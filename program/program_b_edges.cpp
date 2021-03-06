#include <iostream>
#include <time.h>
#include "../src/graph.h"
#include "../src/grid.h"
using namespace std;

int main() {
    srand(time(NULL));
    cout << "This program will percolate a grid by edge " << endl;
    cout << "Introduce the grid size (NxN): " << endl;
    int N;
    cin >> N;
    Grid G(N);
    
    cout << "Introduce value of q ∈ [0,1]: " << endl;
    double q;
    cin >> q;
    G.percolateByEdges(q);
    G.print();

    if (G.propiedad()) cout << endl << "Top and bottom are connected" << endl;
    else  cout << endl << "Top and bottom are not connected" << endl;
    return 0;
}
