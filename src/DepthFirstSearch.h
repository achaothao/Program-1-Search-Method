// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#ifndef DEPTHFIRSTSEARCH_H
#define DEPTHFIRSTSEARCH_H

#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <chrono>
#include "CityFiles.h"

class DepthFirstSearch {
private:
	CityFiles& cityFiles; // Reference to the files

public:
	// Constructor to initialize the search method with the given files
	DepthFirstSearch(CityFiles& cf) : cityFiles(cf) {}
	// Search the route from startCity to destinationCity
	bool search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance);
};

#endif
