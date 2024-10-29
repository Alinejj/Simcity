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

    // Access refresh rate and time limit from the city object
    int refreshRate = city.refreshRate;
    int timeLimit = city.timeLimit;

    city.PrintCity();  // Initial display of city layout

    int updateCount = 0;

    // Main loop, runs until the time limit is reached
    for (int i = 0; i < timeLimit; i += refreshRate) {
        updateCount++;  // Track the current update cycle

        // Update residential cells
        city.updateResidentialCells();

        // Calculate total available workers based on population
        int totalAvailableWorkers = 0;

        // Iterate through city grid to count available workers in residential cells
        for (const auto& row : city.cityGrid) {
            for (const auto& cell : row) {
                // Check if the cell is residential
                if (cell->getCellType() == "R") {
                    // Directly access the population and calculate available workers
                    int population = cell->getCellPopulation();
                    // For simplicity, let's assume each population unit represents one worker
                    totalAvailableWorkers += population;  // Adjust this logic based on your worker calculation
                }
            }
        }

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