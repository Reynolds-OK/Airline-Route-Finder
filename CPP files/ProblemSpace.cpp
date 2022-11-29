#include <iostream>
#include "ProblemSpace.h"


ProblemSpace::ProblemSpace() {
	location = "../../Accra-Rankin Inlet.txt";
	FileReader space(location);

	problem = space.return_result();

	initCity = problem.at(0).at(0);
	initCountry = problem.at(0).at(1);
	destCity = problem.at(1).at(0);
	destCountry = problem.at(1).at(1);
}

/**
	* display the information of the route
	*/
void ProblemSpace::display() {
	std::cout << "Starting city: " << initCity << ". Country: " << initCountry << std::endl;
	std::cout << "Destination city: " << destCity << ". Country: " << destCountry << std::endl;
}

/**
	* display the starting city
	*/
std::string ProblemSpace::starting_city() { return initCity; }

/**
	* display the starting country
	*/
std::string ProblemSpace::starting_country() { return initCountry; }

/**
	* display the destination city
	*/
std::string ProblemSpace::end_city() { return destCity; }

/**
	* display the destination country
	*/
std::string ProblemSpace::end_country() { return destCountry; }
