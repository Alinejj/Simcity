#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include<string>
#include "City.h"
#include "Cell.h"
using namespace std;

class Industrial
{
	public:
		int getCityPollution();
		void sumCityPollution();
		void updateIndustrial(City& city, int i, int j, Cell* currentCell);

	private:
		int totalPollution;



};

#endif
