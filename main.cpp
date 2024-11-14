#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "Cell.h"
#include "City.h"
#include "residential.h"

using namespace std;

City city;

int main() {

    string filename;
    int startRow;
    char choice;

    // Get the filename for the configuration
    cout << "Enter the filename for the configuration: ";
    getline(cin, filename);

    // Initialize city with configuration file data
    city.ReadInAndInitialize(filename);

    // Set all adjacency info for the cell
    city.setAdjecencyForCells();

    // Access refresh rate and time limit from the city object
    int refreshRate = city.refreshRate;
    int timeLimit = city.timeLimit;

    // Initial display of city layout
    city.PrintCity();

    // Ask the user if they want to grow a region (this is outside the main loop)
    cout << "Do you want to grow a region? (y/n): ";
    cin >> choice;

    // Ask for startRow if they want to grow the region
    if (choice == 'y' || choice == 'Y') {
        cout << "Enter the start row number (0 to " << city.cityGrid.size() - 1 << "): ";
        cin >> startRow;

        // Validate the row number
        if (startRow < 0 || startRow >= city.cityGrid.size()) {
            cout << "Invalid row number. Exiting program." << endl;
            return 1;
        }
    }

    int updateCount = 0;

    // Main loop, runs until the time limit is reached
    for (int i = 0; i < timeLimit; i += refreshRate) {
        updateCount++;  // Track the current update cycle

        // Update all city cells for the whole city
        city.updateCells();

        // Calculate total available workers in residential areas
        int totalAvailableWorkers = city.getAvailableWorkers();
        int totalAvailableGoods = city.getAvailableGoods();

        // Output at the specified refresh rate
        if (updateCount % refreshRate == 0) {
            cout << "\nSimulation update " << updateCount << ":\n";
            cout << "Total available workers: " << totalAvailableWorkers << endl;
            cout << "Total available goods: " << totalAvailableGoods << endl;

            if (choice == 'y' || choice == 'Y') {
                // Display from the startRow to the end of the map
                city.PrintCityRange(startRow, city.cityGrid.size() - 1, 0, city.cityGrid[0].size() - 1);
            } else {
                // If the user does not want to grow a region, display the entire grid
                city.PrintCity();
            }

            cout << "\nPress Enter to continue to the next refresh...";
            cin.ignore(); // To clear the input buffer
            cin.get(); // Wait for user input
        }
    }

    cout << "\nSimulation complete. No further updates available or time limit reached.\n";
    return 0;
}