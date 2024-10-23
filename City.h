#ifndef CITY_H
#define CITY_H

#include<string>
#include<vector>
#include "Cell.h"
using namespace std;

class City
{

	public:
		void ReadInAndInitialize(string filename);
		void PrintCity();
		//declaring an empty 2D vector
		vector<vector<Cell*>> cityGrid;		

};

#endif
