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
int main(){
    

    string filename;
    cout << "Enter the filename for the configuration: ";
    getline(cin, filename);
	city.ReadInAndInitialize(filename);
	city.PrintCity();


    bool updated = true;

    while(updated){
        cout<<"\nSimulation of Residential Cells...\n";

        
        //store state of city before update
        vector<vector<Cell*>> prevState = city.cityGrid;

        //update the cells
        city.updateResidentialCells();

        //print the update
        city.PrintCity();

        //check if its updated
        updated = (prevState != city.cityGrid);


        
    }

    cout<<"\nNo more updated avaialable. Sim complete"<<endl;


    return 0;
}