OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

c_program.exe: c_program.o graph.o grid.o node.o
	g++ -o c_program.exe c_program.cpp graph.cpp grid.cpp node.cpp
	
graph.o: graph.cpp 
	g++ -c graph.cpp -I $(OPCIONS)

grid.o: grid.cpp 
	g++ -c grid.cpp -I $(OPCIONS)

node.o: node.cpp 
	g++ -c node.cpp -I $(OPCIONS)
	
clean:
	rm *.o
	rm *.exe

clear: clear c_program.o graph.o grid.o node.o

all: clear c_program.o graph.o grid.o node.o
