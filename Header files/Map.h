/**
 * @author Reynolds Okyere Boakye
 * This class creates an inteconnected map for the cities
 */
#include <unordered_map>
#include "FileReader.h"

class Map {
private:
	std::unordered_map<std::string, std::vector<std::string>> airline_map;
	std::string routes;

public:
	Map();

	std::unordered_map<std::string, std::vector<std::string>> return_map();
};