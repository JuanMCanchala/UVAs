#include <bits/stdc++.h>
using namespace std;

struct Arista {
    int u, v, peso;

    Arista() {}

    Arista(int x, int y, int p) {
        u = x;
        v = y;
        peso = p;
    }

    bool operator<(Arista& a) {
        return peso < a.peso;
    }
};

int n, m, total;
vector<Arista> aristas;
vector<int> idArbol(50000);
vector<Arista> mst;
vector<bool> valid, used;

void kruskal(bool flag) {
    total = 0;
    mst.clear();
    for (int i = 0; i <= n; ++i) idArbol[i] = i;

    sort(aristas.begin(), aristas.end());

    for (int i = 0; i < aristas.size(); ++i) {
        bool isValid = valid[i]; 

        if (isValid) {
            int u = aristas[i].u;
            int v = aristas[i].v;

            if (idArbol[u] != idArbol[v]) {
                mst.push_back(aristas[i]);
                total += aristas[i].peso;

                if (flag) used[i] = true;

                int p1 = idArbol[u];
                int p2 = idArbol[v];
                for (int j = 0; j <= n; ++j) {
                    if (idArbol[j] == p2) idArbol[j] = p1;
                }
            }
        }
    }
}

int secondMinimum() {
    int mn = INT_MAX, tempTotal;
    for (int i = 0; i < m; ++i) {
        if (used[i]) {
            valid[i] = false;
            kruskal(false);
            tempTotal = mst.size() == n - 1 ? total : INT_MAX;
            if (tempTotal < mn) mn = tempTotal;
            valid[i] = true;
        }
    }
    return mn;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> m;
        aristas.clear();
        valid.assign(m, true);
        used.assign(m, false);

        for (int i = 0; i < m; ++i) {
            int u, v, peso;
            cin >> u >> v >> peso;
            aristas.push_back(Arista(u, v, peso));
        }

        kruskal(true);
        int x = mst.size() == n - 1 ? total : INT_MAX;
        int y = secondMinimum();

        cout << x << " " << y << endl;
    }

    return 0;
}
