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
    int startRow, endRow, startCol, endCol;
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

    // Ask user if they want to specify a range of rows and columns
    char choice;
    cout << "Do you want to specify a range of rows and columns? (y/n): ";
    cin >> choice;
            if (choice == 'y' || choice == 'Y') {
                // Zoom into specific row/column if the user chooses to
                

                // Step 1: Ask the user to choose a start and end row
                cout << "Enter the start row number (0 to " << city.cityGrid.size() - 1 << "): ";
                cin >> startRow;
                cout << "Enter the end row number (0 to " << city.cityGrid.size() - 1 << "): ";
                cin >> endRow;

                // Check if the row numbers are valid
                if (startRow < 0 || startRow >= city.cityGrid.size() || endRow < 0 || endRow >= city.cityGrid.size() || startRow > endRow) {
                    cout << "Invalid row numbers." << endl;
                    return 1;
                }

                // Step 2: Ask the user to choose a start and end column
                cout << "Enter the start column number (0 to " << city.cityGrid[0].size() - 1 << "): ";
                cin >> startCol;
                cout << "Enter the end column number (0 to " << city.cityGrid[0].size() - 1 << "): ";
                cin >> endCol;

                // Check if the column numbers are valid
                if (startCol < 0 || startCol >= city.cityGrid[0].size() || endCol < 0 || endCol >= city.cityGrid[0].size() || startCol > endCol) {
                    cout << "Invalid column numbers." << endl;
                    return 1;
                }
	}

    int updateCount = 0;

    // Main loop, runs until the time limit is reached
    for (int i = 0; i < timeLimit; i += refreshRate) {
        updateCount++;  // Track the current update cycle

        // Update all city cells
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
                // Step 3: Display the selected range of cells
		city.PrintCityRange(startRow,endRow,startCol,endCol);
            } else {
                // If the user does not want to select rows and columns, display the entire grid
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