#include <stdio.h>
#include <math.h>

/*
 * Calc e^x
 * 1) From 0 -> N
 * 2) From N -> 0
 * 3) e^x from standart lib
 * Q: Which methods are more accurate?
 *
*/

int main() {
    float x;
    int n;
    float result1;
    printf("\nInput x: ");
    scanf("%f", &x);
    printf("\nInput N: ");
    scanf("%d", &n);

    float res = 0;
    for (int i = 0; i <= n; ++i) {
        float res2;
        float fac = 1;
        for (int j = 1; j <= i; ++j)
            fac *= j;
        res2 = pow(x, i)/fac;
        res += res2;
    }
    result1 = res;
    res = 0;
    for (int i = n; i >= 0; --i) {
        float res2;
	float fac = 1;
	for (int j = 1; j <= i; ++j)
            fac *= j;
	res2 = pow(x, i)/fac;
	res += res2;


    }
    printf("\ne^x from 0 to N: %.20f\ne^x by lib: %.20f\n"
           "e^x from N to 0: %.20f\n", result1, exp(x), res);

}
