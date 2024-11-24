#ifndef CELL_H
#define CELL_H

#include<string>
//#include "City.h"
//#include "residential.h"

using namespace std;

class Cell
{
	public:
		//CONSTRUCTORS
		//CONSTRUCTORS
		Cell();
		Cell(string type);
		Cell(Cell& cell);
		virtual ~Cell() = default;

		//GETTERS AND SETTERS
		virtual int getCellPopulation();
		virtual void setCellPopulation(int population);
		void incrementCellPopulation();
		virtual int getCellPollution();
		virtual void setCellPollution(int pollution);
		void incrementCellPollution(int incrementAmt);
		virtual string getCellType();
		virtual void setCellType(string type);

		//PRINT
		virtual void printCell();

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
