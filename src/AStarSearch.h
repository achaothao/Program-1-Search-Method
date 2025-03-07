// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#ifndef ASTARSEARCH_H
#define ASTARSEARCH_H

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <chrono>
#include "CityFiles.h"

struct AStarNode {
	double actualDistance; // Actual distance traveled so far
	double remainingDistance; // Estimated remaining distance to the goal city
	vector<string> path; // Sequence of cities visited so far

	// Prioritize nodes in the queue
	bool operator>(const AStarNode& other) const {
		return (actualDistance + remainingDistance) > (other.actualDistance + other.remainingDistance);
	}
};

class AStarSearch {
private:
	CityFiles& cityFiles; // Reference to the files

public:
	// Constructor to initialize with the given file
	AStarSearch(CityFiles& cf) : cityFiles(cf) {}

	// Finding the route from the startCity to the destinationCity
	bool search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance);
};

#endif
