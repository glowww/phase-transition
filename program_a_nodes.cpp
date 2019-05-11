#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

int main() {
    srand(time(NULL));
    cout << "This program will percolate by nodes a graph" << endl;
    cout << "Introduce number of nodes: " << endl;
    int N;
    cin >> N;
    Graph G(N);
    
    cout << "Introduce value of q: " << endl;
    float q;
    cin >> q;
    G.percolateByNodes(q);
    G.print();

    return 0;
}
