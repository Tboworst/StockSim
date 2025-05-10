# Compiler settings
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Build the executable
StockSim: main.o Exchange.o Portfolio.o Stock.o
	$(CXX) $(CXXFLAGS) main.o Exchange.o Portfolio.o Stock.o -o StockSim

# Compile main.cpp
main.o: main.cpp Exchange.h Portfolio.h Stock.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile Exchange.cpp
Exchange.o: Exchange.cpp Exchange.h Stock.h
	$(CXX) $(CXXFLAGS) -c Exchange.cpp

# Compile Portfolio.cpp
Portfolio.o: Portfolio.cpp Portfolio.h Stock.h
	$(CXX) $(CXXFLAGS) -c Portfolio.cpp

# Compile Stock.cpp (missing before)
Stock.o: Stock.cpp Stock.h
	$(CXX) $(CXXFLAGS) -c Stock.cpp

# Clean up object and binary files
clean:
	rm -f *.o StockSim

# Run the program
run:
	./StockSim
