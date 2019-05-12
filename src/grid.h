// grid.h
#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <time.h>
#include <utility>
#include "node.h"

using namespace std;

class Grid {

    /**
        Number of rows or columns.
    */
    int size;

    /**
        Grid.
    */
    vector<vector<Node> > G;

public:

    /**
        Class constructor.

        @param Grid size (NxN)
    */
    Grid(int N);

    /**
        Percolate the grid by nodes.

        @param Probability Q ∈ [0,1]
    */
    void percolateByNodes(double Q);

    /**
        Percolate the grid by edges.

        @param Probability Q ∈ [0,1]
    */
    void percolateByEdges(double Q);

    /**
        Prints the graph as an adjacency matrix.
    */
    void print();

    /**
        Finds the parent of the node.

        @param Node position on the grid
        @return Parent position on the grid
    */
	pair<int,int> findUF(pair<int,int> id);

    /**
        Joins two nodes in the UF structure.

        @param Node position 1
        @param Node position 2
    */
	void unionUF(pair<int,int> id1, pair<int,int> id2);

    /**
        Check if the property is satisfied.

        @return True if satisfied, false otherwise.
    */
	bool propiedad(); 
};

#endif