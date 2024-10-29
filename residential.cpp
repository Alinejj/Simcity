#include "residential.h"
#include "City.h"
#include "Cell.h"

using namespace std;

Residential::Residential() : Cell("R") {  // Calls base constructor to set type
    cellPopulation = 0;
}

Residential::Residential(int population){
    this->cellPopulation = population;
    this->cellType = "R";
}

void Residential::setCellPopulation(int pop){
    if(pop >= 0 && pop <= 4){
        cellPopulation = pop;
    }
}

int Residential::getCellPopulation() {
    return cellPopulation;
}


void Residential::growPopulation(City& city, int i, int j, Cell* currentCell){
    int currPop = currentCell->getCellPopulation();

  if (currPop == 0) {
        if (city.isAdjPowerline(i, j)) {
            currentCell->setCellPopulation(1);
            return; 
        }
        else if (city.countAdjPop(i, j) >= 1) {
            currentCell->setCellPopulation(1);
            return; 
        }
    }
    else if (currPop == 1 && city.countAdjPop(i, j) >= 2) {
        currentCell->setCellPopulation(2);
        return; 
    }
    
    else if (currPop == 2 && city.countAdjPop(i, j, 2) >= 4) { 
        currentCell->setCellPopulation(3);
        return; 
    }
    else if (currPop == 3 && city.countAdjPop(i, j, 3) >= 6) { 
        currentCell->setCellPopulation(4);
        return; 
    }
    else if (currPop == 4 && city.countAdjPop(i, j, 4) >= 8) { 
        currentCell->setCellPopulation(4); 
    }
}
