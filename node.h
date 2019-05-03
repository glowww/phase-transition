#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <utility>
using namespace std;

class Node {

    bool enabled;
    bool right;
    bool bottom;
    pair<int,int> parent;

public:

    Node(bool r, bool b, pair<int,int> p);
    
    bool get();
    bool getRight();
    bool getBottom();
    pair<int,int> getParent();
    void setParent(pair<int,int> p);

    void percolate();
    void percolateRightEdge();
    void percolateBottomEdge();
    void print();
};

#endif