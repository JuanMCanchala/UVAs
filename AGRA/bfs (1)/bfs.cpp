#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;
void bfs(int init, int finish, vector<vector<int>>&graph){
    
    vector<int>visits(0, graph.size());
    queue<int>q;
    q.push(init);
    visits[init] = 1;
    int i, node = init;

    while(!q.empty() && node!=finish){

        node = q.front();
        q.pop();
        for(i = 0; i<graph[node].size(); i++){
            if(!visits[graph[node][i]]){
                visits[graph[node][i]] = 1;
                q.push(graph[node][i]); 
            }
        }
    }

}

void dfs(vector<vector<int>>&graph, vector<int>&visits, int node, int finish){

    visits[node] = 1;
    int i;

    for(i = 0; i<graph[node].size(); i++){
            if(!visits[graph[node][i]]){
                dfs(graph, visits, graph[node][i], finish);
            }
        }
    
}
int main(){


    return 0;
}
