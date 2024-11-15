#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm> // for std::copy
#include <iterator>  // for std::back_inserter
#include "Cell.h"
#include "City.h"
#include "residential.h"
#include "Industrial.h"

using namespace std;



//read in and initialize the city file

void City::ReadInAndInitialize(string filename)
{
	    ifstream configFile(filename);

   
    if (configFile.is_open())
    {

        string region;
        string time;
        string refresh;
	//Read config file
        getline(configFile, region);
        getline(configFile, time);
        getline(configFile, refresh);

        

        configFile.close();

        //extract the csv file name 
        string csvFileName = region.substr(region.find (":") + 1);
        timeLimit = stoi(time.substr(time.find(":") + 1));
        refreshRate = stoi(refresh.substr(refresh.find(":") + 1));
        
        
        //open and read the csv file
        ifstream csvFile(csvFileName);
        if(csvFile.is_open()){
            string line;
            while (getline(csvFile, line)){
                stringstream ss(line);
                string cell;
                vector<string> row;

                //split the line by commas
                while (getline(ss, cell, ',')){
                    row.push_back(cell);
                }

                //process the row and add to the city vector
		vector<Cell*>newRow;
                for(const string& cell : row){
			//create a new cell node
			Cell *newCell = new Cell(cell);
			//push back the new cell node into the row
			newRow.push_back(newCell);
                }
		//push back the new row into the city grid vector
		cityGrid.push_back(newRow);
            }

            csvFile.close();
        }

        else{
            cerr<<"Could not open csv file: "<<csvFileName<<endl;
            return;
        }

} else {
         cerr << "Could not read in file. ERROR." << endl;
           return; 
}

}

void City::PrintCity()
{
    
	// Access and print the elements of the 2D vector
    for (const auto& row : cityGrid) {
        for (const auto& cell : row) {
            cell->printCell();
        }
        cout << endl;
    }
}


int City::countAdjPop(int i, int j){
    int count = 0;
    // Add logic to count adjacent cells with population >= 1
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            if (x >= 0 && x < cityGrid.size() && y >= 0 && y < cityGrid[0].size() && !(x == i && y == j)) {
                if (cityGrid[x][y]->getCellPopulation() >= 1) {
                    count++;
                }
            }
        }
    }
    return count;
}

int City::countAdjPop(int i, int j, int minPop){
    int count = 0;
    // Add logic to count adjacent cells with population >= minPopulation
    for (int x = i - 1; x <= i + 1; ++x) {
        for (int y = j - 1; y <= j + 1; ++y) {
            if (x >= 0 && x < cityGrid.size() && y >= 0 && y < cityGrid[0].size() && !(x == i && y == j)) {
                if (cityGrid[x][y]->getCellPopulation() >= minPop) {
                    count++;
                }
            }
        }
    }
    return count;
}

void City::spreadPollution(int x, int y, Cell* cell)
{
	//pass in coordinates for the pollution spread center
	//loop through city
	int xDiff;
	int yDiff;
	int centralPollution;
	centralPollution = cell->getCellPollution();
	int assignPollution;
	//cout << "Central Cell is " << x << ", " << y << " Current Pollution " << centralPollution << endl;
    	for(int i =0; i<cityGrid.size(); i++)
	{
        	for(int j = 0; j < cityGrid[i].size(); j++)
		{
			//calculate the difference from the center of pollution spread
            		xDiff = abs(i - x);
			yDiff = abs(j - y);
			//cout << "Checking cell: " << i << ", " << j << endl;
			//skip the current cell as it's already been set prior
			if(x==i && y==j)
			{}
			else
			{
				//the higher of the x and y difference is the distance from the center
				if(xDiff > yDiff)
				{
					//Take the cells population minus the distance from the center to increment the pollution
					assignPollution = centralPollution - xDiff;
					if(assignPollution > 0)
					{
						cell->incrementCellPollution(assignPollution);
					}
				}
				else if(yDiff > xDiff)
				{
					//Take the cells population minus the distance from the center to increment the pollution
					assignPollution = centralPollution - yDiff;
					if(assignPollution > 0)
					{
						cell->incrementCellPollution(assignPollution);
					}
				}
				else
				{
					assignPollution = centralPollution - xDiff;
					if(assignPollution > 0)
					{
						cell->incrementCellPollution(assignPollution);
					}
				}
				//cout << "assigning pollution of " << assignPollution << endl;
			}
        	}
    	}

}

bool City::isAdjPowerline(int i, int j){
    int rows[] = {-1, 1, 0 , 0};
    int cols[] = {0, 0, -1, 1};


    for(int k = 0; k < 4; k++){
        int newRow = i + rows[k];
        int newCol = j + cols[k];

        //check if new pos is in bounds
        if(newRow >= 0 && newRow < cityGrid.size() && newCol >= 0 && newCol < cityGrid[0].size()){
            Cell* neighbor = cityGrid[newRow][newCol];
            if(neighbor->isPowerline()){
                return true;
            }
        }
    }
    return false;
}

//loop through the city cells and perform needed updates
void City::updateCells(){
    // Clear cityGridNext before deep copying
    for (auto& row : cityGridNext) {
        for (auto& cell : row) {
            delete cell;  // Deallocate the memory of previous cells in cityGridNext
        }
    }
    cityGridNext.clear();  // Clear the cityGridNext vector to prepare for fresh copying

    // Perform a deep copy to copy the current citygrid into citygrid next
    for (const auto& row : cityGrid) {
        vector<Cell*> newRow;
        for (const auto& cell : row) {
            newRow.push_back(new Cell(*cell));//Call copy constructor
        }
        cityGridNext.push_back(newRow);
    }    

    //loop through the city grid next and make updates
    for(int i =0; i<cityGrid.size(); i++){
        for(int j = 0; j < cityGrid[i].size(); j++){
            if(cityGrid[i][j]->getCellType() == "R"){
                Residential* residentialCell = dynamic_cast<Residential*>(cityGridNext[i][j]);
                residentialCell->growPopulation(*this, i, j, cityGridNext[i][j]);
            }
	    //update the industrial cells
            else if(cityGrid[i][j]->getCellType() == "I"){
		cout << "City Grid Next Cell Type: " << cityGridNext[i][j]->getCellType() << endl;
                Industrial* industrialCell = dynamic_cast<Industrial*>(cityGridNext[i][j]);
                if (industrialCell) {
    			cout << "Industrial cell found at (" << i << ", " << j << ")\n";
    			industrialCell->updateIndustrial(*this, i, j, cityGridNext[i][j]);
		} else {
    			cout << "Failed to cast to Industrial at (" << i << ", " << j << ")\n";
		}
            }
        }
    }
    //deallocate memory for the current city Grid
    for (auto& row : cityGrid) {
        for (auto& cell : row) {
            delete cell;
        }
    }
    cityGrid.clear();

    //Perform a deep copy to copy the next grid back to the current grid
    for (const auto& row : cityGridNext) {
        vector<Cell*> newRow;
        for (const auto& cell : row) {
            newRow.push_back(new Cell(*cell));//Call copy constructor
        }
        cityGrid.push_back(newRow);
    }   

    //deallocate memory for the next city Grid
    for (auto& row : cityGridNext) {
        for (auto& cell : row) {
            delete cell;
        }
    }
    cityGridNext.clear();
	
}

/*COMMENTING OUT AND TRYING THE BELOW INSTEAD-MONICA
int City::updateResidentialWorkers() {
    int totalWorkers = 0;
    for (const auto& row : cityGrid) {
        for (const auto& cell : row) {
            if (cell && cell->getCellType() == "R") {
                totalWorkers += cell->getCellPopulation();
            }
        }
    }
    return totalWorkers;
}
*/

int City::getAvailableWorkers()
{
	return availableWorkers;
}
void City::incrementAvailableWorkers()
{
	availableWorkers++;
}
void City::decrementAvailableWorkers()
{
	availableWorkers--;
}

void City::incrementAvailableGoods()
{
	availableGoods++;
}

void City::decrementAvailableGoods()
{
	availableGoods--;
}

int City::getAvailableGoods()
{
	return availableGoods;
}

//Set into the Cell Class whether each cell is adjacent to certain other cells
void City::setAdjecencyForCells()
{
    bool isAdj;
    for(int i =0; i<cityGrid.size(); i++){
        for(int j = 0; j < cityGrid[i].size(); j++){
	    isAdj = isAdjPowerline(i,j);
	    cityGrid[i][j]->setIsAdjacentPowerline(isAdj);
        }
    }
} 

void City::PrintCityRange(int startRow, int endRow, int startCol, int endCol) {
    // Loop through the specified rows and columns to print the range
    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            // Print each cell using the printCell() method from Cell class
            cityGrid[i][j]->printCell(); 
        }
        cout << endl; // Move to the next row after finishing a row
    }
}