#include "node.h"

Node::Node(bool r, bool b, pair<int,int> p){
    
    enabled = true;

    right = r;
    bottom = b;
    parent = p;
}

bool Node::get(){
    return enabled;
}

bool Node::getRight(){
    return right;
}

bool Node::getBottom(){
    return bottom;
}

pair<int,int> Node::getParent(){
    return parent;
}

void Node::setParent(pair<int,int> p){
    parent = p;
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
        if(right && bottom) cout << "  ";
        else if(right) cout << "_ ";
        else if(bottom) cout << " |";
        else cout << "_|";
    }
    else cout << "X ";
}