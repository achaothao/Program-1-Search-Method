// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#ifndef BESTFIRSTSEARCH_H
#define BESTFIRSTSEARCH_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <chrono>
#include "CityFiles.h"

// This struct will defines the comparator for the queue by priotitizes the city with 
// the smallest heuristic distance.
struct Compare {
	bool operator()(const pair<double, vector<string>>& a,
		const pair<double, vector<string>>& b) {
		return a.first > b.first;
	}
};

// 
class BestFirstSearch {
private:
	CityFiles& cityFiles; // Reference to the files

public:
	// Constructor to initialize with the given file
	BestFirstSearch(CityFiles& cf) : cityFiles(cf) {}

	// Search a path from startCity to destinationCity
	bool search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance);
};

#endif
