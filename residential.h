#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include <iostream>
#include <string>
#include "Cell.h"
#include "City.h"

using namespace std;

class Residential : public Cell{
    public:
         Residential();
	       ~Residential();
        Residential(int population); //default constructer
        void setCellPopulation(int pop) override;
        int getCellPopulation() override;
        void growPopulation(City& city, int i, int j, Cell* currentCell);
        
        

    private:
      int population;
       
       

};

#endif
