#include <stdio.h>
#include <math.h>

int main() {
    double epsilon, x;
    printf("Input epsilon> ");
    scanf("%lf", &epsilon);
    printf("Start from> ");
    scanf("%lf", &x);
    double fx = x*x - 4;
    double dfdx = 2 * x;
    double next_interation = x - fx/dfdx;
    while(fabs(next_interation - x) > epsilon) {
    	x = next_interation;
    	fx = x*x - 4;
    	dfdx = 2 * x;
        next_interation = x - fx/dfdx;
    }
    printf("Solution found! %lf\n", x);
}