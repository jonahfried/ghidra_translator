import csv

# Open the scores.csv file
with open('scores.csv', 'r') as file:
  # Read the contents of the file
  reader = csv.reader(file)
  rows = list(reader)

# Remove rows with an empty 4th column
rows = [row for row in rows if row[4]]

# Write the updated rows back to the file
with open('scores_2.csv', 'w', newline='') as file:
  writer = csv.writer(file)
  writer.writerows(rows)