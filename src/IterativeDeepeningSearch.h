// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#ifndef ITERATIVEDEEPENINGSEARCH_H
#define ITERATIVEDEEPENINGSEARCH_H

#include <iostream>
#include <vector>
#include <set>
#include <chrono>
#include "CityFiles.h"

class IterativeDeepeningSearch {
private:
	CityFiles& cityFiles; // Reference to the files
	// Performs a dept limited recursive DFS 
	bool dfsRecursive(const string& current, const string& goal, set<string>& visited,
		vector<string>& path, int depth, int maxDepth);

public:
	// Constructor to initialize the search method with the given files
	IterativeDeepeningSearch(CityFiles& cf) : cityFiles(cf) {}
	// Find the route from startCity to destinationCity
	bool search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance);
};

#endif
