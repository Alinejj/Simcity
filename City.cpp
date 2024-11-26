
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm> 
#include <iterator>  
#include "Cell.h"
#include "City.h"
#include "residential.h"
#include "Industrial.h"
#include "commercial.h"

using namespace std;


//CONSTRUCTORS
City::City()
{
	availableWorkers = 0;
	availableGoods = 0;
	timeLimit = 0;
	refreshRate = 0;
}

City::~City(){}

//read in and initialize the city file

void City::ReadInAndInitialize(string filename)
{
	ifstream configFile(filename);

   
	if (configFile.is_open()){
        	string region;
        	string time;
        	string refresh;

		//Read config file
        	getline(configFile, region);
        	getline(configFile, time);
        	getline(configFile, refresh);

       		//close the config file
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
				if(cell == "I")
				{
					Industrial *indCell = new Industrial(cell);
					newRow.push_back(indCell);					
				}
				else
				{
					Cell *newCell = new Cell(cell);
					//push back the new cell node into the row
					newRow.push_back(newCell);
				}
			
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

}//end function

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

void City::spreadPollution(int x, int y, Cell* cell, City& city, Cell* refCell)
{
/*-DISABLING DEBUG CODE
	//Cell being passed in by reference is the one we are updating
    cout << "BEFORE Pollution Spread: - City Grid" << endl;
    for (const auto& row : cityGrid) {
        for (const auto& cell : row) {
            cell->printCell();
        }
        cout << endl;
    }

	    // Before modifications
    cout << "BEFORE Pollution Spread: - City Grid Next" << endl;
    for (const auto& row : cityGridNext) {
        for (const auto& cell : row) {
            cell->printCell();
        }
        cout << endl;
    }
*/

	//pass in coordinates for the pollution spread center
	//loop through city
	int xDiff;
	int yDiff;
	int pollutionToSpread;
	pollutionToSpread= refCell->getCellPopulation();
	int assignPollution;
	//cout << "Central Cell is " << x << ", " << y << " Pollution to Spread " << pollutionToSpread<< endl;
    	for(int i =0; i<cityGridNext.size(); i++)
	{
        	for(int j = 0; j < cityGridNext[i].size(); j++)
		{
			//calculate the difference from the center of pollution spread
            		xDiff = abs(i - x);
			yDiff = abs(j - y);
			//skip the current cell as it's already been set prior
			if(x==i && y==j)
			{}
			else
			{
				//the higher of the x and y difference is the distance from the center
				if(xDiff > yDiff)
				{
					//Take the cells population minus the distance from the center to increment the pollution
					assignPollution = pollutionToSpread- xDiff;
					if(assignPollution > 0)
					{
						
						//cout << "Assigning pollution of " << assignPollution << " to cell " << i << "," << j << endl;
						//cout << "Current pollution: " << cityGridNext[i][j]->getCellPollution() << endl;
						cityGridNext[i][j]->incrementCellPollution(assignPollution);
						//cout << "New pollution: " << cityGridNext[i][j]->getCellPollution() << endl;
					}
				}
				else if(yDiff > xDiff)
				{
					//Take the cells population minus the distance from the center to increment the pollution
					assignPollution = pollutionToSpread- yDiff;
					if(assignPollution > 0)
					{
						//cout << "Assigning pollution of " << assignPollution << " to cell " << i << "," << j << endl;
						//cout << "Current pollution: " << cityGridNext[i][j]->getCellPollution() << endl;
						cityGridNext[i][j]->incrementCellPollution(assignPollution);
						//cout << "New pollution: " << cityGridNext[i][j]->getCellPollution() << endl;
					}
				}
				else
				{
					assignPollution = pollutionToSpread- xDiff;
					if(assignPollution > 0)
					{
						//cout << "Assigning pollution of " << assignPollution << " to cell " << i << "," << j << endl;
						//cout << "Current pollution: " << cityGridNext[i][j]->getCellPollution() << endl;
						cityGridNext[i][j]->incrementCellPollution(assignPollution);
						//cout << "New pollution: " << cityGridNext[i][j]->getCellPollution() << endl;
					}
				}
				
			}
        	}
    	}

/*-DISABLING DEBUG CODE
	    // after modifications
    cout << "AFTER Pollution Spread:" << endl;
    for (const auto& row : cityGridNext) {
        for (const auto& cell : row) {
            cell->printCell();
        }
        cout << endl;
    }
*/
}

bool City::isAdjPowerline(int i, int j) {
    return isAdjacent(i, j, "T") || isAdjacent(i, j, "#");
}

bool City::isAdjacent(int i, int j, const std::string& type) {
    int rows[] = {-1, 1, 0, 0};
    int cols[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int newRow = i + rows[k];
        int newCol = j + cols[k];

        if (newRow >= 0 && newRow < cityGrid.size() && newCol >= 0 && newCol < cityGrid[0].size()) {
            if (cityGrid[newRow][newCol]->getCellType() == type) {
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
	//cout << "STARTING DEEP COPY" << endl << endl;
    for (const auto& row : cityGrid) {
        vector<Cell*> newRow;
        for (const auto& cell : row) {
		//cout << "Celltype: " << cell->getCellType() << endl;
		if(Industrial* indCell = dynamic_cast<Industrial*>(cell))
		{
			//cout << "trying to copy Industrial" << endl;
			newRow.push_back(new Industrial(*indCell));//call industrial copy constructor
		}
		else
		{
			newRow.push_back(new Cell(*cell));//Call copy constructor
		}
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
		//cout << "City Grid Next Cell Type: " << cityGridNext[i][j]->getCellType() << endl;
                Industrial* industrialCell = dynamic_cast<Industrial*>(cityGridNext[i][j]);
                if (industrialCell) {
    			//cout << "Industrial cell found at (" << i << ", " << j << ")\n";
    			industrialCell->updateIndustrial(*this, i, j, cityGridNext[i][j],cityGrid[i][j]);
		} else {
    			cout << "Failed to cast to Industrial at (" << i << ", " << j << ")\n";
		}
            }

            if(cityGrid[i][j]->getCellType() == "C"){
                Commercial* commercialCell = dynamic_cast<Commercial*>(cityGrid[i][j]);
                commercialCell->updateCommercial(*this, i, j, cityGrid[i][j]);


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
		//cout << "Celltype: " << cell->getCellType() << endl;
		if(Industrial* indCell = dynamic_cast<Industrial*>(cell))
		{
			//cout << "trying to copy Industrial" << endl;
			newRow.push_back(new Industrial(*indCell));//call industrial copy constructor
		}
		else
		{
			newRow.push_back(new Cell(*cell));//Call copy constructor
		}

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
void City::setAdjecencyForCells() {
    for (int i = 0; i < cityGrid.size(); i++) {
        for (int j = 0; j < cityGrid[i].size(); j++) {
            cityGrid[i][j]->setIsAdjacentPowerline(isAdjacent(i, j,"T"));
        }
    }
}

void City::PrintCityRange(int startRow, int endRow, int startCol, int endCol) {
    if (startRow < 0 || endRow >= cityGrid.size() || startCol < 0 || endCol >= cityGrid[0].size()) {
        cerr << "Error: Specified range is out of bounds." << endl;
        return;
    }

    for (int i = startRow; i <= endRow; ++i) {
        for (int j = startCol; j <= endCol; ++j) {
            cityGrid[i][j]->printCell();
        }
        cout << endl;
    }
}




void City::addTotalWorkers(int workers) {
        totalWorkers += workers;
    }

void City::decrementTotalWorkers(int workers) {
        totalWorkers -= workers;
    }

int City::getTotalWorkers() const {
        return totalWorkers;
    }