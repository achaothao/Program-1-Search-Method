// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include "BreadthFirstSearch.h"

// Find a path between two cities
bool BreadthFirstSearch::search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance) {
	// Retrieve information from the files
	const auto& coordinates = cityFiles.getCoordinates();
	const auto& adjacencies = cityFiles.getAdjacencies();

	// Stores the paths as vectors
	queue<vector<string>> queue;
	set<string> visited;
	queue.push({ startCity });
	visited.insert(startCity);

	auto startTime = chrono::high_resolution_clock::now(); // Record startTime

	while (!queue.empty()) {
		// Get the first path in the queue
		vector<string> currentPath = queue.front();
		queue.pop();
		string currentCity = currentPath.back();

		// Expand neighbors of the current city
		for (const string& neighbor : adjacencies.at(currentCity)) {
			if (visited.find(neighbor) == visited.end()) {
				vector<string> newPath = currentPath;
				newPath.push_back(neighbor);

				queue.push(newPath); // Add new path to queue
				visited.insert(neighbor); // Mark neighbor as visited
			}
		}

		// If destinationCity is found, calculate the distance using haversine formula
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

			// Display the route, time, and distance
			cout << "Route found using Breadth-First Search:\n";
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
