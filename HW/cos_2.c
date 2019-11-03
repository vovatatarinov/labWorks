#include <stdio.h>
#include <math.h>


int main() {
    double epsilon, x;

    printf("\nInput x: ");
    scanf("%lf", &x);
    printf("\nInput epsilon: ");
    scanf("%lf", &epsilon);

    long long int ix;
    double res = x / (2 * M_PI);
    ix = res;
    res = res * 2 * M_PI - ix* 2 * M_PI;
    x = res;

    res = 0;
    double last_res = 0;
    for (int i = 0; ; ++i) {
        double res2;
        double fac = 1;
        for (int j = 1; j <= 2*i; ++j)
            fac *= j;
        res2 = pow(-1, i) * pow(x, 2*i)/fac;
        res += res2;
        if (fabs(res2 - last_res) < epsilon)
            break;
        last_res = res2;
    }

    printf("cosinus is %lf\ncosinus by system: %lf\n", res, cos(x));

}
