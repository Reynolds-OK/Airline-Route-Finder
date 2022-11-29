//#pragma once
#pragma once
#include <fstream>
#include <string> 
#include <vector>
#include <regex>

class FileReader {

public:
    FileReader(std::string loc);

    void show_result();

    std::vector <std::vector<std::string>> return_result();


private:
    std::string file_location;

    std::vector <std::vector<std::string>> item_list;

    void split(char str[200]);

    void readfromfile();
};