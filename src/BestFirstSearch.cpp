// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include "BestFirstSearch.h"

// Finding the path between 2 cities using Best-First Search Method
bool BestFirstSearch::search(const string& startCity, const string& destinationCity,
	vector<string>& path, double& totalDistance) {
	// Retrieve information from the files
	const auto& coordinates = cityFiles.getCoordinates();
	const auto& adjacencies = cityFiles.getAdjacencies();

	// Queue for Best-First Search Method and sorted by heuristic distance
	priority_queue<pair<double, vector<string>>,
		vector<pair<double, vector<string>>>, Compare> queue;
	set<string> visited;
	queue.push({ 0, {startCity} }); // Initialize the queue with startCity

	auto startTime = chrono::high_resolution_clock::now(); // Record startTime

	while (!queue.empty()) {
		// Get city with the lowest heuristic distance
		auto current = queue.top();
		queue.pop();
		vector<string> currentPath = current.second;
		string currentCity = currentPath.back();

		// Skip cities that already visited
		if (visited.find(currentCity) != visited.end()) continue;
		visited.insert(currentCity);

		// Expand neighbors of the current city
		for (const string& neighbor : adjacencies.at(currentCity)) {
			if (visited.find(neighbor) == visited.end()) {
				vector<string> newPath = currentPath;
				newPath.push_back(neighbor);

				// Calculate the heuristic distance
				double remainingDistance = cityFiles.distanceFormula(
					coordinates.at(neighbor).latitude, coordinates.at(neighbor).longitude,
					coordinates.at(destinationCity).latitude, coordinates.at(destinationCity).longitude
				);

				// Push the new route into the queue
				queue.push({ remainingDistance, newPath });
			}
		}

		// Calculate the distance using haversine formula if we reach the destinationCity
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

			//Display the route found, time, and total distance
			cout << "Route found using Best-First Search:\n";
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
