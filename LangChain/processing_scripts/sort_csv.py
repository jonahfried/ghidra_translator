import csv

# Open the mappings.csv file
with open('../mappings.csv', 'r') as file:
  # Read the CSV data
  csv_data = csv.reader(file)
  
  # Sort the rows by column 1
  sorted_data = sorted(csv_data, key=lambda row: row[1])

  # Group the sorted data by column 1
  grouped_data = {}
  for row in sorted_data:
    key = row[1]
    if key not in grouped_data:
      grouped_data[key] = []
    grouped_data[key].append(row)
  
  # Within each group, sort by column 2
  for key in grouped_data:
    grouped_data[key] = sorted(grouped_data[key], key=lambda row: row[2])
  
  # Flatten the grouped data back into a list
  sorted_data = []
  for key in grouped_data:
    sorted_data.extend(grouped_data[key])
  
  # Write the sorted data to a new CSV file
  with open('sorted_mappings.csv', 'w', newline='') as output_file:
    writer = csv.writer(output_file)
    writer.writerows(sorted_data)