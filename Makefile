
# Makefile

# Compiler
CXX = g++

# Source files
SRC = main.cpp Cell.cpp City.cpp residential.cpp Industrial.cpp commercial.cpp

# Output binary
TARGET = main

# Build rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET)

# Clean rule to remove the compiled binary
clean:
	rm -f $(TARGET)

.PHONY: all clean 
