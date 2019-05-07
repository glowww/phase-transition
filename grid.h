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

    int size;
    vector<vector<Node> > G;
    vector<bool> emptyRow;

public:

    Grid(int N);
    void percolateByNodes(double Q);
    void percolateByEdges(double Q);
    void print();

	pair<int,int> findUF(pair<int,int> id);
	void unionUF(pair<int,int> id1, pair<int,int> id2);
	bool propiedad(); 
};

#endif