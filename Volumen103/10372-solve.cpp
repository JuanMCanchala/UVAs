/*

Juan Manuel Canchala
8983809
Carlos Ramirez
Complejidad: n log n

*/

/*
no funciona para 
2
0.0 82.9
0.0 68.3
correcto: 0.00 355822.93 mio: 0.00 1006419.24
*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>


using namespace std;

//acos(-1)

struct Ans{
    double angleO;
    double vO;
};

// Será true si puede pasar por todos los edificios
bool pasa( vector<double>& alt, vector<double>& dis, double angle, double vel,int numCasos){
    double gravedad = 9.8;
    double EPS = 1e-8;
    double vX = vel * cos(angle); //la altura en x
    double vY = vel * sin(angle); // la distancia en y
    double time, posX = 0, high;
    bool flag = true;

    for (int i = 0; i < numCasos; i++){
        time = (posX + dis[i]) / vX;
        high = vY * time - 0.5 * gravedad * time * time;
        if (high < alt[i] - EPS){
            flag = false;
        }

        time = posX / vX;
        high = vY * time - 0.5 * gravedad * time * time;
        if (high < alt[i] - EPS){
            flag = false;
        }
        posX += dis[i];
    }


    return flag; 
}

Ans biseccion(double disTotal, int numCasos, vector<double>& alt, vector<double>& dis){
    double PI = acos(-1);
    double EPS = 1e-8;
    double gravedad = 9.8;
    double angleMin = 0;
    double angleMax = PI / 2;
    double angleMedio;
    bool flag;
    Ans ans1;

    while (fabs(angleMax - angleMin) > EPS){
        angleMedio = (angleMin + angleMax) / 2;
        double vel = sqrt(disTotal * gravedad / sin(2 * angleMedio));

        flag = pasa(alt, dis, angleMedio, vel, numCasos);
        if (flag){
            angleMax = angleMedio;
            ans1.angleO = angleMedio;
            ans1.vO = vel;
        }else{
            angleMin = angleMedio;
        }
    }

    return ans1;
}

int main(){
    double PI = acos(-1);
    int numCasos;

    while (scanf("%d", &numCasos) == 1){
        vector<double> alt(numCasos);
        vector<double> dis(numCasos);

        for (int i = 0; i < numCasos; i++){
            scanf("%lf %lf", &alt[i], &dis[i]);
        }

        double disTotal = 0;
        for (int i = 0; i < numCasos; i++){
            disTotal += dis[i];
        }

        Ans ans1 = biseccion(disTotal, numCasos, alt, dis);

        double ans = ans1.angleO * 180 / PI; // pasasr de radianes a grados
        double ans2 = ans1.vO;

        printf("%.2lf %.2lf\n", ans, ans2);
    }

    return 0;
}
