#ifndef CITYFILES_H
#define CITYFILES_H

// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

// Contains cities name and its coordinates
struct City {
	string cityName;
	double latitude, longitude;
};

class CityFiles {
private:
	unordered_map<string, City> coordinates; // Store the coordinates file
	unordered_map<string, vector<string>> adjacencies; // Store the adjacencies file

	double toRadians(double degree) const; // Convert degrees to radians

public:
	void citiesFile(const string& filename); // Load coordinates file
	void adjacenciesFile(const string& filename); // Load adjacencies file
	// Calculate the distance between two cities using Haversine formula
	double distanceFormula(double lat1, double lon1, double lat2, double lon2) const;

	// Access coordinates file
	const unordered_map<string, City>& getCoordinates() const;
	// Access adjacencies file
	const unordered_map<string, vector<string>>& getAdjacencies() const;
};

#endif
