#include "node.h"

Node::Node(bool r, bool b){
    
    enabled = true;

    right = r;
    bottom = b;
}

void Node::percolate(){
    enabled = false;
}

void Node::percolateRightEdge(){
    right = false;
}

void Node::percolateBottomEdge(){
    bottom = false;
}

void Node::print(){
    if(enabled){
        if(right && bottom) cout << "A";
        else if(right) cout << "R";
        else if(bottom) cout << "B";
        else cout << "X";
    }
    else cout << "D";
}