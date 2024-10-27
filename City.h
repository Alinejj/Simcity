#ifndef CITY_H
#define CITY_H

#include<string>
#include<vector>
#include <iostream>
#include "Cell.h"
//#include "residential.h"

using namespace std;

class City
{
	

	public:
		void ReadInAndInitialize(string filename);
		void PrintCity();
		void updateResidentialCells();
		int countAdjPop(int i, int j);
		bool isAdjPowerline(int i, int j);
		//declaring an empty 2D vector
		vector<vector<Cell*>> cityGrid;

	


};

#endif
