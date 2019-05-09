#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <time.h>
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

/*
  This will be used only in exercise 1. 
*/
class Graph
{
  int size;
  vector<vector<bool> > G;
  vector<bool> emptyRow;

  vector<vector<int> > GraphAdj;
  vector<vector<vector<int> > > Graphs;
  
  void removeRow(int i);
  void removeColumn(int i);

public:
  Graph(int N);
  Graph(string file);
  void percolateByNodes(double Q);
  void percolateByEdges(double Q);
  void print();
  void printGraphAdj();

  void discardNodesGraphAdj(double Q);

};

#endif