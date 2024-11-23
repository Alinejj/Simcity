#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include<string>
#include "Cell.h"
#include "City.h"

using namespace std;

class Industrial: public Cell
{
	public:
		Industrial();
		~Industrial();
		int getCityPollution();
		void sumCityPollution();
		void updateIndustrial(City& city, int i, int j, Cell* currentCell);
		void setCellPopulation(int pop) override;
        int getCellPopulation() override;
		Industrial(int population);

	private:
		int totalPollution;



};

#endif
