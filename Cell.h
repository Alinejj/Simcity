#ifndef CELL_H
#define CELL_H

#include<string>
//#include "City.h"
//#include "residential.h"

using namespace std;

class Cell
{
	public:
		Cell();
		Cell(string type);
		virtual int getCellPopulation();
		virtual void setCellPopulation(int population);
		void incrementCellPopulation();
		virtual int getCellPollution();
		virtual void setCellPollution(int pollution);
		void incrementCellPollution(int incrementAmt);
		virtual string getCellType();
		virtual void setCellType(string type);
		void printCell();
		bool getIsAdjacentPowerline();
		void setIsAdjacentPowerline(bool value);
		bool isPowerline();
		

	protected:
		int cellPopulation;
		int cellPollution;
		string cellType;
		bool isAdjPowerline;
		




};

#endif
