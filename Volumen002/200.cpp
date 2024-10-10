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
        vector<int> deegre(27, 0);  
        vector<int> visits(27, 0);  
        words.push_back(s);
        
        while (cin >> s && s != "#") {
            words.push_back(s);
        }

        for (i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];
            k = 0;
            while (k < word1.size() && k < word2.size() && word1[k] == word2[k]) {
                k++;
            }
            if (k < word1.size() && k < word2.size()) {
                graph[word1[k] - 'A'].push_back(word2[k] - 'A');
                deegre[word2[k] - 'A']++;
            }
        }

        queue<int> q;
        for (i = 0; i < 27; i++) {
            if (deegre[i] == 0 && !graph[i].empty()) {
                q.push(i);
                visits[i] = 1;
            }
        }

        while (!q.empty()) {
            u = q.front();
            q.pop();
            ans += (u + 'A');  

            for (i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                deegre[v]--;
                if (deegre[v] == 0 && !visits[v]) {
                    q.push(v);
                    visits[v] = 1;
                }
            }
        }

        cout << ans << endl;  
    }
    
    return 0;
}
