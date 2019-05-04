#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

void testByEdges(){
  vector<int> v;
  for(double i = 0.46; i <= .54; i += 0.001){
    int times = 0;
    for(int j = 0; j < 100; j++){
      Grid g(100);
      g.percolateByEdges(i);
      if (g.propiedad()) times++;
    }
    v.push_back(times);
  }

  double j = 0.46;
  for(int i = 0; i < v.size(); i++){
    cout << j << "  " << v[i] << endl;
    j+=0.001;
  }
}

void testByNodes(){
  vector<int> v;
  for(double i = 0.36; i <= .45; i += 0.001){
    int times = 0;
    for(int j = 0; j < 100; j++){
      Grid g(100);
      g.percolateByNodes(i);
      if (g.propiedad()) times++;
    }
    v.push_back(times);
  }

  double j = 0.36;
  for(int i = 0; i < v.size(); i++){
    cout << j << "  " << v[i] << endl;
    j+=0.001;
  }
}

int main() {
    srand(time(NULL));

    //testByEdges();
    testByNodes();
    
    return 0;
}