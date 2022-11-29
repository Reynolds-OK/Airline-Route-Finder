#include "FileWriter.h"



FileWriter::FileWriter(std::string name) {
	file_name = name + "_output.txt";
}


bool FileWriter::exportOut(std::string info) {
	std::ofstream outfile("../../" + file_name);

	outfile << info << std::endl;

	outfile.close();

	return true;
}
