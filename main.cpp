#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Cell.h"
#include "City.h"

using namespace std;

City city;
int main(){
    string filename;
    cout << "Enter the filename for the configuration: ";
    getline(cin, filename);
	city.ReadInAndInitialize(filename);
	city.PrintCity();



    return 0;
}