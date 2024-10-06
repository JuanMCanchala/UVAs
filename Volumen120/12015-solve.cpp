#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef struct Pagina {
    string url;
    int valor;
} Pagina;

int main() {
    int numCasos, contador = 1;
    cin >> numCasos;

    while (numCasos--) {
        int mayor = 0;
        vector<Pagina> busquedas;  // Vector para almacenar las búsquedas
        cout << "Case #" << contador << ":" << endl;

        for (int i = 0; i < 10; ++i) {
            Pagina temp;  // Estructura temporal para almacenar los datos
            cin >> temp.url >> temp.valor;
            busquedas.push_back(temp);  // Agregar la estructura al vector
            }
        for(int j=0; j < 10; j++){
            if(mayor < busquedas[j].valor)
                mayor = busquedas[j].valor;

        }
        for(int k = 0; k < 10; k++){
            if(mayor == busquedas[k].valor){
                cout << busquedas[k].url << endl;
            }
        }
        contador++;
    }
    return 0;
    }


