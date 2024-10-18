#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include<string>
using namespace std;

class Industrial
{
	public:
		int getCityPollution();
		void sumCityPollution();
		void updateIndustrialCell();

	private:
		int totalPollution;



};

#endif
