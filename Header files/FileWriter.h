#pragma once
#include <fstream>
#include <string> 


class FileWriter {

private:
	std::string file_name;

public:
	FileWriter(std::string name);

	bool exportOut(std::string info);
};