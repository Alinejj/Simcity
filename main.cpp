#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Cell.h"
#include "City.h"
#include "residential.h"

using namespace std;

City city;


int main() {
    string filename;
    cout << "Enter the filename for the configuration: ";
    getline(cin, filename);
    
    // Initialize city with configuration file data
    city.ReadInAndInitialize(filename);

    //set all adjacency info for the cell
    city.setAdjecencyForCells();

    // Access refresh rate and time limit from the city object
    int refreshRate = city.refreshRate;
    int timeLimit = city.timeLimit;

    city.PrintCity();  // Initial display of city layout

    int updateCount = 0;

    // Main loop, runs until the time limit is reached
    for (int i = 0; i < timeLimit; i += refreshRate) {
        updateCount++;  // Track the current update cycle

        // Update all city cells
        city.updateCells();

         // Calculate total available workers in residential areas
        //int totalAvailableWorkers = city.updateResidentialWorkers();
	int totalAvailableWorkers = city.getAvailableWorkers();

        

        // Output at the specified refresh rate
        if (updateCount % refreshRate == 0) {
            cout << "\nSimulation update " << updateCount << ":\n";
            cout << "Total available workers: " << totalAvailableWorkers << endl;
            city.PrintCity();
            cout << "\nPress Enter to continue to the next refresh...";
            cin.get(); // Wait for user input
        }
    }

    cout << "\nSimulation complete. No further updates available or time limit reached.\n";
    return 0;
}