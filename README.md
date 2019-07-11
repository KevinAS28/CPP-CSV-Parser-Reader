# C++ CSV Parser
### feel free with this code :)

## read csv from string or file, and parse it to vector or map.

## How to use it?

reading from string using vector parser
`CSV mycsv0 = CSV(csv_string); //note that vector parser is the default

vstr first_row = mycsv0.vector_data[0]; //vstr = std::vector<std::string>

std::string data = first_row[0];`


reading from string using map parser. map parser will treat the first row as the column names.
use the column names to indexing your data in each row.
`CSV mycsv1 = CSV(csv_string, "m") // "m" stands for map. use "v" for vector

vstr column_names = mycsv1.column_names; //the column names 

mapss first_row = mycsv1.map_data[0]; //

std::string data = first_row[column_names[0]];`


Kevin AS
