#include <iostream>
#include "Cell.h"
#include "City.h"
#include "commercial.h"

using namespace std;

// Default constructor for a commercial cell, starts with population = 0
Commercial::Commercial() : Cell("C"), cellPopulation(0) {}

// Overloaded constructor for a commercial cell, allows setting an initial population
Commercial::Commercial(int population) : Cell("C"), cellPopulation(population) {}

// Returns the current population of this commercial cell
int Commercial::getCellPopulation() {
    return cellPopulation;
}

// Updates the population of this commercial cell
void Commercial::setCellPopulation(int pop) {
    this->cellPopulation = pop;
}

// This function decides if a commercial cell should grow based on the city state and nearby cells
void Commercial::updateCommercial(City& city, int i, int j, Cell* currentCell) {
    int currentPopulation = currentCell->getCellPopulation(); // Get how many people live in this cell
    int workers = city.getAvailableWorkers(); // Check how many workers the city has available
    int goods = city.getAvailableGoods();     // Check how many goods the city has available

    // If this cell has no population
    if (currentPopulation == 0) {
        // It can grow if it's next to a powerline and there are enough workers and goods
        if (currentCell->getIsAdjacentPowerline() && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        } 
        // Or it can grow if it’s next to at least one populated cell, and resources are available
        else if (city.countAdjPop(i, j, 1) >= 1 && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        }
    }

    // If this cell already has 1 person living in it
    if (currentPopulation == 1) {
        // It can grow if it’s next to at least two populated cells, and resources are available
        if (city.countAdjPop(i, j, 1) >= 2 && workers >= 1 && goods >= 1) {
            applyGrowth(currentCell, city, i, j, workers, goods);
        }
    }
}

// Handles what happens when a cell grows: increases population and decreases city resources
void Commercial::applyGrowth(Cell* currentCell, City& city, int i, int j, int& availableWorkers, int& availableGoods) {
    currentCell->incrementCellPopulation();  // Add one person to this cell
    city.decrementAvailableWorkers();        // Use up one worker from the city
    city.decrementAvailableGoods();          // Use up one unit of goods from the city
}
