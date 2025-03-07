// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include "AStarSearch.h"

// Finding the path between 2 cities using A* Search Method
bool AStarSearch::search(const string& startCity, const string& destinationCity, vector<string>& path, double& totalDistance) {
	// Retrieve information from the files
	const auto& coordinates = cityFiles.getCoordinates();
	const auto& adjacencies = cityFiles.getAdjacencies();

	// Stored nodes using queue
	priority_queue<AStarNode, vector<AStarNode>, greater<AStarNode>> queue;
	set<string> visited;
	// Initialize the queue with startCity
	queue.push({ 0, cityFiles.distanceFormula(
				coordinates.at(startCity).latitude, coordinates.at(startCity).longitude,
				coordinates.at(destinationCity).latitude, coordinates.at(destinationCity).longitude), {startCity} });

	// Start recording the time
	auto startTime = chrono::high_resolution_clock::now();

	// Run this while loop if the queue is not empty
	while (!queue.empty()) {
		// Retrieve the node with the lowest total cost distance by adding the actualDistance + remainingDistance
		AStarNode current = queue.top();
		queue.pop();
		string currentCity = current.path.back();

		// Skip the cities that already been visited
		if (visited.find(currentCity) != visited.end()) continue;
		visited.insert(currentCity);

		// Calculate the actual distance traveled and the remaining distance and push it into the queue
		for (const string& neighbor : adjacencies.at(currentCity)) {
			if (visited.find(neighbor) == visited.end()) {
				vector<string> newPath = current.path;
				newPath.push_back(neighbor);
				double newCost = current.actualDistance + cityFiles.distanceFormula(
					coordinates.at(currentCity).latitude, coordinates.at(currentCity).longitude,
					coordinates.at(neighbor).latitude, coordinates.at(neighbor).longitude
				);
				double remainingDistance = cityFiles.distanceFormula(
					coordinates.at(neighbor).latitude, coordinates.at(neighbor).longitude,
					coordinates.at(destinationCity).latitude, coordinates.at(destinationCity).longitude
				);
				queue.push({ newCost, remainingDistance, newPath });
			}
		}

		// If we reach destinationCity, display the route, time, and distance
		if (currentCity == destinationCity) {
			path = current.path;
			totalDistance = current.actualDistance;
			auto endTime = chrono::high_resolution_clock::now();
			chrono::duration<double> elapsed = endTime - startTime;

			cout << "Route found using A* Search:\n";
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
