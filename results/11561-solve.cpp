//
// Profesor: Carlos Ramirez
// Codigo: 8983809
// Estudiante: Juan Manuel Canchala 
// Complejidad: 
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Coordenada {
    int x, y;
};

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool esSeguro(int x, int y, vector<vector<char> >& matriz, vector<vector<bool> >& visitados, int W, int H) {
    bool ans = false;
    if (x >= 0 && x < H && y >= 0 && y < W && matriz[x][y] != '#' && !visitados[x][y]) {
        ans = true;
    }
    return ans;
}

int bfs(int coordX, int coordY, vector<vector<char> >& matriz, vector<vector<bool> >& visitados, int W, int H) {
    queue<Coordenada> q;
    Coordenada inicio; 
    inicio.x = coordX;
    inicio.y = coordY;
    q.push(inicio);
    visitados[coordX][coordY] = true;
    int numGemas = 0;

    while (!q.empty()) {
        Coordenada p = q.front(); 
        q.pop();
        bool trampa = false;

        for (int i = 0; i < 4 && !trampa; i++) {
            int x = p.x + dr[i];
            int y = p.y + dc[i];
            if (esSeguro(x, y, matriz, visitados, W, H) && matriz[x][y] == 'T') {
                trampa = true;
            }
        }

        if (!trampa) {
            for (int i = 0; i < 4; i++) {
                int x = p.x + dr[i];
                int y = p.y + dc[i];
                if (esSeguro(x, y, matriz, visitados, W, H) && matriz[x][y] != 'T') {
                    visitados[x][y] = true;
                    Coordenada nuevoP;
                    nuevoP.x = x;
                    nuevoP.y = y;
                    q.push(nuevoP);
                    if (matriz[x][y] == 'G') {
                        numGemas++;
                    }
                }
            }
        }
    }

    return numGemas;
}

int main() {
    int W, H;
    
    while (cin >> W >> H) {
        vector<vector<char> > matriz(H, vector<char>(W));
        vector<vector<bool> > visitados(H, vector<bool>(W));

        Coordenada nodo;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> matriz[i][j];
                if (matriz[i][j] == 'P') {
                    nodo.x = i;
                    nodo.y = j;
                }
            }
        }
        int ans = bfs(nodo.x, nodo.y, matriz, visitados, W, H);

        cout << ans << endl;
    }
    return 0;
}
