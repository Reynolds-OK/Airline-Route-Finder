#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "FileReader.h"


FileReader::FileReader(std::string loc) {
    file_location = loc;
    readfromfile();
 }

void FileReader::show_result() {
    for (std::vector<std::string> i : item_list) {
        for (std::string j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
 }

std::vector <std::vector<std::string>> FileReader::return_result(){
    return item_list;
 }


void FileReader::split(char str[200]) {
    std::vector<std::string> arr;
    char* substr;

    substr = strtok(str, ",");    // here delimiter is white space

    int i = 0;

    while (substr != NULL)
    {
        arr.push_back(substr);
        i += 1;
        substr = strtok(NULL, ",");
    }

    item_list.push_back(arr);

}


void FileReader::readfromfile() {
    char line[200];

    std::ifstream infile;
    infile.open(file_location);

    while (infile.getline(line, 200)) {
        split(line);
    }

    infile.close();
}