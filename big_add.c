#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main() {
   unsigned int n1, n2;
   printf("\nInput number1> ");
   scanf("%d", &n1);
   printf("\nInput number2> ");
   scanf("%d", &n2);
   /* Lets count number of digits */
   int n3 = n1 + n2;
   int digits = 0;
   while (n3 > 0) {
        ++digits;
        n3 /= 10;
   }
   /* Digits is number of digits */

   /* Allocate mem */
   char* d1 = (char*)malloc(digits);
   char* d2 = (char*)malloc(digits);
   char* d3 = (char*)malloc(digits);
   char* flags = (char*)malloc(digits);
   if ( ((unsigned long)d1 == 0) || ((unsigned long)d2 == 0) 
        || ((unsigned long)d3 == 0) || ((unsigned long)flags == 0) ) {
        printf("Allocating error. Restart the program.\n");
	exit(1);
   }
   /* int to str */
   for (int i = digits - 1; i >= 0; --i) {
        d1[i] = n1 % 10;
	n1 /= 10;
	d2[i] = n2 % 10;
	n2 /= 10;
	flags[i] = 0;
   }
   for (int i = digits - 1; i >= 0; --i) {
	d3[i] = d1[i] + d2[i];
	if (flags[i])
            ++d3[i];
	if (d3[i] >= 10) {
            d3[i] -= 10;
	    if (i != 0)
                flags[i - 1] = 1; 
	}

   
   }
   for (int i = 0; i < digits; ++i) {
        if (flags[i])
            printf("*");
	else
            printf(" ");
   }
   printf("\n");
   for (int i = 0; i < digits; ++i)
        printf("%d", d1[i]);
   printf("\n");
   for (int i = 0; i < digits; ++i)
        printf("%d" ,d2[i]);
   printf("\n");
   for (int i = 0; i < digits; ++i)
        printf("_");
   printf("\n");
   for (int i = 0; i < digits; ++i)
        printf("%d", d3[i]);
   printf("\n");
}
