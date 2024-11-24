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
		void PrintCity();
		void updateCells();
		int countAdjPop(int i, int j);
		int countAdjPop(int i, int j, int minPop);
		bool isAdjPowerline(int i, int j);
		int updateResidentialWorkers();
		//declaring an empty 2D vector
		vector<vector<Cell*>> cityGrid;
		vector<vector<Cell*>> cityGridNext;
		int getAvailableWorkers();
		void incrementAvailableWorkers();
		void decrementAvailableWorkers();
		void incrementAvailableGoods();
		void decrementAvailableGoods();
		int getAvailableGoods();
		void spreadPollution(int x, int y, Cell* cell);
		void PrintCityRange(int startRow, int endRow, int startCol, int endCol);
		int timeLimit;
		int refreshRate;
		bool isAdjacent(int i, int j, const std::string& type);


   		void addTotalWorkers(int workers) ;

    	void decrementTotalWorkers(int workers) ;

    	int getTotalWorkers() const;



	private:
		int availableWorkers;
		int availableGoods;
		int totalWorkers;
};

#endif
