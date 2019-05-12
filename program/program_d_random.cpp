#include <iostream>
#include <time.h>
#include "../src/graph.h"
using namespace std;

int main() {
    srand(time(NULL));
    Graph G ("list.txt");
    G.percolate_graphs_Ham();
    G.print();
    
    return 0;
}