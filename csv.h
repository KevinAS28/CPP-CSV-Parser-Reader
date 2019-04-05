#ifndef __csv
#define __csv true
#include <string> //cpp standard library
#include <vector> //cpp standard library
#include "strtool.h" //find this on my github: https://github.com/KevinAS28

typedef std::vector<std::string> vstr; //vector string
typedef std::vector<vstr> vvstr; //vector vector string
class CSV{
public:
	vvstr csv_data = vvstr();
	FILE * csv_file;
	std::string column_splitter = ",";
	std::string row_splitter = "\n";
	CSV(std::string data, std::string row_splitter="\n", std::string column_splitter = ","){
		vstr line = split_str_s(data, row_splitter);
		this->column_splitter = column_splitter;
		for (std::string i : line){
			vstr dat = split_str_s(i, column_splitter);
			this->csv_data.push_back(dat);
		}
	}
	CSV(FILE * the_file, std::string row_splitter="\n", std::string column_splitter = ","){
		std::string data = "";
		while (true){
			int d = getc(the_file);
			if (d==EOF)break;
			data+=d;
		}
		CSV csv = CSV(data, row_splitter, column_splitter);
		this->csv_data = csv.csv_data;
	}
	vstr& operator[](int index){
		return this->csv_data[index];
	}
	std::string get_string(){
		std::string to_return = "";
		for (vstr v: this->csv_data){
			for (std::string s:v){
				to_return+=s;
				to_return+=this->column_splitter;
			}
			to_return+=this->row_splitter;
		}
		return to_return;
	}
};

#endif