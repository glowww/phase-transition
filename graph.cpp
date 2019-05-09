#include "graph.h"

Graph::Graph(int N){
    size = N;

    vector<bool> v(size, false);
    emptyRow = v;

    //vector<vector<bool>> vec(size, vector<bool> (size, true));

    for(int i = 0; i < size; i++){
        vector<bool> v(size, true);
        G.push_back(v);
        G[i][i] = false;
    }
    
}

Graph::Graph(string file){
    string line;
    int fixeIndex, node;
    ifstream graphFile(file);
    if (graphFile.is_open()) {
        for (int i = 0; i < 3; i++)
            getline(graphFile,line);
        while (getline(graphFile,line)) {
            istringstream iss(line);
            iss >> fixeIndex;
            GraphAdj[fixeIndex];
            list<int> l;
            while (iss >> node) {
                l.push_back(node);
                // GraphAdj[fixeIndex].push_back(node);
                // GraphAdj[node].push_back(fixeIndex);
            }
            GraphAdj.push_back(l);
        }
        size = GraphAdj.size();
        graphFile.close();
    }
    else cout << "Unable to open file"; 
}

void Graph::removeRow(int i){
    G[i] = emptyRow;
}

void Graph::removeColumn(int i){
    for(int j = 0; j < size; j++){
        G[j][i] = false;
    }
}

void Graph::percolateByNodes(double Q){

    for(int i = 0; i < size; i++){
        double random = (double)rand()/((double)RAND_MAX + 1);

        if(random <= Q){
            removeRow(i);
            removeColumn(i);
        }
    } 
    
}

void Graph::percolateByEdges(double Q){

    for(int i = 1; i < size; i++){
        for(int j = 0; j < i; j++){
            double random = (double)rand()/((double)RAND_MAX + 1);

            if(random <= Q){
                G[i][j] = false;
                G[j][i] = false;
            }
        }
    } 

}

void Graph::print(){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            cout << G[i][j];
        }
        cout << endl;
    }
}

void Graph::printGraphAdj() {
    for (int i = 0; i < size; i++) {
        cout << i << " -> ";
        for (list<int>::iterator it = GraphAdj[i].begin(); it != GraphAdj[i].end(); it++)
            cout << *it << " ";
        cout << endl;
    }
}


void Graph::discardNodesGraphAdj(double Q){
    cout << Q << endl;
    /*
    srand(time(NULL));
    for(int i = 0; i < size; i++){
        double random = (double)rand()/((double)RAND_MAX + 1);
        if(random <= Q){
             for(int j = 0; j < size; j++){
                    GraphAdj[i][j] = 0;
             }
             for(int j = 0; j < size; j++){
                    GraphAdj[j][i] = 0;
             }
        }
    } 
    */
}

bool Graph::isSafe(int v, int path[], int pos){
    
    if (G[path[pos-1]][v] == 0){
        return false;
    }
        
    for (int i = 0; i < pos; i++){
       if (path[i] == v) return false;
    }
        
    return true;
}

bool Graph::hamCycleRec(int path[], int pos){

    if (pos == size){
        return (G[ path[pos-1] ][ path[0] ] == 1);
    }
 
    for (int v = 1; v < size; v++){
        
        if (isSafe(v, path, pos)){
            path[pos] = v;
            if (hamCycleRec(path, pos+1)){
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}
 

bool Graph::hamCycle(){
    int *path = new int[size];
    for (int i = 0; i < size; i++){
        path[i] = -1;
    }

    path[0] = 0;
    return hamCycleRec(path, 1);
}