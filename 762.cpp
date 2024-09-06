#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
using namespace std;

void bfs(int n, string &c1, string &c2, map<string, vector<string> > &grafo){
map<string, string> parent;
bool encontrado = false;
queue<string> q;
for(int i = 0;  i < n; i++){
    cin >> c1 >> c2;
    grafo[c1].push_back(c2);
    grafo[c2].push_back(c1);
}
cin >> c1 >> c2;

q.push(c1);
};

int main(){
int n, c = 0;
string c1, c2, city;
while(cin >> n){
map<string, vector<string> > grafo;

}

    return 0;
}