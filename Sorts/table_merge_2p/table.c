#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
 int t = *a;
 *a = *b;
 *b = t;
}

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

void bublesort(int* a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i] > a[j])
                swap(&a[i], &a[j]);
        }
    }
}


void mergesort(int* ar, int a, int b);

void mergesort(int *ar, int a, int b) {
    if (a >= b)
        return;
    int mid = (a+b)/2;
    bublesort(ar, mid+1);
    int* c = &ar[mid+1];
    bublesort(c,b - mid);
    merge(ar, a, mid, b);
}

int expBase2(int n) {
	return (1 << n);
}

int main() {
/* Table builder */
	printf("Sorts Table Builder.\n");
	FILE* out;
	clock_t start, end;
	srand(time(NULL));
	out = fopen("table.csv", "w");
	/* Turn off the buffer */

        setbuf (out, NULL);
	fprintf(out, "Sorts compare\n");
        fprintf(out, "Merge Sort. 2 parts\n");
        printf("Merge Sort. 2 parts\n");
	fprintf(out, "N;Time 1;Time 2;Time 3;Time 4;Time 5;Time 6;Time 7;Time 8;Time 9;Time 10;\n");
    for (int i = 1; i <= 20; ++i) {
    	fprintf(out, "%d;", expBase2(i));
    	printf("N = %d\n", expBase2(i));
    	int ** a = (int **) malloc(10*sizeof(int*));
    	for (int j = 0; j < 10; ++j)
    		a[j] = (int*)malloc(expBase2(i)*sizeof(int));
    	for (int j = 0; j < 10; ++j)
    		for (int k = 0; k < expBase2(i); ++k)
    			a[j][k] = rand();
    	for(int j = 0; j < 10; ++j) {
    		start = clock();
    		mergesort(a[j],0,expBase2(i)-1);
    		end = clock();
    		free(a[j]);
    		fprintf(out, "%lf;", ((double)(end - start))/CLOCKS_PER_SEC);
    	}
    	free(a);
    	fprintf(out, "\n");
    }
	fclose(out);
}
