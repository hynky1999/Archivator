#include "SaveUtilities.h"
#include <chrono>
#include <fstream>
#include <iostream>

void SaveString(std::ofstream & ofs, const std::string & str){
	std::string::size_type str_size = str.size();
	ofs.write(reinterpret_cast<char*>(&str_size), sizeof(str_size));
	const char* str_raw = str.c_str();
	ofs.write(str_raw, sizeof(char) * str_size);
	if(!ofs.good())
		throw fs::filesystem_error(FILE_WRITE_ERR, std::make_error_code(std::errc::io_error));
}

void LoadString(std::ifstream & ifs, std::string & str){
	std::string::size_type size;
	ifs.read(reinterpret_cast<char*>(&size), sizeof(size));

	char * str_raw = new char [size + 1];
	if(!ifs.good())
		throw fs::filesystem_error(FILE_WRITE_ERR, std::make_error_code(std::errc::io_error));
	ifs.read(str_raw, sizeof(char) * size);
	str_raw[size] = '\0';
	str.resize(size);
	str = str_raw;	
	delete [] str_raw;
}

