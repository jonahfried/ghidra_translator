from varclr.models.model import Encoder
import csv

model = Encoder.from_pretrained("varclr-codebert")

def is_valid(row):
  return len(row) >= 5

print("model loaded...")

# Open the mappings.csv file
with open('/Users/sean/Documents/Documents/Files/Programming/CS 263/ghidra_translator/LangChain/mappings.csv', 'r') as input_file, open('scores.csv', 'w', newline='') as output_file:
  # Read the CSV data
  csv_data = csv.reader(input_file)
  writer = csv.writer(output_file)
  
  for row in csv_data:
    if is_valid(row):
      inferred, ground = row[3], row[4]
      score = model.score(inferred, ground)
      writer.writerow(row + [score])

      # every 10 rows, print the progress
      if csv_data.line_num % 10 == 0:
        print(f"{csv_data.line_num} rows processed...")