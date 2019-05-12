OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

SRC = src
PROGRAM = program
BIN = bin

all: program program_a_nodes program_a_edges program_b_nodes \
	program_b_edges program_d_nodes program_d_edges

program.o: $(PROGRAM)/program.cpp 
	g++ -c $(PROGRAM)/program.cpp -I $(OPCIONS)

program_a_nodes.o: $(PROGRAM)/program_a_nodes.cpp 
	g++ -c $(PROGRAM)/program_a_nodes.cpp -I $(OPCIONS)

program_a_edges.o: $(PROGRAM)/program_a_edges.cpp 
	g++ -c $(PROGRAM)/program_a_edges.cpp -I $(OPCIONS)

program_b_nodes.o: $(PROGRAM)/program_b_nodes.cpp 
	g++ -c $(PROGRAM)/program_b_nodes.cpp -I $(OPCIONS)

program_b_edges.o: $(PROGRAM)/program_b_edges.cpp 
	g++ -c $(PROGRAM)/program_b_edges.cpp -I $(OPCIONS)

program_d_nodes.o: $(PROGRAM)/program_d_nodes.cpp 
	g++ -c $(PROGRAM)/program_d_nodes.cpp -I $(OPCIONS)

program_d_edges.o: $(PROGRAM)/program_d_edges.cpp 
	g++ -c $(PROGRAM)/program_d_edges.cpp -I $(OPCIONS)

graph.o: $(SRC)/graph.cpp 
	g++ -c $(SRC)/graph.cpp -I $(OPCIONS)

grid.o: $(SRC)/grid.cpp 
	g++ -c $(SRC)/grid.cpp -I $(OPCIONS)

node.o: $(SRC)/node.cpp 
	g++ -c $(SRC)/node.cpp -I $(OPCIONS)

%.o: $(SRC)/%.cpp
	g++ -c $(SRC) -I $(OPCIONS) -o $(BIN)/$@

%.o: $(PROGRAM)/%.cpp
	g++ -c $(PROGRAM) -I $(OPCIONS) -o $(BIN)/$@
	
program: program.o graph.o grid.o node.o
	g++ -o program.exe $(PROGRAM)/program.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_a_nodes: program_a_nodes.o graph.o grid.o node.o
	g++ -o program_a_nodes.exe $(PROGRAM)/program_a_nodes.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_a_edges: program_a_edges.o graph.o grid.o node.o
	g++ -o program_a_edges.exe $(PROGRAM)/program_a_edges.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp
	
program_b_nodes: program_b_nodes.o graph.o grid.o node.o
	g++ -o program_b_nodes.exe $(PROGRAM)/program_b_nodes.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_b_edges: program_b_edges.o graph.o grid.o node.o
	g++ -o program_b_edges.exe $(PROGRAM)/program_b_edges.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_d_nodes: program_d_nodes.o graph.o grid.o node.o
	g++ -o program_d_nodes.exe $(PROGRAM)/program_d_nodes.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_d_edges: program_d_edges.o graph.o grid.o node.o
	g++ -o program_d_edges.exe $(PROGRAM)/program_d_edges.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp