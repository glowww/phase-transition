#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <time.h>
#include <list>
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

  vector<list<int> > GraphAdj;

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

  bool hamCycle();
  bool hamCycleRec(int path[], int pos);
  bool isSafe(int v, int path[], int pos);

};

#endif
