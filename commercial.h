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

    void updateCommercial(City& city, int i, int j, Cell* currentCell);

    void applyGrowth(Cell* currentCell, City& city, int i, int j, int& availableWorkers, int& availableGoods);

    void setCellPopulation(int pop) override;
    int getCellPopulation() override;

private:
    int cellPopulation;  // Declare this if it doesn't exist in Cell
};

#endif
