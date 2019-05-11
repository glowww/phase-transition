#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

int main() {
    srand(time(NULL));
    cout << "This program will percolate by edges a graph" << endl;
    cout << "Introduce number of nodes: " << endl;
    int N;
    cin >> N;
    Graph G(N);
    
    cout << "Introduce value of q: " << endl;
    float q;
    cin >> q;
    G.percolateByEdges(q);
    G.print();

    return 0;
}
