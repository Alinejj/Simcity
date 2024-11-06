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
	cellPopulation++;
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

bool Cell::isPowerline()
{
	return (cellType == "T" || cellType == "#");
}
//OTHER
void Cell::printCell(){
	if(cellPopulation == 0 && (cellType=="R" || cellType == "I" || cellType =="C"))
	{
		cout << cellType << "(" << cellPollution << ")" << " ";
	}
	else if(cellPopulation > 0 && (cellType=="R" || cellType == "I" || cellType =="C"))
	{
		cout << cellPopulation << "(" << cellPollution << ")" << " ";
	}
	else
	{
		cout << cellType << "(" << cellPollution << ")" << " ";
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
