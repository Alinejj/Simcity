#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Cell.h"
#include "City.h"

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