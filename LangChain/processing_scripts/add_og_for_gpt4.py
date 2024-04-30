import csv

def find_ground(current_row, rows):
  function = current_row[1]
  placeholder = current_row[2]

  for r in rows:
    if r[1] == function and r[2] == placeholder:
      if len(r) > 4:
        return r[4]
  return None

gpt4_mappings = '/Users/sean/Documents/Documents/Files/Programming/CS 263/ghidra_translator/LangChain/gpt4_cleaned_mappings.csv'
other_mappings = '/Users/sean/Documents/Documents/Files/Programming/CS 263/ghidra_translator/LangChain/mappings.csv'
output_file_path = '/Users/sean/Documents/Documents/Files/Programming/CS 263/ghidra_translator/LangChain/gpt4_mappings_with_ground.csv'

with open(gpt4_mappings, 'r') as gpt4_mappings_file, open(output_file_path, 'w', newline='') as output_file, open(other_mappings, 'r') as other_mappings_file:
  gpt4_mappings_reader = csv.reader(gpt4_mappings_file)
  other_mappings_reader = csv.reader(other_mappings_file)
  writer = csv.writer(output_file)
  other_mappings_rows = list(other_mappings_reader)[1:]

  print(other_mappings_rows[:3])
  
  for row in gpt4_mappings_reader:
    llm = row[0]
    ground = find_ground(row, other_mappings_rows)
    if ground:
      row = row[:-1] + [ground]
      writer.writerow(row)
    else:
      writer.writerow(row)