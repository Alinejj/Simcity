#include<iostream>
#include<string>
#include "Cell.h"
using namespace std;

//GETTERS
int Cell::getCellPopulation(){
	return cellPopulation;
}
int Cell::getCellPollution(){
	return cellPollution;
}
string Cell::getCellType(){
	return cellType;
}

//SETTERS
void Cell::setCellPopulation(int population){
	cellPopulation = population;
}
void Cell::setCellPollution(int pollution){
	cellPollution = pollution;
}
void Cell::setCellType(string type){
	cellType = type;
}
void Cell::incrementCellPopulation()
{
	if (cellPopulation < 3) {  
        cellPopulation++;
    }
}

void Cell::incrementCellPollution(int incrementAmt)
{
	cellPollution = cellPollution + incrementAmt;
}

//CONSTRUCTORS
Cell::Cell(){
	cellPopulation = 0;
	cellPollution = 0;
	cellType = "unknown";
}

Cell::Cell(string type){
	cellPopulation = 0;
	cellPollution = 0;
	cellType = type;
}

Cell::Cell(Cell& cell){
	cellPopulation = cell.cellPopulation;
	cellPollution = cell.cellPollution;
	cellType = cell.cellType;
	isAdjPowerline = cell.isAdjPowerline;
}


bool Cell::isPowerline()
{
	return (cellType == "T" || cellType == "#");
}
//OTHER
void Cell::printCell(){
	//cout << "Base Cell" << endl;
	if(cellPopulation == 0 && (cellType=="R" || cellType == "I" || cellType =="C"))
	{
		cout << "\t" << cellType << "(" << cellPollution << ")";
	}
	else if(cellPopulation > 0 && (cellType=="R" || cellType == "I" || cellType =="C"))
	{
		cout << "\t" << cellPopulation << "(" << cellPollution << ")";
	}
	else
	{
		cout << "\t" << cellType << "(" << cellPollution << ")";
	}
	
}

bool Cell::getIsAdjacentPowerline()
{
	return isAdjPowerline;
}
void Cell::setIsAdjacentPowerline(bool value)
{
	isAdjPowerline = value;
}
