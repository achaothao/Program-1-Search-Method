// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include "IterativeDeepeningSearch.h"

// Explores path, if destinationCity is reach within the dept limit, return true
// if the depth limit is exceeded, backtracks
bool IterativeDeepeningSearch::dfsRecursive(const string& current, const string& goal, set<string>& visited,
	vector<string>& path, int depth, int maxDepth) {

	// Stop search if depth limit is exceeded
	if (depth > maxDepth) return false;
	visited.insert(current);
	path.push_back(current);

	if (current == goal) return true; // Return true if we reach the goal

	const auto& adjacencies = cityFiles.getAdjacencies(); // Retrieve adjacencies file

	// Explore neighbors recursively within the path limit
	for (const string& neighbor : adjacencies.at(current)) {
		if (visited.find(neighbor) == visited.end()) {
			if (dfsRecursive(neighbor, goal, visited, path, depth + 1, maxDepth)) return true;
		}
	}

	path.pop_back();
	return false;
}

bool IterativeDeepeningSearch::search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance) {
	// Retrieve coordinates file
	const auto& cities = cityFiles.getCoordinates();

	auto startTime = chrono::high_resolution_clock::now();

	for (int maxDepth = 0; maxDepth < 100; ++maxDepth) {
		set<string> visited; // Reset visited cities for each dept iteration
		path.clear(); // Reset the path

		// Call depth limited DFS function
		if (dfsRecursive(startCity, destinationCity, visited, path, 0, maxDepth)) {
			totalDistance = 0;
			for (int i = 1; i < path.size(); ++i) {
				totalDistance += cityFiles.distanceFormula(
					cities.at(path[i - 1]).latitude, cities.at(path[i - 1]).longitude,
					cities.at(path[i]).latitude, cities.at(path[i]).longitude
				);
			}

			auto endTime = chrono::high_resolution_clock::now();
			chrono::duration<double> elapsed = endTime - startTime;

			// Display route found, time, and distance
			cout << "Route found using Iterative Deepening DFS:\n";
			for (const string& city : path) {
				cout << city << " -> ";
			}
			cout << "End\n";
			cout << "Time taken: " << elapsed.count() << " seconds\n"
				<< "Total distance: " << totalDistance << " km\n";

			return true;
		}
	}

	return false;
}
