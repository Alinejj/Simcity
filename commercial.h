#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include <iostream>
#include <string>
#include "City.h"
#include "Cell.h"

using namespace std;

class Commercial : public Cell {
public:
    Commercial();
    Commercial(int population);

    // Decides whether this commercial cell should grow
    void updateCommercial(City& city, int i, int j, Cell* currentCell);

    
    // Handles the actual process of growing the cell: increases population and adjusts city resources
    void applyGrowth(Cell* currentCell, City& city, int i, int j, int& availableWorkers, int& availableGoods); 
     
    // Sets the population of this cell (overrides the base class method)
    void setCellPopulation(int pop) override;

    // Gets the current population of this cell (overrides the base class method)
    int getCellPopulation() override;

private:
    int cellPopulation;  // Declare this if it doesn't exist in Cell
};

#endif
