/**
 * @author Reynolds Okyere Boakye
 * This class provide blueprint for the
 * current city, previous city and trip number
 */
#include <iostream>
#include "Node.h"

Node::Node(std::string city) {
	state = city;
	parent = NULL;
	trips = 0;
}

Node::Node(std::string city, std::shared_ptr<Node> upper) {
	state = city;
	parent = upper;
	trips = 0;
}

Node::Node(std::string city, int travels) {
	state = city;
	parent = NULL;
	trips = travels;
}

Node::Node(std::string city, std::shared_ptr<Node> upper, int travels) {
	state = city;
	parent = upper;
	trips = travels;
}

/**
*returns current state
* @return this.state
*/
std::string Node::getState() { return state; }

/**
	* returns current state
	* @return this.state
	*/
std::shared_ptr<Node> Node::getParent() { return parent; }

/**
	* returns current state
	* @return this.state
	*/
int Node::getTrip() { return trips; }


void Node::toString() {
	std::cout << "Airport Code: " << state << ". From: " << parent->getState() << ". Trip: " << trips << std::endl;
}


bool Node::equals(Node another) {
	if (state == another.getState()) {
		return true;
	}
	return false;
}

void Node::path_route(std::string start, std::string end) {
	std::string direction;
	std::shared_ptr<Node> current(new Node(this->getState(), this->getParent(), this->getTrip()));
	std::string temp;
	int total_flights = current->getTrip();
	int count = total_flights;
	int additional_stops = 0;

	FileReader file_routes("../../routes.csv");
	std::vector<std::vector<std::string>> routes = file_routes.return_result();
	std::string airline;
	std::string stops;

	while (current->getParent()->getState() != "END") {
		for (std::vector<std::string> each : routes) {
			if ((each.at(4) == current->getState()) && (each.at(2) == current->getParent()->getState())) {
				airline = each.at(0);
				stops = each.at(6);
				break;
			}
		}

		//write the required sentence for a route from one city to another with an airline
		temp = std::to_string(count) + ". " + airline + " from " + current->getParent()->getState() + " to " + current->getState() + " " + stops + " stops.\n";
		direction = temp + direction;

		additional_stops += stoi(stops);

		current = current->getParent();
		count -= 1;
	}

	direction = "-------------------------------------------\n" + direction;
	direction = "\nRoutes to use to get to your destination\n" + direction;
	direction += "\nTotal flights: " + std::to_string(total_flights) + "\n";
	direction += "Total additional stops: " + std::to_string(additional_stops);

	// write to file
	FileWriter write(start + "-" + end);
	bool result = write.exportOut(direction);

	if (result) {
		std::cout << "Done exporting";
	}
	else {
		std::cout << "Could not export information";
	}
	std::cout << std::endl;
	std::cout << direction;
}
