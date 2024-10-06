#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int INF = -1;

bool esBipartito(map<int, vector<int> >& graph, int numNodos){
    queue<int> q;
    vector<int> color(numNodos+1, INF);
    bool esBipartito = true;

    for(int i = 0; i < numNodos && esBipartito; i++){
        if(color[i] == INF){
            color[i] = 0;  
            q.push(i);
        }
        while(!q.empty() && esBipartito){
            int u = q.front();
            q.pop();
            for(int j = 0; j < graph[u].size(); j++){
                int v = graph[u][j];
                if (color[v] == INF) {
                    color[v] = !color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    esBipartito = false;
                }
            }
        }
    }
    return esBipartito;
}

int main(){

    int numNodos;
    cin >> numNodos;
    while(numNodos != 0){
        int u, v;
        map<int, vector<int> > graph;
        while(cin >> u >> v && (u != 0 && v != 0)){
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if(esBipartito(graph, numNodos)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        cin >> numNodos; 
    }

    return 0;
}
