#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

void merge(int *ar, int a, int mid, int c) {
    int nl = mid-a+1;
    int nr = c-mid;
    int* left = (int*) malloc((nl)*sizeof(int));
    int* right = (int*) malloc((nr)*sizeof(int));
    /* Copy arrays */
    for (int i = a; i <= mid; i++)
        left[i-a] = ar[i];
    for (int i = mid+1; i <= c; i++)
        right[i-mid-1] = ar[i];
    /* merge arrays */
    int i = 0; /* For left array */
    int j = 0; /* For right array */
    int k = a; /* For main array */

    while (i < nl && j < nr) 
    { 
        if (left[i] <= right[j]) 
        { 
            ar[k] = left[i]; 
            i++; 
        } 
        else
        { 
            ar[k] = right[j]; 
            j++; 
        } 
        k++; 
    } 
    /* Copy the remaining elements */
    while (i < nl) 
    { 
        ar[k] = left[i]; 
        i++; 
        k++; 
    } 

    while (j < nr) 
    { 
        ar[k] = right[j]; 
        j++; 
        k++; 
    } 
    free(left); /* Try to free memory */
    free(right); 
}

void mergesort(int* ar, int a, int b);

void mergesort(int *ar, int a, int b) {
    if (a >= b)
        return;
    int mid = (a+b)/2;
    mergesort(ar, a, mid);
    mergesort(ar, mid+1, b);
    merge(ar, a, mid, b);
}

int numOfDigits(int n) {
    int res = 0;
    while(n > 0) {
        n /= 10;
        ++res;
    }
    return res;
}

int digit(int n, int i) {
    int res;
    for (int j = 0; j < i; ++j) {
        res = n % 10;
	n /= 10;
     }
    return res;
}

int main() {
    
    srand(time(NULL));

    int m,n;
    printf("Input number of elements> ");
    scanf("%d", &m);
    printf("Input number of files> ");
    scanf("%d", &n);
    
    int* a = malloc(m*sizeof(int));

    for (int i = 0; i < m; ++i)
        a[i] = rand();
    
    mergesort(a, 0, m - 1);
    int length = numOfDigits(n) + 6;
    char* name = malloc(length);
    name[0] = 'a';
    char* name2 = name + (length - 5);
    sprintf(name2, "%s", ".dat");   
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < numOfDigits(n); ++j) {
            name[length - 6 - j] = digit(i, j + 1) + '0';
	}
	
        FILE* out = fopen(name, "w");
	for (int j = 0; j < m; ++j) {
            fprintf(out, "%d %d\n", j + 1, a[j]);
	}
	fclose(out);
    }
    free(name);
}
