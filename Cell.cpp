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

//OTHER
void Cell::printCell(){
	if(cellPopulation == 0 && (cellType=="R" || cellType == "I" || cellType =="C"))
	{
		cout << cellType << " ";
	}
	else if(cellPopulation > 0 && (cellType=="R" || cellType == "I" || cellType =="C"))
	{
		cout << cellPopulation << " ";
	}
	else
	{
		cout << cellType << " ";
	}
}