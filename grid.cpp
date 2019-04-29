#include "grid.h"

Grid::Grid(int N){
    size = N;

    for(int i = 0; i < size; i++){
        vector<Node> v;
        for(int j = 0; j < size; j++){
            bool right = (j < size-1);
            bool bottom = (i < size-1);
            v.push_back(Node(right, bottom));
        }
        G.push_back(v);
    }
}

void Grid::percolateByNodes(double Q){

    srand(time(NULL));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            double random = (double)rand()/((double)RAND_MAX + 1);

            if(random <= Q){
                G[i][j].percolate();
            }
        }
    } 
}

void Grid::percolateByEdges(double Q){

    srand(time(NULL));

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            double random = (double)rand()/((double)RAND_MAX + 1);

            if(random <= Q){
                G[i][j].percolateRightEdge();
            }

            random = (double)rand()/((double)RAND_MAX + 1);
            if(random <= Q){
                G[i][j].percolateBottomEdge();
            }
        }
    } 

}

void Grid::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            G[i][j].print();
        }
        cout << endl;
    }
}