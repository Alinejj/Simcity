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

char Residential::display() const {
    /*if(population == 0) return '0';
    if(population == 1) return '1';
    if(population == 2) return '2';
    if(population == 3) return '3';
    if(population == 4) return '4';
    return 'R';*/

    if (cellPopulation > 0 && cellPopulation <= 4) {
        return '0' + cellPopulation; // Convert population number to char
    }
    return 'R'; 
}

void Residential::growPopulation(City& city, int i, int j, Cell* currentCell){
    int currPop = currentCell->getCellPopulation();

   if (currPop == 0) {
        if (city.isAdjPowerline(i, j)) {
            currentCell->setCellPopulation(1);
        } else if (city.countAdjPop(i, j) >= 1) {
            currentCell->setCellPopulation(1);
        }
    } else if (currPop == 1 && city.countAdjPop(i, j) >= 2) {
        currentCell->setCellPopulation(2);
    } else if (currPop == 2 && city.countAdjPop(i, j) >= 4) {
        currentCell->setCellPopulation(3);
    } else if (currPop == 3 && city.countAdjPop(i, j) >= 6) {
        currentCell->setCellPopulation(4);
    } else if (currPop == 4 && city.countAdjPop(i, j) >= 8) {
        currentCell->setCellPopulation(4); // Keeps it at max population
    }
}
