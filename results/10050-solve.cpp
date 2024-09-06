#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;
    while (num--) {
        int dias, partidos;
        cin >> dias >> partidos;
        vector<int> partido;
        vector<int> simulacionDias(dias, 0);
        for (int i = 0; i < partidos; i++) {
            int cadaDia;
            cin >> cadaDia;
            partido.push_back(cadaDia);
        }

        for (int i = 0; i < partido.size(); i++) {
            int cada = partido[i];
            for (int j = 0; j < simulacionDias.size(); j++) {
                //cambio de donde hago la evaluacion
                if ((j % 7 != 5) && (j % 7 != 6) && ((j + 1) % cada == 0)) {
                    simulacionDias[j] = 1;
                }
            }
        }

        int suma = 0;
        for (int i = 0; i < simulacionDias.size(); i++) {
            suma += simulacionDias[i];
        }

        cout << suma << endl;
    }

    return 0;
}