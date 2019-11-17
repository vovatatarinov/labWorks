#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bublesort(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i] > a[j]) 
                swap(&a[i], &a[j]);
        }
    }
}

int main() {
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int* ar = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) 
        ar[i] = rand();
    printf("Sorting...\n");
    bublesort(ar, n); 
    freopen("bublesort.txt", "w", stdout);
    for (int i = 0; i < n; ++i) 
        printf("%d\n", ar[i]);

}
