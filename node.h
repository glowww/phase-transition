#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <utility>
using namespace std;

class Node {

    /**
        Node is enabled.
    */
    bool enabled;

    /**
        Edge between this node and the node below.
    */
    bool right;

    /**
        Edge between this node and the node to the right.
    */
    bool bottom;

    /**
        Parent position.
    */
    pair<int,int> parent;

public:

    /**
        Class constructor.

        @param right
        @param bottom
        @param parent
    */
    Node(bool r, bool b, pair<int,int> p);
    
    /**
        @return enabled
    */
    bool get();

    /**
        @return right
    */
    bool getRight();

    /**
        @return bottom
    */
    bool getBottom();

    /**
        @return parent
    */
    pair<int,int> getParent();

    /**
        Sets the parent node position.

        @param parent
    */
    void setParent(pair<int,int> p);
    
    /**
        Sets enabled to false.
    */
    void percolate();

    /**
        Sets right to false.
    */
    void percolateRightEdge();

    /**
        Sets bottom to false.
    */
    void percolateBottomEdge();

    /**
        Prints the node.
    */
    void print();
};

#endif