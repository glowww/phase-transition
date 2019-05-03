#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

int main() {

    Grid g(10);
    g.percolateByEdges(.5);
    //g.percolateByNodes(.5);
    g.print();

	  if (g.propiedad()) cout << "se cumple" << endl;
		else cout << "no" << endl;
    
    return 0;
}