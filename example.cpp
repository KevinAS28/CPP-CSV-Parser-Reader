#include <iostream>
#include "csv.h"

void read_from_file(){
	//with file stream
	FILE * csv_stream = fopen("house.csv", "r");
	CSV csv = CSV(csv_stream);
	std::cout << csv[1][0] << "\n";
}

void from_string(){
	//with file stream
	FILE * csv_stream = fopen("house.csv", "r");

	//read the file
	std::string data = "";
	int b = 0;
	while (true){
		b = getc(csv_stream);
		if (b==EOF) break;
		data+=(char)b;
	}

	//print out the data
	//std::cout << data;

	CSV csv = CSV(data);
	std::cout << csv[1][0] << "\n";	
}

int main(){	
 from_string();
 read_from_file();
	return 0;
}