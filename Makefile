OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11

SRC = src
PROGRAM = program
BIN = bin

all: program program_a_nodes program_a_edges program_b_nodes \
	program_b_edges program_c program_d_nodes program_d_edges program_d_random

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

program_c: program_c.o graph.o grid.o node.o
	g++ -o program_c.exe $(PROGRAM)/program_c.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_d_nodes: program_d_nodes.o graph.o grid.o node.o
	g++ -o program_d_nodes.exe $(PROGRAM)/program_d_nodes.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_d_edges: program_d_edges.o graph.o grid.o node.o
	g++ -o program_d_edges.exe $(PROGRAM)/program_d_edges.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp

program_d_random: program_d_random.o graph.o grid.o node.o
	g++ -o program_d_random.exe $(PROGRAM)/program_d_random.cpp $(SRC)/graph.cpp $(SRC)/grid.cpp $(SRC)/node.cpp