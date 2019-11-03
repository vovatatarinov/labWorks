#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <linux/random.h>

int main() {
    double a, b;
    int N;
    int k;
    printf("\nInput a> ");
    scanf("%lf", &a);
    printf("\nInput b> ");
    scanf("%lf", &b);
    printf("\nInput N> ");
    scanf("%d", &N);
    printf("\nComputing...\n");
    if (b < a) {
        printf("Error!\nb - a < 0\n(b - a) should be greater than 0\n");
	    return 1;
    }
    if (N <= 0) {
        printf("Error!\nN <= 0\nN should be greater than 0\n");
	    return 1;
    }
    srand(time(NULL));
    double f_max = a * a;
    if (b* b > f_max)
        f_max = b * b;
    for (int i = 0; i < N; ++i) {
        double randy = ((double) rand() / RAND_MAX) * f_max;
        double randx = ((double) rand() / RAND_MAX) * (b - a);
        randx += a;
        if (randy <= randx * randx)
            ++k;
    }
    double res = ((double) k / N) * f_max * (b - a);
    printf("Result> %lf\nBy formula> %lf\nPoints> %d\n", res, (b * b * b - a * a * a) / 3, k);    
}
