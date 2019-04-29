#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

class Node {

    bool enabled;
    bool right;
    bool bottom;

public:

    Node(bool r, bool b);
    void percolate();
    void percolateRightEdge();
    void percolateBottomEdge();
    void print();
};

#endif