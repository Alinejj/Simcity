#ifndef CELL_H
#define CELL_H

#include<string>
using namespace std;

class Cell
{
	public:
		Cell();
		Cell(string type);
		int getCellPopulation();
		void setCellPopulation(int population);
		int getCellPollution();
		void setCellPollution(int pollution);
		string getCellType();
		void setCellType(string type);
		//Cell getAdjacentCells();
		//void setAdjacentCells(Cell* adjacencyList);
		void printCell();

	private:
		int cellPopulation;
		int cellPollution;
		string cellType;
		//Cell* adjacentCells[8];
		




};

#endif
