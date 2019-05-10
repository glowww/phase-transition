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

  bool hamCycle();
  bool hamCycleRec(int path[], int pos);
  bool isSafe(int v, int path[], int pos);

  void percolateHam();

  bool hamCycle_MAT(const vector<vector<int> > &mat);
  bool hamCycleRec_MAT(const vector<vector<int> > &mat, int path[], int pos);
  bool isSafe_MAT(const vector<vector<int> > &mat, int v, int path[], int pos);

};

#endif
