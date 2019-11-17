#include <stdio.h>
#include <malloc.h>

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
   int n;
   scanf("%d", &n);
   int* a = (int*) malloc(n*sizeof(int));
   if (a == NULL)
        return 1;
   for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
   printf("Sorting...\n");
   bublesort(a, n);
   for (int i = 0; i < n; ++i)
        printf("%d\n", a[i]);

}
