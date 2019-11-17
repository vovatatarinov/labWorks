#include <stdio.h>
#include <malloc.h>

void swap(int* a, int* b) {
 int t = *a;
 *a = *b;
 *b = t;
}

int partition(int *ar, int a, int b) {
    int p = ar[(a+b)/2];
    /* Выберем на некоторое время разделяющий элемент за середину отрезка */
    int i = a;
    int j = b;
    while (i <= j) {
        while (ar[i] < p)
            i++;
        while (ar[j] > p)
            j--;
	if (i >= j) 
            break;
        swap(&ar[i++], &ar[j--]);
    }
    return j;
}

void quicksort(int* ar, int a, int b);

void quicksort(int *ar, int a, int b) {
    if (a < b) {
        int pivot = partition(ar, a, b);
        quicksort(ar, a, pivot);
        quicksort(ar, pivot + 1, b);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int* ar = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; ++i) 
        scanf("%d", &ar[i]);
    printf("Sorting...\n");
    quicksort(ar, 0, n-1); 
    for (int i = 0; i < n; ++i) 
        printf("%d\n", ar[i]);
}
