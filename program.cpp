#include <iostream>
#include <time.h>
#include "graph.h"
#include "grid.h"
using namespace std;

void testByEdges(){

  cout << "Calculating..." << endl;
  
  clock_t t = clock();

  vector<int> v;
  for(double i = 0.0; i <= 1; i += 0.001){
    int times = 0;
    for(int j = 0; j < 100; j++){
      Grid g(100);
      g.percolateByEdges(i);
      if (g.propiedad()) times++;
    }
    v.push_back(times);
  }

  t = clock() - t;

  double j = 0.0;
  for(int i = 0; i < v.size(); i++){
    cout << j << "  " << v[i] << endl;
    j+=0.001;
  }

  cout << "It took " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;
}

void testByNodes(){

  cout << "Calculating..." << endl;
  
  clock_t t = clock();

  vector<int> v;
  for(double i = 0.0; i <= 1; i += 0.001){
    int times = 0;
    for(int j = 0; j < 100; j++){
      Grid g(100);
      g.percolateByNodes(i);
      if (g.propiedad()) times++;
    }
    v.push_back(times);
  }

  t = clock() - t;

  double j = 0.0;
  for(int i = 0; i < v.size(); i++){
    cout << j << "  " << v[i] << endl;
    j+=0.001;
  }

  cout << "It took " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;
}

void testHamiltonianCycle(bool site){

  cout << "Calculating..." << endl;
  
  clock_t t = clock();

  vector<int> v;  
  for(double i = 0.0; i <= 1; i += 0.01){
    int times = 0;
    for(int j = 0; j < 100; j++){
      Graph g(20);

      if(site) g.percolateByNodes(i);
      else g.percolateByEdges(i);

      if (g.hamCycle()) times++;
    }
    v.push_back(times);
  }

  t = clock() - t;

  double j = 0.0;
  for(int i = 0; i < v.size(); i++){
    cout << j << "  " << v[i] << endl;
    j+=0.01;
  }

  cout << "It took " << t << " clicks (" << ((float)t)/CLOCKS_PER_SEC << " seconds)" << endl;
}

int main() {
    srand(time(NULL));
    //Graph G ("test.adjlist");
    //G.printGraphAdj();
    //testByEdges();
    //testByNodes();

    testHamiltonianCycle(false);
    
    
    return 0;
}