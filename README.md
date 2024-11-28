# SimCity

# Description
This project simulates how pollution spreads across a city with 3 zones (Industrial, Residential, and Commercial).

# Prerequisites
There are 2 files needed to run the program and they should be placed in the main program folder

- Config.txt should provide the following inputs in this format
```bash
Region Layout:region1.csv
Time Limit:20
Refresh Rate:1
```

- region1.csv should provide the layout for the city grid in this format
```bash
, ,T,#,T,T,T, 
I,I,I,-,C,C,T, 
I,I,I,-,C,C,T,P
I,I,I,-,C,C,T, 
-,-,-,-,-,-,#,-
 , ,-,R,R,R,T, 
 , ,-,R,R,R, , 
 , ,-,R,R,R, , 
```

- Other program files (.cpp and .h files included with the zip file and a makefile)

# Compiling
Compile using the makefile as follows
```bash
make
```

# Running
Run after compiling using the following command
```bash
./main
```
After running the program it will prompt you to enter the config file you are using. Enter config.txt and press enter
```bash
Enter the filename for the configuration: config.txt
```
Then after each time step it will output the updated city grid and prompt the user to hit enter to continue the simulation
```bash
Press Enter to continue to the next refresh...
```
# Bonus Points
When running the program, it will prompt the user whether they want to grow a region. If the user answers yes (y), it will then prompt for the start row of the region to grow. Then the entire program will run for only that prompted region.
# Team Members
Project group 004 created this program and consisted of the following people:
- Monica King
- Laasya Ankem
- Aline Jouaidi
- Kyathi Uyyala



