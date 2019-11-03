#include <stdio.h>
#include <math.h>

double normalize_x(double x) {
    long long int ix;
    double res = x / (2 * M_PI);
    ix = res;
    res = res * 2 * M_PI - ix* 2 * M_PI;
    return res;
}

double factorial(int n) {
    if (!n)
        return 1;
    double res=1;
    for (int i = 1; i <= n; ++i)
        res *= i;
    return res;
}

double x_n(int n, double x) {
    return pow(-1, n) * pow(x, 2*n)/factorial(2*n);
}

int main() {
    double epsilon, x;

    printf("\nInput x: ");
    scanf("%lf", &x);
    printf("\nInput epsilon: ");
    scanf("%lf", &epsilon);

    x = normalize_x(x);
    double res = 0;
    for (int i = 0; fabs(x_n(i+1, x)- x_n(i, x)) > epsilon; ++i)
        res += x_n(i, x);
    printf("cosinus is %lf\n", res);

}
