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
		virtual int getCellPollution();
		virtual void setCellPollution(int pollution);
		virtual string getCellType();
		virtual void setCellType(string type);
		virtual char display() const;
		//Cell getAdjacentCells();
		//void setAdjacentCells(Cell* adjacencyList);
		void printCell();
		bool isPowerline();
		

	protected:
		int cellPopulation;
		int cellPollution;
		string cellType;
		//Cell* adjacentCells[8];
		




};

#endif
