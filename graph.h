#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

/*
  This will be used only in exercise 1. 
*/
class Graph
{
  int size;
  vector<vector<bool>> G;
  vector<bool> emptyRow;

  void removeRow(int i);
  void removeColumn(int i);

public:
  Graph(int N);
  void percolateByNodes(double Q);
  void percolateByEdges(double Q);
  void print();

};

#endif