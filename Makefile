OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

program: program.o graph.o grid.o node.o
	g++ -o program.exe program.cpp graph.cpp grid.cpp node.cpp


program_a_nodes: program_a_nodes.o graph.o grid.o node.o
	g++ -o program_a_nodes.exe program_a_nodes.cpp graph.cpp grid.cpp node.cpp

program_a_edges: program_a_edges.o graph.o grid.o node.o
	g++ -o program_a_edges.exe program_a_edges.cpp graph.cpp grid.cpp node.cpp
	
program_b_nodes: program_b_nodes.o graph.o grid.o node.o
	g++ -o program_b_nodes.exe program_b_nodes.cpp graph.cpp grid.cpp node.cpp

program_b_edges: program_b_edges.o graph.o grid.o node.o
	g++ -o program_b_edges.exe program_b_edges.cpp graph.cpp grid.cpp node.cpp


program_d_nodes: program_d_nodes.o graph.o grid.o node.o
	g++ -o program_d_nodes.exe program_d_nodes.cpp graph.cpp grid.cpp node.cpp

program_d_edges: program_d_edges.o graph.o grid.o node.o
	g++ -o program_d_edges.exe program_d_edges.cpp graph.cpp grid.cpp node.cpp

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
