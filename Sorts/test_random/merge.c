#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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

int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int* ar = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) 
        ar[i] = rand();
    printf("Sorting...\n");
    mergesort(ar, 0, n-1); 
    freopen("mergesort.txt", "w", stdout);
    for (int i = 0; i < n; ++i) 
        printf("%d\n", ar[i]);
}
