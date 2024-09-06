/*car*/
#include <stdio.h>
#include <math.h>

int main() {
    int numeroCaso = 1;
    int type;

    while (scanf("%d", &type) == 1 && type != 0) {

        double u, v, t, a, s;

        switch (type) {
            case 1:
                scanf("%lf %lf %lf", &u, &v, &t);
                a = (v - u) / t;
                s = u * t + 0.5 * a * t * t;
                printf("Case %d: %.3lf %.3lf\n", numeroCaso, s, a);
                break;
            case 2:
                scanf("%lf %lf %lf", &u, &v, &a);
                t = (v - u) / a;
                s = u * t + 0.5 * a * t * t;
                printf("Case %d: %.3lf %.3lf\n", numeroCaso, s, t);
                break;
            case 3:
                scanf("%lf %lf %lf", &u, &a, &s);
                v = sqrt(u * u + 2 * a * s);
                t = (v - u) / a;
                printf("Case %d: %.3lf %.3lf\n", numeroCaso, v, t);
                break;
            case 4:
                scanf("%lf %lf %lf", &v, &a, &s);
                u = sqrt(v * v - 2 * a * s);
                t = (v - u) / a;
                printf("Case %d: %.3lf %.3lf\n", numeroCaso, u, t);
                break;
        }

        numeroCaso++;
    }

    return 0;
}
