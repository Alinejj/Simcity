#include "residential.h"
#include "City.h"
#include "Cell.h"

using namespace std;

Residential::Residential() : Cell("R") {  // Calls base constructor to set type
    cellPopulation = 0;
}

//constructor
Residential::Residential(int population){
    this->cellPopulation = population;
    this->cellType = "R";
}

Residential::~Residential(){}

//sets the cellpopulation and checks that as long as the population of the cell is 0,1,2,3,4 we can assign the cellPopulation to pop
void Residential::setCellPopulation(int pop){
    if(pop >= 0 && pop <= 4){
        cellPopulation = pop;
    }
}
//gets the cell population
int Residential::getCellPopulation() {
    return cellPopulation;
}


void Residential::growPopulation(City& city, int i, int j, Cell* currentCell){
    //stores the population of my residential cells
    int currPop = currentCell->getCellPopulation();

    //if my population is 0 and im adjacent to a powerline
  if (currPop == 0 && city.isAdjPowerline(i, j) ) {
       //set that cell population to 1 and increment the available workers
        currentCell->setCellPopulation(1);
	    city.incrementAvailableWorkers();
            return; 
        
    }
    //if my population is 0 and im adjacent to at at least 1 cell with population 1 then set the population to be 1 and increment workers
   else if(currPop == 0 && city.countAdjPop(i, j,1) >= 1){
        
            currentCell->setCellPopulation(1);
	    city.incrementAvailableWorkers();
            return; 
        }
    //if my population is 1 and im adjacent to at at least 2 cells with population 1 then set the population to be 2 and increment workers
    else if (currPop == 1 && city.countAdjPop(i, j, 1) >= 2) {
        currentCell->setCellPopulation(2);
        city.incrementAvailableWorkers();
        return; 
    }
    //if my population is 2 and im adjacent to at at least 4 cells with population 2 then set the population to be 3 and increment workers
    else if (currPop == 2 && city.countAdjPop(i, j, 2) >= 4) { 
        currentCell->setCellPopulation(3);
	city.incrementAvailableWorkers();
        return; 
    }
    //if my population is 3 and im adjacent to at at least 6 cells with population 3 then set the population to be 4 and increment workers
    else if (currPop == 3 && city.countAdjPop(i, j, 3) >=6) { 
        currentCell->setCellPopulation(4);
	city.incrementAvailableWorkers();
        return; 
    }
    //if my population is 4 and im adjacent to at at least 8 cells with population 4 then set the population to be 1 and increment workers
    else if (currPop == 4 && city.countAdjPop(i, j, 4) >= 8) { 
        currentCell->setCellPopulation(4); 
	city.incrementAvailableWorkers();
    }
}
