#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include<string>
#include "Cell.h"
#include "City.h"

using namespace std;

class Industrial: public Cell
{
	public:
		//CONSTRUCTORS
		Industrial();
		~Industrial() override = default;
		Industrial(string type);
		Industrial(Industrial& cell);

		//PRINT
		void printCell() override;

		//OTHER
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
