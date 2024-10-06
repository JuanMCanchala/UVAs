#include <iostream>
#include <vector>
using namespace std;

int main(){
    int numCasos;
    cin >> numCasos;

    while(numCasos--){
        int numEstudiantes;
        cin >> numEstudiantes;

        vector<int> estudiantes(numEstudiantes);
        for(int i = 0; i < numEstudiantes; i++){
            cin >> estudiantes[i];
        }

        int maxDiferencia = -1;
        int maxSenior = estudiantes[0];  // estudiante senior

        for(int i = 1; i < numEstudiantes; i++){
            // Calcular la diferencia entre el más senior hasta ahora y el junior actual
            int diferencia = maxSenior - estudiantes[i];
            if(diferencia > maxDiferencia){
                maxDiferencia = diferencia;
            }
            // Actualizar el máximo senior visto hasta ahora
            if(estudiantes[i] > maxSenior){
                maxSenior = estudiantes[i];
            }
        }

        cout << maxDiferencia << endl;
    }

    return 0;
}
