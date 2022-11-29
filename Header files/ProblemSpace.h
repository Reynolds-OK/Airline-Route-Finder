#pragma once
#include <string> 
#include <vector>
#include "FileReader.h"

class ProblemSpace {

private:
    std::vector <std::vector<std::string>> problem;
	std::string initCity;
    std::string initCountry;
    std::string destCity;
    std::string destCountry;
    std::string location;

public:
    ProblemSpace();

	/**
	 * display the information of the route
	 */
    void display();

    /**
     * display the starting city
     */
    std::string starting_city();

    /**
     * display the starting country
     */
    std::string starting_country();

    /**
     * display the destination city
     */
    std::string end_city();

    /**
     * display the destination country
     */
    std::string end_country();

};