//
// Profesor: Carlos Ramirez
// Codigo: 8983809
// Estudiante: Juan Manuel Canchala 
// Complejidad: 
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

// estos dos arreglos son extremadamente utiles para recorrer las adyacentes de una posiion en la matriz en un unico ciclo 
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};

struct Resultado {
    char letra;
    int conexiones;
};

bool comparar(Resultado &a, Resultado &b){
    bool ans;
    if (a.conexiones > b.conexiones){
        ans = true;
    } else if (a.conexiones == b.conexiones){
        ans = a.letra < b.letra;
    } else {
        ans = false;
    }
    return ans;
}

struct Coordenada {
    int x, y;
};

//habia que cmabiar el bfs o el dfs para adapatarlo al problema
void bfs(int fila, int columna, char letra, vector<vector<char> > &matriz, vector<vector<bool> > &visitado){
    int high = matriz.size();
    int width = matriz[0].size();
    
    queue<Coordenada> q;
    Coordenada start = {fila, columna};
    q.push(start);
    visitado[fila][columna] = true;

    while (!q.empty()){
        Coordenada nodo = q.front();
        q.pop();
        int x = nodo.x;
        int y = nodo.y;

        for (int i = 0; i < 4; i++) {
            int newFila = x + dr[i];
            int newColumna = y + dc[i];
            //verificacion para que no halla sehmentation fault
            if (newFila >= 0 && newFila < high && newColumna >= 0 && newColumna < width && !visitado[newFila][newColumna] && matriz[newFila][newColumna] == letra){
                visitado[newFila][newColumna] = true;
                Coordenada sig = {newFila, newColumna};
                q.push(sig);
            }
        }
    }
}
int main() {
    int numCasos;
    cin >> numCasos;

    for (int k = 0; k < numCasos; k++) {
        int high, width;
        cin >> high >> width;
        
        //ambas matrices las inicializo del tamaño de highy width y para vistado la lleno de falses por defecto
        //para guardar la matriz
        vector<vector<char> > matriz(high, vector<char>(width));
        //para cada celda de la matriz verificar si no fue verificado
        vector<vector<bool> > visitado(high, vector<bool>(width));
        
        for(int i = 0; i < high; i++){
            for(int j = 0; j < width; j++){
                cin >> matriz[i][j];
            }
        }
        // se usa para saber cuantas areas conextadas hay
        map<char, int> contador;

        for(int i = 0; i < high; i++){
            for(int j = 0; j < width; j++){
                if (!visitado[i][j]) {
                    contador[matriz[i][j]]++;
                    bfs(i, j, matriz[i][j], matriz, visitado);
                }
            }
        }

        vector<Resultado> resultados;
        for(map<char, int>::iterator it = contador.begin(); it != contador.end(); ++it){
            Resultado resultado;
            resultado.letra = it->first;
            resultado.conexiones = it->second;
            resultados.push_back(resultado);
        }

        sort(resultados.begin(), resultados.end(), comparar);

        cout << "World #" << k + 1 << endl;
        for(int i = 0; i < resultados.size(); i++){
            cout << resultados[i].letra << ": " << resultados[i].conexiones << endl;
        }
    }

    return 0;
}
