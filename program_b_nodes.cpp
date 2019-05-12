#include <iostream>
#include <time.h>
#include "grid.h"
using namespace std;

int main() {
    srand(time(NULL));
    cout << "This program will percolate by nodes a grid" << endl;
    cout << "Introduce the grid size (NxN): " << endl;
    int N;
    cin >> N;
    Grid G(N);
    
    cout << "Introduce value of q ∈ [0,1]: " << endl;
    double q;
    cin >> q;
    G.percolateByNodes(q);
    G.print();
    
    if (G.propiedad()) cout << endl << "Top and bottom are connected" << endl;
    else  cout << endl << "Top and bottom are not connected" << endl;
    return 0;
}
