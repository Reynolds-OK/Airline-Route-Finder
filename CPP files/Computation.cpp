#include <iostream>
#include "Computation.h"

Computation::Computation() { airports_dir = "../../airports.csv"; }

bool Computation::isContains(std::queue<std::shared_ptr<Node>> frontier, std::shared_ptr<Node> child) {
    while (!frontier.empty()) {
        if (frontier.front()->getState() == child->getState())
            return true;
        frontier.pop();
    }
    return false;
}

bool Computation::VecContains(std::vector<std::string> end_cities, std::string state) {
    for (std::string city : end_cities) {
        if (city == state) { return true; }
    }
    return false;
}

bool Computation::determine() {

    ProblemSpace start_to_end;

    Map problem_map;
    std::unordered_map<std::string, std::vector<std::string>> mmap = problem_map.return_map();

    bool found_start = false;
    bool found_end = false;

    std::string start_city_code;
    std::vector <std::string> end_city_codes;

    std::queue<std::shared_ptr<Node>> frontier;


    FileReader airports(airports_dir);
    std::vector <std::vector<std::string>> all_airports = airports.return_result();

    std::shared_ptr<Node> end(new Node("END"));

    if (start_to_end.starting_city() == start_to_end.end_city()
        && start_to_end.starting_country() == start_to_end.end_country()) {
        std::cout << "You are already in that city";
        return true;
    }


    // checks for all airports in a particular starting city
    // confirms if the destination city has an airport
    for (std::vector <std::string> airport : all_airports) {
        if (airport.at(2) == start_to_end.starting_city()
            && airport.at(3) == start_to_end.starting_country()
            && (airport.at(4) != "\\N")) {

            start_city_code = airport.at(4);
            found_start = true;

            std::shared_ptr<Node> city(new Node(start_city_code, end));
            frontier.push(city);
        }

        if (airport.at(2) == start_to_end.end_city()
            && airport.at(3) == start_to_end.end_country()
            && (airport.at(4) != "\\N")) {
            end_city_codes.push_back(airport.at(4));
            found_end = true;
        }
    }

    // possibly no airport in the specified city
    if (!found_start || !found_end) {
        std::cout << "Starting Airport or Ending Airport Route not found";
        return false;
    }

    std::cout << "Starting Route Search from " << start_to_end.starting_city() << std::endl;
    std::cout << "Ending at " << start_to_end.end_city() << std::endl;

    std::unordered_set<std::string> explored;


    while (!frontier.empty()) {
        std::shared_ptr<Node> current = frontier.front();
        frontier.pop();
        //std::cout << "Popped node " << current->getState() << std::endl;

        explored.insert(current->getState());

        // acquire connected cities to current cities
        std::vector <std::string> connected = mmap[current->getState()];

        if (connected.size() == 0)
            continue;

        for (std::string next : connected) {
            std::shared_ptr<Node> child(new Node(next, current, current->getTrip() + 1));

            if ((explored.find(child->getState()) == explored.end())
                && !isContains(frontier, child)) {

                if (VecContains(end_city_codes, child->getState())) {
                    std::cout << std::endl;
                    std::cout << "Found airport (" << child->getState() << ") in " << start_to_end.end_city() << std::endl;

                    child->path_route(start_to_end.starting_city(), start_to_end.end_city());

                    return true;
                }
                frontier.push(child);
            }
        }
    }

    std::cout << "Didn't find airport city";
    return false;
}
