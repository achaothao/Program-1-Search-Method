// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include "DepthFirstSearch.h"

// Find route between 2 cities
bool DepthFirstSearch::search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance) {
	// Retrieve information from the files
	const auto& coordinates = cityFiles.getCoordinates();
	const auto& adjacencies = cityFiles.getAdjacencies();

	// Stores routes as vectors
	stack<vector<string>> stack;
	set<string> visited;
	stack.push({ startCity });
	visited.insert(startCity);

	auto startTime = chrono::high_resolution_clock::now();

	while (!stack.empty()) {
		// LIFO, get the last path added to the stack
		vector<string> currentPath = stack.top();
		stack.pop();
		string currentCity = currentPath.back();

		// Expand neigbors of the current city
		for (const string& neighbor : adjacencies.at(currentCity)) {
			if (visited.find(neighbor) == visited.end()) {
				vector<string> newPath = currentPath;
				newPath.push_back(neighbor);

				stack.push(newPath); // Push new route onto the stack
				visited.insert(neighbor); // Mark neigbor as visited
			}
		}

		// If destinationCity is found, calculate the distance
		if (currentCity == destinationCity) {
			path = currentPath;
			totalDistance = 0;
			for (int i = 1; i < path.size(); ++i) {
				totalDistance += cityFiles.distanceFormula(
					coordinates.at(path[i - 1]).latitude, coordinates.at(path[i - 1]).longitude,
					coordinates.at(path[i]).latitude, coordinates.at(path[i]).longitude
				);
			}

			auto endTime = chrono::high_resolution_clock::now();
			chrono::duration<double> elapsed = endTime - startTime;

			// Display the route found, time taken, and total distance 
			cout << "Route found using Depth-First Search:\n";
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
