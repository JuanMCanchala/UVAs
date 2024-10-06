#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> >& graph, vector<bool>& visiteds, int node, stack<int>& result) {
    visiteds[node] = true;
    for (int j = 0; j < graph[node].size(); j++) {
        int u = graph[node][j];
        if (!visiteds[u]) {
            dfs(graph, visiteds, u, result);
        }
    }
    result.push(node); 
}

void ot(vector<vector<int> >& graph, int n) {
    vector<bool> visiteds(n + 1, false); 
    stack<int> result;

    for (int i = 1; i <= n; i++) {
        if (!visiteds[i]) {
            dfs(graph, visiteds, i, result);
        }
    }
    bool first = true; 
    while (!result.empty()) {
        if (!first) {
            cout << " "; 
        }
        cout << result.top();
        result.pop();
        first = false; 
    }
    cout << endl; 
}

int main() {
    int numTask, relations;

    while (cin >> numTask >> relations && !(numTask == 0 && relations == 0)) {
        vector<vector<int> > graph(numTask + 1); 

        for (int i = 0; i < relations; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        ot(graph, numTask);
    }

    return 0;
}
