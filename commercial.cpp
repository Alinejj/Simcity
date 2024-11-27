#include <iostream>
#include "Cell.h"
#include "City.h"
#include "commercial.h"


using namespace std;

Commercial::Commercial() : Cell("C"), cellPopulation(0) {}

Commercial::Commercial(int population) : Cell("C"), cellPopulation(population) {}

int Commercial::getCellPopulation() {
    return cellPopulation;
}

void Commercial::setCellPopulation(int pop) {
    this->cellPopulation = pop;
}

void Commercial::updateCommercial(City& city, int i, int j, Cell* currentCell) {
    int currentPopulation = currentCell->getCellPopulation();
    int workers = city.getAvailableWorkers();
    int goods = city.getAvailableGoods();

    if (currentPopulation == 0) {
        if (currentCell->getIsAdjacentPowerline()==true && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        } else if (city.countAdjPop(i, j, 1) >= 1 && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        }
    }

    if (currentPopulation == 1) {
        if (city.countAdjPop(i, j, 1) >= 2 && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        }
    }
}

void Commercial::applyGrowth(Cell* currentCell, City& city, int i, int j, int& availableWorkers, int& availableGoods) {
    currentCell->incrementCellPopulation();
    city.decrementAvailableWorkers();
    city.decrementAvailableGoods();
}
