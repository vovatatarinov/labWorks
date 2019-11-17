#include <stdio.h>

int main() {
    int p;
    int n;
    printf("Input n> ");
    scanf("%d", &n);
    printf("Input p> ");
    scanf("%d", &p);
    int i = 1;
    while (n / i > 0)
        i *= p;
    i /= p;
    while (i > 0) {
	char c = n / i;
	if (c >= 10) {
	    c -= 9; 
            c |= (1 << 6);
	}
	else
            c |= ( (1 << 5) | (1 << 4) );
	printf("%c", c);
	n = n % i;
	i /= p;
    }
    printf("\n");
}
