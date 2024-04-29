from langchain_openai import ChatOpenAI
from langchain_core.prompts import ChatPromptTemplate
from langchain_core.output_parsers import StrOutputParser
import os
import glob

LANGCHAIN_TRACING_V2="true"
LANGCHAIN_API_KEY="PUT-API-KEY-HERE"
OPENAI_API_KEY="PUT-API-KEY-HERE"

SYSTEM_PROMPT = '''
You are an expert software engineer. Given some code that was decompiled by Ghidra, let's think step by step and construct a mapping from all the placeholder variable names to descriptive, concise names (in snake case) and types given the context.

I would like the mapping to be in the following format:
{
  <placeholder name> : <inferred name>,
}

Please also explain the reasoning behind each inferred name. Please don't be lazy.
'''

gpt4 = ChatOpenAI()

prompt = ChatPromptTemplate.from_messages([
    ("system", "{system}"),
    ("user", "{input}")
])

output_parser = StrOutputParser()

chain = prompt | gpt4 | output_parser

# Get a list of all .c files in the ./decompiled directory
c_files = glob.glob('./decompiled/*.c')

for c_file in c_files:
    # Read the contents of the .c file
    with open(c_file, 'r') as file:
        file_contents = file.read()

    # Feed the contents to a chain invocation
    result = chain.invoke({
        "system": SYSTEM_PROMPT,
        "input": file_contents
    })

    # Get the base name of the .c file (without the extension)
    base_name = os.path.basename(c_file).split('.')[0]

    # Create a .txt file in the ./inferred directory with the same base name
    with open(f'./inferred/gpt4/{base_name}.txt', 'w') as file:
        file.write(result)
    
    print(f"Inferred mapping written to ./inferred/gpt4/{base_name}.txt")
