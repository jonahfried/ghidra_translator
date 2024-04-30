from langchain_google_vertexai import VertexAI
import os
import glob

model = VertexAI(model_name="gemini-pro")

# Get a list of all .c files in the ./decompiled directory
c_files = glob.glob('./decompiled/*.c')

for c_file in c_files:
    # Read the contents of the .c file
    with open(c_file, 'r') as file:
        file_contents = file.read()

    message = f'''
    You are an expert software engineer. Given some code that was decompiled by Ghidra, let's think step by step and construct a mapping from all the placeholder variable names to descriptive, concise names (in snake case) and types given the context.

    I would like the mapping to be in the following format:
    {{
      <placeholder name> : <inferred name>,
    }}

    Please also explain the reasoning behind each inferred name. Please don't be lazy. Here is the code:

    {file_contents}
    '''

    result = model.invoke(message)

    # Get the base name of the .c file (without the extension)
    base_name = os.path.basename(c_file).split('.')[0]

    # Create a .txt file in the ./inferred directory with the same base name
    with open(f'./inferred/gemini/{base_name}.txt', 'w') as file:
        file.write(result)

    print(f"Inferred mapping written to ./inferred/gemini/{base_name}.txt")