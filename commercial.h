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

    // decides whether the commercial cell should grow
    void updateCommercial(City& city, int i, int j, Cell* currentCell);

    
    // hanldes the actual process of growing the cell
    void applyGrowth(Cell* currentCell, City& city, int i, int j, int& availableWorkers, int& availableGoods); 
     
    // sets the population of the cell
    void setCellPopulation(int pop) override;

    // gets the current population of this cell 
    int getCellPopulation() override;

private:
    int cellPopulation;  
};

#endif
