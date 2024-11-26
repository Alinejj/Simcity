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
			//CONSTRUCTORS
		City();
		~City();

		//READ IN
		void ReadInAndInitialize(string filename);
		void setAdjecencyForCells(); //Set into the Cell Class whether each cell is adjacent to certain other cells
		
		//PRINT
		void PrintCity();
		void PrintCityRange(int startRow, int endRow, int startCol, int endCol);

		//PRIMARY UPDATES
		void updateCells();
		int updateResidentialWorkers();
		void spreadPollution(int x, int y, Cell* cell,City& city, Cell* refCell);

		//HELPERS
		int countAdjPop(int i, int j);
		int countAdjPop(int i, int j, int minPop);
		bool isAdjPowerline(int i, int j);
		int getAvailableWorkers();
		void incrementAvailableWorkers();
		void decrementAvailableWorkers();
		void incrementAvailableGoods();
		void decrementAvailableGoods();
		int getAvailableGoods();
		bool isAdjacent(int i, int j, const std::string& type);
		void addTotalWorkers(int workers) ;
		void decrementTotalWorkers(int workers) ;
		int getTotalWorkers() const;
				
		//VECTORS AND VARIABLES
		vector<vector<Cell*>> cityGrid;
		vector<vector<Cell*>> cityGridNext;
		int timeLimit;
		int refreshRate;

	private:
		int availableWorkers;
		int availableGoods;
		int totalWorkers;
};

#endif
