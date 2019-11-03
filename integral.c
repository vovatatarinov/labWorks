#include <stdio.h>
#include <math.h>

int main() {
    printf("\nInput a: ");
    double a;
    scanf("%lf", &a);
    printf("\nInput b: ");
    double b;
    scanf("%lf", &b);
    if (a > b)
        return 1;
    printf("\nInput epsilon: ");
    double eps;
    scanf("%lf", &eps);
    if (eps <= 0)
        return 1;
    //int counter = 0;
    int first = 1;
    int parts = 1;
    double res = 0;
    double last_res = 0;
    do {
	parts *= 2;
	if (first == 1) parts = 1;
	if (first == 2)
            first = 0;
	if (!first) {
	    first = 0;
            last_res = res;
	    res = 0;
	   
	}
        double dx = b - a;
	dx /= parts;
	double xi = a + dx/2;

       do {
            double yi = xi * xi;
	    res += yi;
	    xi += dx;
	
	} while(xi <b);
        res *= dx;
	if (first) {
	    first = 2;
	    printf("Result: %lf    Parts: %d\n", res, parts);
	    continue;
	}
	printf("Result: %lf    Parts: %d\n", res, parts);
       //parts *= 2;

    } 
    while((fabs(res - last_res) > eps)|| (first == 2));
    printf("\nParts: %d\n"
           "Result: %lf\n"
	   "By formula: %lf\n", parts, res, (b*b*b - a*a*a)/3);
}
