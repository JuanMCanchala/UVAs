//arreglar la eficiencia del codigo
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int numInversiones(string& s) {
    int inversions = 0;
    int n = s.length();

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (s[i] > s[j]) {
                inversions++;
            }
        }
    }

    return inversions;
}

bool comparacionesStr(pair<string, int>& p1, pair<string, int>& p2) {
    int inversiones_p1 = numInversiones(p1.first);
    int inversiones_p2 = numInversiones(p2.first);

    if (inversiones_p1 != inversiones_p2) {
        return inversiones_p1 < inversiones_p2;
    } else {
        return p1.second < p2.second;
    }
}

int main() {
    int M;
    cin >> M;

    for (int j = 0; j < M; ++j) {
        int n, m;
        cin >> n >> m;

        vector<pair<string, int> > strYindice(m);

        for (int i = 0; i < m; ++i) {
            cin >> strYindice[i].first;
            strYindice[i].second = i;
        }

        sort(strYindice.begin(), strYindice.end(), comparacionesStr);

        for (int i = 0; i < strYindice.size(); ++i) {
            cout << strYindice[i].first << endl;
        }

        if (j < M - 1) {
            cout << endl;
        }
    }

    return 0;
}
