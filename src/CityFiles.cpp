// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#define _USE_MATH_DEFINES 
#include "CityFiles.h"

// Convert degree to radian
double CityFiles::toRadians(double degree) const {
	return degree * M_PI / 180.0;
}

// Calculate distance between 2 cities using Haversine Formula
double CityFiles::distanceFormula(double lat1, double lon1, double lat2, double lon2) const {
	constexpr double earthRadiusKm = 6371.0; // Earth's radius

	// Convert latitude and longitude to radian
	double lat1Rad = toRadians(lat1);
	double lon1Rad = toRadians(lon1);
	double lat2Rad = toRadians(lat2);
	double lon2Rad = toRadians(lon2);

	// Compute the differences in latitude and longitude
	double deltaLat = lat2Rad - lat1Rad;
	double deltaLon = lon2Rad - lon1Rad;

	// Harversine Formula
	double a = sin(deltaLat / 2.0) * sin(deltaLat / 2.0) +
		cos(lat1Rad) * cos(lat2Rad) * sin(deltaLon / 2.0) * sin(deltaLon / 2.0);
	double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));

	// Calculate the distance
	const double distance = earthRadiusKm * c;

	return distance;
}

// Read the coordinates file 
void CityFiles::citiesFile(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << "Error: Unable to open file " << filename << endl;
		return;
	}

	string line, name;
	double latitude, longitude;
	while (getline(file, line)) {
		stringstream ss(line);
		getline(ss, name, ','); // Read city name
		ss >> latitude; // Read city latitude
		ss.ignore(); // Ignore comma
		ss >> longitude; // Read city longitude
		// Store city data
		coordinates[name] = { name, latitude, longitude };
	}

	file.close();
}

// Read the adjacencies file
void CityFiles::adjacenciesFile(const string& filename) {
	ifstream file(filename);
	if (!file) {
		cerr << "Error: Unable to open file!" << filename << endl;
		return;
	}

	string city1, city2;
	while (file >> city1 >> city2) {
		adjacencies[city1].push_back(city2);
		adjacencies[city2].push_back(city1); // Ensure bidirectional connection
	}

	file.close();
}

// Return reference to the map containing coordinates file information
const unordered_map<string, City>& CityFiles::getCoordinates() const {
	return coordinates;
}

// Return reference to the adjacencies list and represents the cities connections as a graph
const unordered_map<string, vector<string>>& CityFiles::getAdjacencies() const {
	return adjacencies;
}
