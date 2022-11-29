#pragma once
#include <queue>
#include <unordered_set>
#include "ProblemSpace.h"
#include "FileReader.h"
#include "Node.h"
#include "Map.h"



class Computation {

private:
    std::string airports_dir;

public:
    Computation();

    bool isContains(std::queue<std::shared_ptr<Node>>, std::shared_ptr<Node>);

    bool VecContains(std::vector<std::string> end_cities, std::string state);

    bool determine();
};