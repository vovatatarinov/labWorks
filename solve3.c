#include <stdio.h>
#include <math.h>

int main() {
    double epsilon, a, b;
    printf("Input epsilon> ");
    scanf("%lf", &epsilon);
    printf("Input a> ");
    scanf("%lf", &a);
    printf("Input b> ");
    scanf("%lf", &b);
    while (fabs(b - a) > epsilon) {
        double fa = a*a - 4;
        double fb = b*b - 4;
	if (fb == fa)
            fb -= epsilon;
        a = b - (b - a) * fb / (fb - fa);
        fa = a*a - 4;
	if (fa == fb)
            fa -= epsilon;
        b = a + (a - b) * fa / (fa - fb);

    }
    printf("Solution found! %lf\n", b);
}
