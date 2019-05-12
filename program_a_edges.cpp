#include <iostream>
#include <time.h>
#include "graph.h"
using namespace std;

int main() {
    srand(time(NULL));
    cout << "This program will percolate a graph by edges" << endl;
    cout << "Introduce number of nodes: " << endl;
    int N;
    cin >> N;
    Graph G(N);
    
    cout << "Introduce value of q ∈ [0,1]: " << endl;
    float q;
    cin >> q;
    G.percolateByEdges(q);
    G.print();

    return 0;
}
