import csv

file_path = '/Users/sean/Documents/Documents/Files/Programming/CS 263/ghidra_translator/LangChain/gpt4_inferred_mappings.csv'
output_file_path = '/Users/sean/Documents/Documents/Files/Programming/CS 263/ghidra_translator/LangChain/gpt4_cleaned_mappings.csv'

with open(file_path, 'r') as input_file, open(output_file_path, 'w', newline='') as output_file:
  reader = csv.reader(input_file)
  writer = csv.writer(output_file)
  
  for row in reader:
    cleaned_row = [column.replace('"', '') for column in row[:4]]

    # keep only the first word in the last row
    #cleaned_row.append(cleaned_row[-1].split()[0])
    if len(cleaned_row[-1].split()) == 0:
      continue
    first_word = cleaned_row[-1].split()[0]

    cleaned_row = cleaned_row[:-1] + [first_word]

    writer.writerow(cleaned_row)