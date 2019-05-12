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

class Graph
{
  /**
    Number of nodes.
  */
  int size;

  /**
    Adjacency matrix.
  */
  vector<vector<bool> > G;

  /**
    Empty row to replace in the adjacency matrix.
  */
  vector<bool> emptyRow;

  /**
    Nodes that have been deleted.
  */
  vector<bool> deleted;

  vector<vector<int> > GraphAdj;
  vector<vector<vector<int> > > Graphs;
  
  /**
    Removes a row from the adjacency matrix (all elements set to 0).

    @param Row number
  */
  void removeRow(int i);

  /**
    Removes a column from the adjacency matrix (all elements set to 0).

    @param Column number
  */
  void removeColumn(int i);

  /**
    Check if exists a hamiltonian cycle. Recursive function used by hamCycle function.

    @return True if exists, false otherwise.
  */
  bool hamCycleRec(int path[], int pos);

  /**
    Check if a node is accesible. Used by hamCycleRec function.

    @return True if accesible, false otherwise.
  */
  bool isSafe(int v, int path[], int pos);

public:
  /**
    Class constructor.

    @param Graph size
  */
  Graph(int N);

  /**
    Class constructor.

    @param File name
  */
  Graph(string file);

  /**
    Percolate the graph by nodes.

    @param Probability Q ∈ [0,1]
  */
  void percolateByNodes(double Q);

  /**
    Percolate the graph by edges.

    @param Probability Q ∈ [0,1]
  */
  void percolateByEdges(double Q);

  /**
    Check if exists a hamiltonian cycle.

    @return True if exists, false otherwise.
  */
  bool hamCycle();

  /**
    Prints the graph as an adjacency matrix.
  */
  void print();

  /**
    Prints the graph as an adjacency matrix.
  */
  void printGraphAdj();

  /**
    Discards nodes from graphAdj with probability Q.

    @param Probability Q ∈ [0,1]
  */
  void discardNodesGraphAdj(double Q);
};

#endif