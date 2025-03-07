// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#ifndef BREADTHFIRSTSEARCH_H
#define BREADTHFIRSTSEARCH_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <chrono>
#include "CityFiles.h"

class BreadthFirstSearch {
private:
	CityFiles& cityFiles; // Reference to the files

public:
	// Constructor to initialize the search method with the given files
	BreadthFirstSearch(CityFiles& cf) : cityFiles(cf) {}

	// Find the path from the startCity to destinationCity
	bool search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance);
};

#endif
