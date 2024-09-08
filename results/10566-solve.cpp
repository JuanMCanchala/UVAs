/*
Juan Manuel Canchala
8983809
Carlos Ramirez
Complejidad: log n porque solo se esta usando la biseccion

*/

#include <iostream>
#include <cmath>
#include <cstdio>  

using namespace std;

double biseccion(double x, double y, double c) {
    double EPS = 10e-8;
    double l = 0, r = min(x, y);
    double mid;
    double ans = 0.0;
    bool encontrado = false;

    while ((r - l) > EPS && !encontrado) {
        mid = (l + r) / 2;

        double equ = (c / sqrt(x * x - mid * mid)) * mid + (c / sqrt(y * y - mid * mid)) * mid;

        if (fabs(equ - mid) < EPS) {
            ans = equ;
            encontrado = true;
        } else if (equ > mid) {
            r = mid;
        } else {
            l = mid;
        }
    }

    if (!encontrado) {
        ans = (l + r) / 2;
    }

    return ans;
}

int main() {
    double x, y, c;
    while (scanf("%lf %lf %lf", &x, &y, &c) == 3) {  
        double ans = biseccion(x, y, c);
        printf("%.3f\n", ans);  
    }

    return 0;
}
