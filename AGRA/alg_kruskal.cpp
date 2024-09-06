// libro de uva

//algoritmo de kruskal para construir un MST

#include <iostream>
#include <vector>
#include <algorithm> // Para sort()

using namespace std;

typedef pair<int, int> ii; // Par de enteros (para los vértices)
typedef vector<pair<int, ii>> EdgeList; // Lista de aristas (peso, (u, v))

// Clase para la estructura Union-Find (o Disjoint Set Union, DSU)
class UnionFind {
private:
    vector<int> parent, rank; // Estructuras para almacenar los padres y las alturas

public:
    // Constructor: Inicializa el conjunto disjunto
    UnionFind(int N) {
        parent.assign(N, 0);
        rank.assign(N, 0);
        for (int i = 0; i < N; i++) parent[i] = i;
    }

    // Encuentra el representante del conjunto de x
    int findSet(int i) {
        if (parent[i] == i) return i;
        else return parent[i] = findSet(parent[i]); // Compresión de caminos
    }

    // Determina si dos elementos están en el mismo conjunto
    bool isSameSet(int i, int j) {
        return findSet(i) == findSet(j);
    }

    // Une dos conjuntos
    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            int x = findSet(i), y = findSet(j);
            // Union by rank
            if (rank[x] > rank[y]) parent[y] = x;
            else {
                parent[x] = y;
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }
};

int main() {
    int V, E; // Vértices y aristas
    scanf("%d %d", &V, &E);

    EdgeList edgeList; // Lista de aristas en el formato (peso, (u, v))

    // Leer las aristas del grafo
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w); // (u, v, w) = (vértice u, vértice v, peso w)
        edgeList.push_back(make_pair(w, ii(u, v))); // Añadir la arista
    }

    // Ordenar las aristas por peso en orden ascendente (O(E log E))
    sort(edgeList.begin(), edgeList.end());

    // Inicializar el costo del MST y el número de aristas tomadas
    int mst_cost = 0, num_taken = 0;

    // Inicializar Union-Find (Disjoint Set Union)
    UnionFind UF(V); // Crear un conjunto disjunto con V elementos

    // Iterar sobre las aristas ordenadas
    for (int i = 0; i < E && num_taken < V - 1; i++) {
        pair<int, ii> front = edgeList[i]; // La arista más ligera no tomada

        // Si los vértices de la arista no están en el mismo conjunto
        if (!UF.isSameSet(front.second.first, front.second.second)) {
            num_taken++; // Tomar la arista en el MST
            mst_cost += front.first; // Añadir el peso al costo total del MST
            UF.unionSet(front.second.first, front.second.second); // Unir los conjuntos
        }
    }

    // Imprimir el costo total del MST
    printf("MST cost = %d (Kruskal's)\n", mst_cost);

    return 0;
}
