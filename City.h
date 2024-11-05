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
		void setAdjecencyForCells(); //Set into the Cell Class whether each cell is adjacent to certain other cells
		void PrintCity();
		void updateCells();
		int countAdjPop(int i, int j);
		int countAdjPop(int i, int j, int minPop);
		bool isAdjPowerline(int i, int j);
		int updateResidentialWorkers();
		//declaring an empty 2D vector
		vector<vector<Cell*>> cityGrid;
		int getAvailableWorkers();
		void incrementAvailableWorkers();
		void decrementAvailableWorkers();
		
	
	
	int timeLimit;
	int refreshRate;

	private:
		int availableWorkers;
};

#endif
