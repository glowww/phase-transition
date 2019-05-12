#include <iostream>
#include <time.h>
#include "grid.h"
using namespace std;

int main() {
    srand(time(NULL));
    cout << "This program will percolate by edges a grid" << endl;
    cout << "Introduce lenght of the grid (grid will have size lenght x lenght): " << endl;
    int N;
    cin >> N;
    Grid G(N);
    
    cout << "Introduce value of q: " << endl;
    double q;
    cin >> q;
    G.percolateByEdges(q);
    G.print();

    if (G.propiedad()) cout << endl << "Top and bottom are connected" << endl;
    else  cout << endl << "Top and bottom are not connected" << endl;
    return 0;
}
