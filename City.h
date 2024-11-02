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
		int countAdjPop(int i, int j, int minPop);
		bool isAdjPowerline(int i, int j);
		int updateResidentialWorkers();
		//declaring an empty 2D vector
		vector<vector<Cell*>> cityGrid;

	
	int timeLimit;
	int refreshRate;


};

#endif
