#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, Case = 0;
    
    cin >> t;
    
    while (t--) {
        cout << "Case #" << ++Case << ":\n";
        
        vector<int> A(3);  // Cantidad de problemas resueltos por cada amigo
        vector<vector<int>> B(3);  // Listas de problemas resueltos por cada amigo
        vector<int> mark(10001, 0);  // Array para marcar cuántos amigos resolvieron cada problema
        
        // Leer las listas de problemas resueltos por cada amigo
        for (int i = 0; i < 3; i++) {
            cin >> A[i];  // Leer cuántos problemas resolvió el amigo i
            B[i].resize(A[i]);  // Redimensionar el vector B[i] según la cantidad de problemas
            for (int j = 0; j < A[i]; j++) {
                cin >> B[i][j];  // Leer cada problema resuelto
                mark[B[i][j]]++;  // Incrementar el contador de cuántos amigos resolvieron este problema
            }
            // Ordenar la lista de problemas resueltos por este amigo
            sort(B[i].begin(), B[i].end());
        }
        
        int maxUnique = 0;  // Máximo número de problemas únicos
        vector<int> solve(3);  // Número de problemas únicos que resolvió cada amigo
        
        // Calcular cuántos problemas únicos resolvió cada amigo
        for (int i = 0; i < 3; i++) {
            int tmp = 0;  // Contador de problemas únicos para el amigo i
            for (int j = 0; j < A[i]; j++) {
                if (mark[B[i][j]] == 1) {  // Si el problema fue resuelto solo por este amigo
                    tmp++;
                }
            }
            if (tmp > maxUnique) {  // Actualizar el máximo número de problemas únicos
                maxUnique = tmp;
            }
            solve[i] = tmp;  // Guardar cuántos problemas únicos resolvió el amigo i
        }
        
        // Imprimir los amigos que resolvieron el mayor número de problemas únicos
        for (int i = 0; i < 3; i++) {
            if (solve[i] == maxUnique) {
                cout << i + 1 << " " << solve[i];  // Imprimir el número del amigo y cuántos problemas únicos resolvió
                for (int j = 0; j < A[i]; j++) {
                    if (mark[B[i][j]] == 1) {  // Imprimir solo los problemas únicos
                        cout << " " << B[i][j];
                    }
                }
                cout << "\n";
            }
        }
        
        // Limpiar el array de marcaje para el próximo caso
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < A[i]; j++) {
                mark[B[i][j]] = 0;  // Resetear los valores de marcaje para el siguiente caso
            }
        }
    }
    
    return 0;
}
