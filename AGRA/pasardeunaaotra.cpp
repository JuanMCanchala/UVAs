#include <iostream>
#include <vector>

using namespace std;

//MATRICES A LISTAS DE ADYACENCIA
int main() {
    
    vector<vector<int>> matrix = {
        {0, 1, 1, 0}, 
        {0, 0, 1, 0}, 
        {1, 0, 0, 1}, 
        {0, 0, 0, 0}  
    };

    int n = matrix.size(); 
    vector<vector<int>> adj(n); 

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                adj[i].push_back(j); 
            }
        }
    }

    return 0;
}

// LISTAS DE ADYACENCIA A MATRICES
int main() {

    vector<vector<int>> adj = {
        {1, 2},       
        {2},    
        {0, 3},      
        {}         
    };

    int n = adj.size(); 
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < adj[u].size(); v++) {
            matrix[u][adj[u][v]] = 1; 
        }
    }

    return 0;
}

// LISTA DE ARISTAS A LISTAS DE ADYACENCIA
int main() {

    vector<pair<int, int>> edges = {
        {0, 1}, 
        {0, 2},  
        {1, 2},  
        {2, 0},  
        {2, 3}  
    };

    int n = 4; 
    vector<vector<int>> adj(n); 

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
    }

    return 0;
}

//LISTAS DE ADYACENCIA A ARISTAS

int main() {
    vector<vector<int>> adj = {
        {1, 2},       
        {2},         
        {0, 3},       
        {}            
    };

    vector<pair<int, int>> edges; 

    for (int u = 0; u < adj.size(); u++) {
        for (int v = 0; v < adj[u].size(); v++) {
            edges.push_back(make_pair(u, adj[u][v]));
        }
    }

    return 0;
}

//LISTA DE ARISTAS A MATRIZ

int main() {

    vector<pair<int, int>> edges = {
        {0, 1},  
        {0, 2}, 
        {1, 2},  
        {2, 0},  
        {2, 3}   
    };

    int n = 4; 
    vector<vector<int>> matrix(n, vector<int>(n, 0)); 

    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        matrix[u][v] = 1; 
    }

    return 0; 
}

//MATRIZ A LISTA DE ARISTAS

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 1, 0}, 
        {0, 0, 1, 0}, 
        {1, 0, 0, 1}, 
        {0, 0, 0, 0}  
    };

    int n = matrix.size(); 
    vector<pair<int, int>> edges; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                edges.push_back(make_pair(i, j)); 
            }
        }
    }

    return 0;
}