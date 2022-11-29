/**
 * @author Reynolds Okyere Boakye
 * This class provide blueprint for the
 * current city, previous city and trip number
 */
#pragma once
#include <string> 
#include <vector>
#include <memory>
#include "FileReader.h"
#include "FileWriter.h"

class Node {
private:
	std::string state;
	std::shared_ptr<Node> parent;
	int trips;

public:

	Node(std::string city);

	Node(std::string city, std::shared_ptr<Node> upper);

	Node(std::string city, int travels);

	Node(std::string city, std::shared_ptr<Node> upper, int travels);

	/**
	*returns current state
	* @return this.state
	*/
	std::string getState();

	/**
	 * returns current state
	 * @return this.state
	 */
	std::shared_ptr<Node> getParent();

	/**
	 * returns current state
	 * @return this.state
	 */
	int getTrip();


	void toString();


	bool equals(Node another);

	void path_route(std::string start, std::string end);

};