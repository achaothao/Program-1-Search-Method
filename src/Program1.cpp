// A Chao Thao
// Program 1: Search Method
// 03/07/2025

#include <iostream>
#include "CityFiles.h"
#include "BreadthFirstSearch.h"
#include "DepthFirstSearch.h"
#include "IterativeDeepeningSearch.h"
#include "BestFirstSearch.h"
#include "AStarSearch.h"

using namespace std;

// Prompt the user with all 5 different search methods option
void userOption() {
    cout << "\nSearch Methods:\n"
         << "1. Breadth-First Search\n"
         << "2. Depth-First Search\n"
         << "3. Iterative Deepening DFS\n"
         << "4. Best-First Search\n"
         << "5. A* Search\n"
         << "6. Quit\n";
}

int main() {
    vector<string> path;
    double totalDistance = 0;
    int option;
    string startCity, destinationCity;
    bool found = false;

    // Load coordinates and adjacencies files
    CityFiles cityFiles;
    cityFiles.citiesFile("coordinates.csv");
    cityFiles.adjacenciesFile("Adjacencies.txt");

    // Retrieve information from the files
    const auto& coordinates = cityFiles.getCoordinates();
    const auto& adjacencies = cityFiles.getAdjacencies();

    // Get user input
    cout << "Enter starting city: ";
    cin >> startCity;
    cout << "Enter destination city: ";
    cin >> destinationCity;

    // Check to see if both cities in the database
    while (coordinates.find(startCity) == coordinates.end() || coordinates.find(destinationCity) == coordinates.end()) {
        cerr << "\nError: One or both cities not found in database.\n" 
             << "Please try again...\n\n";

        cout << "Enter starting city: ";
        cin >> startCity;
        cout << "Enter destination city: ";
        cin >> destinationCity;
    }

    userOption();

    cout << "Select a Search Mehtod (1-5) or 6 to Quit: ";
    cin >> option;

    // Displaying route, time, and total distance between 2 cities base on
    // the search method the user choose.
    while (option < 7) {
        cout << endl;
        if (option == 1) {
            BreadthFirstSearch breadthFirstSearch(cityFiles);
            found = breadthFirstSearch.search(startCity, destinationCity, path, totalDistance);
        }
        else if (option == 2) {
            DepthFirstSearch depthFirstSearch(cityFiles);
            found = depthFirstSearch.search(startCity, destinationCity, path, totalDistance);
        }
        else if (option == 3) {
            IterativeDeepeningSearch iterativeDeepeningSearch(cityFiles);
            found = iterativeDeepeningSearch.search(startCity, destinationCity, path, totalDistance);
        }
        else if (option == 4) {
            BestFirstSearch bestFirstSearch(cityFiles);
            found = bestFirstSearch.search(startCity, destinationCity, path, totalDistance);
        }
        else if (option == 5) {
            AStarSearch astarSearch(cityFiles);
            found = astarSearch.search(startCity, destinationCity, path, totalDistance);
        }
        else if (option == 6) {
            cout << "\nGoodbye!\n";
            break;
        }
        else {
            cout << "Invalid option. Please try again...\n";
        }

        userOption();

        cout << "Select a Search Mehtod (1-5) or 6 to Quit: ";
        cin >> option;
    }

    return 0;
}
