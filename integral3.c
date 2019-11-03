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
    double last_res = 0;
    double res = 0;
    double sum = 0;
    double xi = a;
    double yi = xi* xi;
    yi /= 2;
    sum += yi;
    xi = b;
    yi = xi * xi;
    yi /= 2;
    sum += yi;
    while (1) {
    last_res = res;
    double dx = (b - a)/parts;
    xi = a;
    //printf("%lf\n", xi);
    xi -= dx;
    for (int i = 1; i < parts; i = i + 2) {
      xi += 2*dx;
      yi = xi * xi;
      sum += yi;  
      //printf("%lf\n", xi);
    }
    
    res = sum * dx;
    printf("Current sum> %lf    Current result>%lf    Parts> %d\n",sum, res, parts);
    if (fabs(res - last_res) < eps)
        break;
    parts *= 2;
    }
    printf("Result> %lf\nBy formula> %lf\nParts> %d", res, (b*b*b-a*a*a)/3, parts);
    return 0;
}
