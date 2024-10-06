#include <iostream>
#include <vector>

using namespace std;

int main(){

    int numCasos, K, contador = 0, mayor = -1, valores, i;
    cin >> numCasos;

    for(i = 0; i < numCasos; i++){
        vector<int> numeros;
        valores = 0;
        mayor = -1;
        contador++;
        cin >> K;
        for(int j = 0; j < K; j++){
        cin >> valores;
            numeros.push_back(valores);
        }
        for(int k = 0; k < numeros.size(); k++){
            if(mayor < numeros[k])
            mayor = numeros[k];
        }
        cout << "Case " << contador << ": " << mayor << endl;
    }

    return 0;
}