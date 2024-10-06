//Para todo aquel que la solucion le de Wrong Answer o TLE les dejo mi solucion 
//dejare algunos comentarios como aclaracion :)
// PD: los casos de udebug no sirven para solucionar este problema me dio accepted y en los casos no me daba correcto

#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm> 

using namespace std;

double EPS = 1e-9; // Voy a volver a dejar el EPS en 1e-9 si lo hago mas grande se hace TLE

double biseccion(int numSegmentos, double time, vector<int>& distancias, vector<int>& speed) {
    //Los rangos iniciales por lo que creo son mejorables
    double l = -1e9, r = 1e10;
    double mid, tiempo;
    //inicio de la biseccion
    while (r - l > EPS) {
        mid = (l + r) / 2;
        tiempo = 0;
        // uso de flag1 dice si el valor de mid es valido para calcular el tiempo 
        bool flag = true;
        // uso de flag2 si durante el ciclo for se encuentra que la velocidad es menor o igual que cero pues se detiene el for como un break basicamente con esta optimizacion es suficiente para que pase en python habria que buscar otras optimizaciones como buscar el valor menor de speed por ejemplo aunque no se si funcione
        bool flag2 = true; 
        for (int i = 0; i < numSegmentos && flag2; i++) {
            double velocidadReal = speed[i] + mid;
            if (velocidadReal > 0) {
                tiempo += distancias[i] / velocidadReal;
            } else {
                flag = false; 
                flag2 = false; 
            }
        }


        if (!flag || tiempo > time) {
            l = mid; 
        }else{
            r = mid;
        }
    }

    return (l + r) / 2;
}

int main() {
    int numSegmentos;
    double time;
    //lectura
    while (scanf("%d %lf", &numSegmentos, &time) != EOF) {
        vector<int> distancias(numSegmentos);
        vector<int> speed(numSegmentos);
        
        for (int i = 0; i < numSegmentos; ++i) {
            scanf("%d %d", &distancias[i], &speed[i]);
        }

        double ans = biseccion(numSegmentos, time, distancias, speed);
        //impresion de la repsuesta
        printf("%.9f\n", ans);
    }
    
    return 0;
}
