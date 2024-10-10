//dominator
/*
ejecutamos dfs en el nodo 0 para determinar que vertices son alcanzables desde el 0, depues comprobamos que vertices estan dominados por X, desactivamos temporalmente todas las aristas saliendo de dicho vertice X y vovlvemos a ejecutar dfs(0)
*/
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> >& graph, vector<int>& visits, int node) {
    visits[node] = 1; 
    for (int i = 0; i < graph.size(); i++) {
        if (graph[node][i] == 1 && visits[i] == 0) {
            dfs(graph, visits, i); 
        }
    }
}

void ans(int caso, int size, vector<vector<int> >& G) {

    vector<int> alcanzables_iniciales(size, 0);

    dfs(G, alcanzables_iniciales, 0);

    vector<vector<int> > matriz_dominator(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        if (alcanzables_iniciales[i])
            matriz_dominator[0][i] = 1;
    }

    for (int nodo_a_desactivar = 1; nodo_a_desactivar < size; nodo_a_desactivar++) {
        vector<int> visits(size, 0);

        vector<vector<int> > grafo_temporal = G;
        for (int i = 0; i < size; i++) {
            grafo_temporal[nodo_a_desactivar][i] = 0;
        }

        dfs(grafo_temporal, visits, 0);

        for (int i = 0; i < size; i++) {
            if (alcanzables_iniciales[i] && visits[i] == 0)
                matriz_dominator[nodo_a_desactivar][i] = 1;
        }

        matriz_dominator[nodo_a_desactivar][nodo_a_desactivar] = 1;
    }

    cout << "Case " << caso << ":" << endl;

    cout << "+";
    for (int i = 0; i < size * 2 - 1; i++) {
        cout << "-";
    }
    cout << "+" << endl;

    for (int i = 0; i < size; i++) {
        cout << "|";
        for (int j = 0; j < size; j++) {
            if (matriz_dominator[i][j] == 1) {
                cout << "Y";
            } else {
                cout << "N";
            }
            if (j < size - 1) {
                cout << "|";
            }
        }
        cout << "|" << endl;

        cout << "+";
        for (int k = 0; k < size * 2 - 1; k++) {
            cout << "-";
        }
        cout << "+" << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int size;
        cin >> size;

        vector<vector<int> > G(size, vector<int>(size, 0));
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cin >> G[i][j];
            }
        }

        ans(i, size, G);
    }
    return 0;
}
