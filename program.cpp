#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

int main() {

    Grid g(20);
    //g.percolateByNodes(.25);
    g.print();

    return 0;
}