#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Cell.h"
#include "City.h"
#include "residential.h"

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
            cout<<cell->display()<<" ";
        }
        cout << endl;
    }


}

int City::countAdjPop(int i, int j){
    int popCount = 0;

    int rows[] = {-1, 1, 0 , 0};
    int cols[] = {0, 0, -1, 1};

    for(int k = 0; k < 4; k++){
        int newRow = i + rows[k];
        int newCol = j + cols[k];

        //check if new pos is in bounds
        if(newRow >= 0 && newRow < cityGrid.size() && newCol >= 0 && newCol < cityGrid[0].size()){
            Cell* neighbor = cityGrid[newRow][newCol];
            if(neighbor->getCellPollution() >= 1){
                popCount++;
            }
        }
    }
    return popCount;
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

void City::updateResidentialCells(){
    for(int i =0; i<cityGrid.size(); i++){
        for(int j = 0; j < cityGrid[i].size(); j++){
            if(cityGrid[i][j]->getCellType() == "R"){
                Residential* residentialCell = dynamic_cast<Residential*>(cityGrid[i][j]);
                if (residentialCell) {
                    residentialCell->growPopulation(*this, i, j, residentialCell);
                }
            }
        }
    }
}


