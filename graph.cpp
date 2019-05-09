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
    int number_of_graphs, sizeGraphAdj;

    string line;
    int fixeIndex, node;
    ifstream graphFile(file);
    if (graphFile.is_open()) {

        getline(graphFile,line);
        istringstream iss(line);
        iss >> number_of_graphs;
        iss >> sizeGraphAdj;

        for (int j = 0; j < number_of_graphs; j++) {
            GraphAdj = vector<vector<int> > (sizeGraphAdj, vector<int> (sizeGraphAdj, 0));
            for (int i = 0; i < sizeGraphAdj; i++) {
                getline(graphFile,line);
                istringstream iss(line);
                iss >> fixeIndex;
                while (iss >> node) {
                    GraphAdj[fixeIndex][node] = 1;
                    GraphAdj[node][fixeIndex] = 1;
                }
            }
            getline(graphFile,line);
            Graphs.push_back(GraphAdj);
        }
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

    srand(time(NULL));

    for(int i = 0; i < size; i++){
        double random = (double)rand()/((double)RAND_MAX + 1);

        if(random <= Q){
            removeRow(i);
            removeColumn(i);
        }
    }
}

void Graph::percolateByEdges(double Q){

    srand(time(NULL));

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
    for (int k = 0; k < Graphs.size(); k++) {
        for (int i = 0; i < Graphs[k].size(); ++i) {
            cout << i << " -> ";
            for (int j = 0; j < Graphs[k][i].size(); ++j)
                cout << Graphs[k][i][j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}

void Graph::discardNodesGraphAdj(double Q){
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
}
