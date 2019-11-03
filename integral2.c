#include <stdio.h>
#include <math.h>

int main() {
    double a, b, eps;
    printf("\nInput a> ");
    scanf("%lf", &a);
    printf("\nInput b> ");
    scanf("%lf", &b);
    printf("\nInput epsilon> ");
    scanf("%lf", &eps);
    printf("\nComputing...\n");
    if (b < a) {
        printf("Error!\nb - a < 0\n(b - a) should be greater than 0\n");
	return 1;
    }
    if (eps <= 0) {
        printf("Error!\nepsilon <= 0\nEpsilon should be greater than 0\n");
	return 1;
    }
    int parts = 1;
    double last_sum = 0;
    double sum = 0;
    while (1) {
    last_sum = sum;
    sum = 0;
    double dx = (b - a)/parts;
    double xi = a;
    double yi = xi* xi;
    yi /= 2;
    sum += yi;
    //printf("%lf\n", xi);
    for (int i = 1; i < parts; ++i) {
      xi += dx;
      yi = xi * xi;
      sum += yi;  
      //printf("%lf\n", xi);
    }
    xi += dx;
    //printf("%lf\n", xi);
    yi = xi * xi;
    yi /= 2;
    sum += yi;
    sum *= dx;
    printf("Current sum> %lf    Parts> %d\n",sum, parts);
    if (fabs(sum - last_sum) < eps)
        break;
    parts *= 2;
    }
    printf("Result> %lf\nBy formula> %lf\nParts> %d", sum, (b*b*b-a*a*a)/3, parts);
    return 0;
}
