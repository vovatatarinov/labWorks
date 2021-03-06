#include <stdio.h>
#include <math.h>

void main() {
    int n;
    double epsilon;
    printf("Input epsilon> ");
    scanf("%lf", &epsilon);
    printf("Input n> ");
    scanf("%d", &n);
    double a, b, c;
    for (int i = 0; i < n; ++i) {
        /* Workaround break points */
        a = -M_PI/2 + M_PI*i;
        b = +M_PI/2 + M_PI*i;
        a = (a+b)/2;
        b -= epsilon;
        while (b - a > epsilon)
        {
            c = (a + b) / 2;
            double fc = tan(c) - c;
            double fb = tan(b) - b;
            if(fc * fb >= 0)
                b = c;
            else
                a = c;
        }
        printf("Solution found! %lf   %lf\n", (a+b)/2, tan((a+b)/2) - (a+b)/2);
    }
}
