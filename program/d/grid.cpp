#include "grid.h"

Grid::Grid(int N){
    size = N;

    // Todas las casillas son accesibles y
    // ellas son su propio representante
    for(int i = 0; i < size; i++){
        vector<Node> v;
        for(int j = 0; j < size; j++){
            bool right = (j < size-1);
            bool bottom = (i < size-1);
            pair<int, int> parent = make_pair(i,j);
            v.push_back(Node(right, bottom, parent));
        }
        G.push_back(v);
    }	
}

void Grid::percolateByNodes(double Q){

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            double random = (double)rand()/((double)RAND_MAX + 1);

            if(random <= Q){
                G[i][j].percolate();
            }
        }
    } 
    
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if (G[i][j].get()){
				if (i<size-1){
					if (G[i+1][j].get()) unionUF(make_pair(i,j),make_pair(i+1,j));
				}
				if (j<size-1){
					if (G[i][j+1].get()) unionUF(make_pair(i,j),make_pair(i,j+1));
				}
			}
		}
	}
}

void Grid::percolateByEdges(double Q){

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

	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if (G[i][j].get()){
				if (G[i][j].getBottom()){
					unionUF(make_pair(i,j),make_pair(i+1,j));
				}
				if (G[i][j].getRight()){
					unionUF(make_pair(i,j),make_pair(i,j+1));
				}
			}
		}
	}
}

pair<int,int> Grid::findUF(pair<int,int> id){
    
    pair<int,int> rep = G[id.first][id.second].getParent();
    // Es el representante
    if (rep == id) return id;
    // Seguir buscando hasta encontrar el representante
    else return findUF(rep); 
}

void Grid::unionUF(pair<int,int> id1, pair<int,int> id2){
    pair<int,int> rep1 = findUF(id1);
    pair<int,int> rep2 = findUF(id2);
    if (rep1 != rep2){
        // El padre será el que esté en la fila más alta
        if (rep1.first <= rep2.first) G[rep2.first][rep2.second].setParent(rep1); 
        else G[rep1.first][rep1.second].setParent(rep2); 
    }
}

bool Grid::propiedad(){
	
	for(int i=0; i<size; i++){
        // Miro todos los sets que hay en la primera fila
		pair<int,int> rep1 = findUF(make_pair(0,i)); 
		for(int j=0; j<size; j++){
            // Miro todos los sets que tiene la ultima fila
			pair<int,int> rep2 = findUF(make_pair(size-1,j)); 

            // Si alguno de la primera y ultima coinciden, se cumple
			if (rep1 == rep2) return true; 
		}
	}

	return false;
}

void Grid::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            G[i][j].print();
        }
        cout << endl;
    }
}
