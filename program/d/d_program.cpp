#include <iostream>
#include <time.h>
#include "graph.h"
using namespace std;

int main() {
    srand(time(NULL));
    Graph G ("list.txt");
    G.percolate_graphs_Ham();
    
    return 0;
}