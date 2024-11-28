# SimCity

**Description**
This project simulates how pollution spreads across a city with 3 zones (Industrial, Residential, and Commercial).

**Prerequisites**
There are 2 files needed to run the program and they should be placed in the main program folder

- Config.txt should provide the following inputs in this format
```bash
Region Layout:region1.csv
Time Limit:20
Refresh Rate:1
```

- region1.csv should provide the layout for the city grid in this format
, ,T,#,T,T,T, 
I,I,I,-,C,C,T, 
I,I,I,-,C,C,T,P
I,I,I,-,C,C,T, 
-,-,-,-,-,-,#,-
 , ,-,R,R,R,T, 
 , ,-,R,R,R, , 
 , ,-,R,R,R, , 

- Other program files (.cpp and .h files included with the zip file and a makefile)


