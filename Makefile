CXX = g++ # Compiler
CXXFLAGS = -std=c++11 -Wall -g # Flags

all: Main

Main: SquareMat.o Main.o  
	$(CXX) $(CXXFLAGS) -o Main SquareMat.o Main.o

SquareMat.o: SquareMat.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c SquareMat.cpp

Main.o: Main.cpp SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c Main.cpp -o Main.o

Test.o: test.cpp doctest.h SquareMat.hpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o Test.o

Test: SquareMat.o Test.o
	$(CXX) $(CXXFLAGS) -o Test SquareMat.o Test.o

test: Test
	./Test

valgrind: Main
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./Main

clean:
	rm -f SquareMat.o Main.o Test.o Main Test

.PHONY: all clean test valgrind
