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

    // Prompt user to enter configuration filename
    cout << "Enter the filename for the configuration: ";
    getline(cin, filename);

    // Initialize city with configuration file data, including refresh rate and time limit
    city.ReadInAndInitialize(filename);

    // Access refresh rate and time limit from the city object
    int refreshRate = city.refreshRate;
    int timeLimit = city.timeLimit;
    
    city.PrintCity();  // Initial display of city layout

    int updateCount = 0;
    bool updated = true;

    // Main loop, runs until no updates or until time limit is reached
    for(int i=0; i<timeLimit; i+=refreshRate){
    //while (updated && (updateCount < timeLimit)) {
	cout << "RefreshRate: " << refreshRate << " update: " << updated << " update count: " << updateCount << " timelimit: " << timeLimit << endl;
        updateCount++;  // Track the current update cycle

        // Store previous city grid state to check for changes
        vector<vector<Cell*>> prevState = city.cityGrid;

        // Update residential cells
        city.updateResidentialCells();

        // Check if city grid has changed
        updated = (prevState != city.cityGrid);

        // Output at the specified refresh rate
        if (updateCount % refreshRate == 0) {
            cout << "\nSimulation update " << updateCount << ":\n";
            city.PrintCity();
            cout << "\nPress Enter to continue to the next refresh...";
            cin.get(); // Wait for user input
        }
    }

    cout << "\nSimulation complete. No further updates available or time limit reached.\n";

    return 0;
}
