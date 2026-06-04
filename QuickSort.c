#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX 100000


int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int i = lb + 1;
    int j = ub;
    int temp;


    while (1) {
        while (i <= ub && a[i] <= pivot)
            i++;
        while (a[j] > pivot)
            j--;


        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }


    temp = a[lb];
    a[lb] = a[j];
    a[j] = temp;


    return j;
}


void quickSort(int a[], int lb, int ub) {
    if (lb < ub) {
        int k = partition(a, lb, ub);
        quickSort(a, lb, k - 1);
        quickSort(a, k + 1, ub);
    }
}


int main() {
    int arr[MAX];
    srand(time(NULL));


    printf("Input Size\tTime Taken (sec)\n");


    for (int n = 10000; n <= MAX; n += 10000) {
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 100000;


        clock_t start = clock();
        quickSort(arr, 0, n - 1);
        clock_t end = clock();


        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("%d\t\t%f\n", n, time_taken);
    }


    return 0;
}
