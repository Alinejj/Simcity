#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

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

        //extract the csv file name 
        string csvFileName = region.substr(region.find (":") + 1);
        
        //open and read the csv file
        ifstream csvFile(csvFileName);
        if(csvFile.is_open()){
            string line;
            while (getline(csvFile, line)){
                stringstream ss(line);
                string cell;
                vector<string> row;

                //split the line by commas
                while (getline(ss, cell, ',')){
                    row.push_back(cell);
                }

                //process the row
                for(const string& cell : row){
                    cout<<cell<< " ";
                }
                    cout<<endl;


            }

            csvFile.close();
        }

        else{
            cerr<<"Could not open csv file: "<<csvFileName<<endl;
            return 1;
        }

} else {
         cerr << "Could not read in file. ERROR." << endl;
           return 1; 
}




    return 0;
}