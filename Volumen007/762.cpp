#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int n, c = 0;
    string c1, c2, city;

    while (cin >> n) {
        map<string, vector<string> > graph;
        map<string, bool> visited;
        map<string, string> parent;
        stack<pair<string, string> > route;
        bool found = false;
        queue<string> q;
        c++;

        for (int i = 0; i < n; i++) {
            cin >> c1 >> c2;
            graph[c1].push_back(c2);
            graph[c2].push_back(c1);
        }

        cin >> c1 >> c2;

        q.push(c1);
        visited[c1] = true;

        while (!q.empty() && !found) {
            city = q.front();
            q.pop();

            if (city == c2) {
                found = true;
            } else {
                for (int i = 0; i < graph[city].size(); i++) {
                    string s = graph[city][i];
                    if (!visited[s]) {
                        visited[s] = true;
                        q.push(s);
                        parent[s] = city;
                    }
                }
            }
        }

        if (c > 1) cout << endl;

        if (!found)
            cout << "No route" << endl;
        else {
            while (c2 != c1) {
                route.push(make_pair(parent[c2], c2));
                c2 = parent[c2];
            }

            while (!route.empty()) {
                cout << route.top().first << " " << route.top().second << endl;
                route.pop();
            }
        }
    }

    return 0;
}
