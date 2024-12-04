#include <iostream>
#include "Cell.h"
#include "City.h"
#include "commercial.h"

using namespace std;

// default constructor for the commercial cell and starts with population = 0
Commercial::Commercial() : Cell("C"), cellPopulation(0) {}

// overloaded constructor for the commercial cell that allows setting an initial population
Commercial::Commercial(int population) : Cell("C"), cellPopulation(population) {}

// returns the current population of the commercial cell
int Commercial::getCellPopulation() {
    return cellPopulation;
}

// updates the population of the commercial cell
void Commercial::setCellPopulation(int pop) {
    this->cellPopulation = pop;
}

// decides if the commercial cell should grow based on the city state and nearby cells
void Commercial::updateCommercial(City& city, int i, int j, Cell* currentCell) {
    int currentPopulation = currentCell->getCellPopulation(); // Get how many people live in this cell
    int workers = city.getAvailableWorkers(); // Check how many workers the city has available
    int goods = city.getAvailableGoods();     // Check how many goods the city has available

    // if the cell has no population
    if (currentPopulation == 0) {
        if (currentCell->getIsAdjacentPowerline()==true && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        } 
        // else it can grow if it’s next to at least one populated cell, and resources are available
        else if (city.countAdjPop(i, j, 1) >= 1 && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        }
    }

    // if the cell already has 1 person living in it
    if (currentPopulation == 1) {
        // it can grow if it’s next to at least two populated cells, and resources are available
        if (city.countAdjPop(i, j, 1) >= 2 && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        }
    }
}

// handles what happens when a cell grows it increases population and decreases city resources
void Commercial::applyGrowth(Cell* currentCell, City& city, int i, int j, int& availableWorkers, int& availableGoods) {
    currentCell->incrementCellPopulation();  // adds one person to this cell
    city.decrementAvailableWorkers();        // uses up one worker from the city
    city.decrementAvailableGoods();          // uses up one unit of goods from the city
}
