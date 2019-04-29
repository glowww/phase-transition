OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++0x

program.exe: program.o graph.o grid.o node.o
	g++ -o program.exe program.cpp graph.cpp grid.cpp node.cpp
	
graph.o: graph.cpp 
	g++ -c graph.cpp -I $(OPCIONS)

grid.o: grid.cpp 
	g++ -c grid.cpp -I $(OPCIONS)

node.o: node.cpp 
	g++ -c node.cpp -I $(OPCIONS)
	
clean:
	rm *.o
	rm *.exe

clear: clear program.o graph.o grid.o node.o

all: clear program.o graph.o grid.o node.o
