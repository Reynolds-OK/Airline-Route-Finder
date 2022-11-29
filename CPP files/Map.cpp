/**
 * @author Reynolds Okyere Boakye
 * This class creates an inteconnected map for the cities
 */

#include "Map.h"

Map::Map() {
	routes = "../../routes.csv";
	std::vector<std::string> result;

	FileReader new_map(routes);
	std::vector <std::vector<std::string>> routes = new_map.return_result();

	for (std::vector<std::string> each : routes) {
		std::vector<std::string> result;
		//checks whether city already exists else create an empty 
			// If key not found in map iterator
			// to end is returned
		if (airline_map.find(each.at(2)) != airline_map.end())
			result = airline_map[each.at(2)];

		if (count(result.begin(), result.end(), each.at(4)))
			continue;

		result.push_back(each.at(4));

		airline_map[each.at(2)] = result;
	}
}

std::unordered_map<std::string, std::vector<std::string>> Map::return_map() {
	return airline_map;
}