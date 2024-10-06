#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    int i, j, k, u;

    while (cin >> s) {
        vector<string> words;
        string ans;
        vector<vector<int> > graph(27);
        vector<int> deegre(27, -1);
        vector<int> visits(27);
        words.push_back(s);
        while (cin >> s && s != "#") {
            words.push_back(s);
        }

        for (i = 0; i < words.size(); i++) {
            for (j = i + 1; j < words.size(); j++) {
                k = 0;
                while (k < words[i].size() && k < words[j].size() &&
                    words[i][k] != words[j][k]) {
                    k++;
                }
                if (k != words[i].size() && k != words[j].size()) {
                    graph[words[i][k] - 'A'].push_back(words[j][k] - 'A');
                    if (deegre[words[j][k] - 'A'] == -1) {
                        deegre[words[j][k] - 'A'] = 0;
                    }
                    deegre[words[j][k] - 'A']++;
                }
            }
        }

        queue<int> q;
        for (i = 0; i < 27; i++) {
            if (!deegre[i]) {
                q.push(i);
                visits[i] = 1;
            }
        }

        while (!q.empty()) {
            u = q.front();
            q.pop();
            ans += (u + 'A');

            for (i = 0; i < graph[u].size(); i++) {
                if (!visits[graph[u][i]]) {
                    deegre[graph[u][i]]--;
                    if (!deegre[graph[u][i]]) {
                        q.push(graph[u][i]);
                        visits[graph[u][i]] = 1;
                    }
                }
            }
        }

        cout << ans << endl;

        return 0;
    }
}