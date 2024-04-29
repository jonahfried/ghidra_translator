from langchain_anthropic import ChatAnthropic
from langchain_core.prompts import ChatPromptTemplate
import os
import glob
import time

ANTHROPIC_API_KEY="PUT-API-KEY-HERE"

SYSTEM_PROMPT = '''
You are an expert software engineer. Given some code that was decompiled by Ghidra, let's think step by step and construct a mapping from all the placeholder variable names to descriptive, concise names (in snake case) and types given the context.

I would like the mapping to be in the following format:
{
  <placeholder name> : <inferred name>,
}

Please also explain the reasoning behind each inferred name. Please don't be lazy.
'''

chat = ChatAnthropic(temperature=0, api_key=ANTHROPIC_API_KEY, model_name="claude-3-opus-20240229")

prompt = ChatPromptTemplate.from_messages([("system", "{system}"), ("human", "{input}")])

chain = prompt | chat

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
    with open(f'./inferred/claud/{base_name}.txt', 'w') as file:
        file.write(result.content)
    
    print(f"Inferred mapping written to ./inferred/claud/{base_name}.txt")

    # Wait 10 seconds to avoid rate limiting
    time.sleep(13)