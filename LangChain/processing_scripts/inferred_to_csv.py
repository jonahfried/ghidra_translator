import os
import csv
import json

directory = './inferred'

inferred_mappings = []

# Iterate over each folder in the directory
for folder in os.listdir(directory):
  if folder == "gpt4":
    folder_path = os.path.join(directory, folder)
    if os.path.isdir(folder_path):
      print(f"Processing folder: {folder}")
      # Iterate over each file in the folder
      for file in os.listdir(folder_path):
        file_path = os.path.join(folder_path, file)
        file_name = file.split('.')[0]
        if os.path.isfile(file_path):
          print(f"Processing file: {file}")
          # Read the contents of the file
          with open(file_path, 'r') as file:
            file_contents = file.read()
          # Grab the portion of the file contained by curly braces
          start = file_contents.find('{')
          end = file_contents.rfind('}')
          if start == -1 or end == -1:
            print(f"Couldnt find inferred mapping in {file}")
            continue
          inferred_mapping = file_contents[start+1:end]
          # Write each mapping to the CSV as a new row
          for mapping in inferred_mapping.split('\n'):
            placeholder = mapping.split(':')[0].strip()
            if placeholder == '':
              continue
            try:
              inferred = mapping.split(':')[1].strip()
            except:
              inferred = ''
            inferred_mappings.append({
              'llm': folder,
              'function': file_name,
              'placeholder': placeholder,
              'inferred': inferred
            })

# Write the inferred mappings to a CSV file
with open('gpt4_inferred_mappings.csv', 'w', newline='') as file:
  writer = csv.DictWriter(file, fieldnames=['llm', 'function', 'placeholder', 'inferred'])
  writer.writeheader()
  for mapping in inferred_mappings:
    writer.writerow(mapping)