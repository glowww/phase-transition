#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

int main() {
    srand(time(NULL));
    Graph G ("list.txt");
    G.percolateBFS();
    
    return 0;
}