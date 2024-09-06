#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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