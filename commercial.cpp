#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main(){
    string filename;
    cout << "Enter the filename for the configuration: ";
    std::getline(cin, filename);

    ifstream configFile(filename);

   
    if (configFile.is_open())
    {

        string region;
        string time;
        string refresh;

        getline(configFile, region);
       

        getline(configFile, time);
       

        getline(configFile, refresh);

       

        configFile.close();

} else {
         cerr << "Could not read in file. ERROR." << endl;
           return 1; 
}




    return 0;
}