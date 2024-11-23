#include <iostream>
#include "Industrial.h"
#include "City.h"
#include "Cell.h"
using namespace std;

Industrial::Industrial() : Cell("I") {  // Calls base constructor to set type
    cellPopulation = 0;
}

Industrial::~Industrial(){}

//constructor
Industrial::Industrial(int population){
    this->cellPopulation = population;
    this->cellType = "I";
}

//sets the cellpopulation and checks that as long as the population of the cell is 0,1,2,3,4 we can assign the cellPopulation to pop
void Industrial::setCellPopulation(int pop){
    if(pop >= 0 && pop <= 2){
        cellPopulation = pop;
    }
}
//gets the cell population
int Industrial::getCellPopulation() {
    return cellPopulation;
}

//update industrial cells according to instructions
void Industrial::updateIndustrial(City& city, int i, int j, Cell* currentCell)
{
	//get cells current population
	int currPop = currentCell->getCellPopulation();

	//get available workers
	int availableWorkers = city.getAvailableWorkers();

	//decision based on cell's current population
	switch(currPop)
	{
		case 0:
			//The cell is adjacent to a power line and available workers is >=2
			if(currentCell->getIsAdjacentPowerline()==true && availableWorkers >= 2)
			{
				currentCell->incrementCellPopulation();
				city.decrementAvailableWorkers();
				city.incrementAvailableGoods();
				currentCell->setCellPollution(currPop);
				city.spreadPollution(i,j,currentCell);
				
			}
			//There is at least 1 adjacent cell with population of at least 1 and available works is >=2
			else if (city.countAdjPop(i, j, 1)>=1 && availableWorkers>=2)
			{
				currentCell->incrementCellPopulation();
				city.decrementAvailableWorkers();
				city.incrementAvailableGoods();
				currentCell->setCellPollution(currPop);
				city.spreadPollution(i,j,currentCell);
								
			}
			break;			
		case 1:
			//There are at least 2 adjacent cells with population of at least 1 and available workers is >=2
			if (city.countAdjPop(i, j, 1)>=2 && availableWorkers>=2)
			{
				currentCell->incrementCellPopulation();
				city.decrementAvailableWorkers();
				city.incrementAvailableGoods();
				currentCell->setCellPollution(currPop);
				city.spreadPollution(i,j,currentCell);
								
			}
			break;
		case 2:
			//There are at least 4 adjacent cells with population of at least 2 and available workers is >=2
			if (city.countAdjPop(i, j, 2)>=4 && availableWorkers>=2)
			{
				currentCell->incrementCellPopulation();
				city.decrementAvailableWorkers();
				city.incrementAvailableGoods();
				currentCell->setCellPollution(currPop);
				city.spreadPollution(i,j,currentCell);
								
			}
			break;
		default:
			break;
	}

}