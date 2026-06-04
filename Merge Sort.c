#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main() {
    srand(time(NULL));

    int sizes[] = {10000, 50000, 100000, 200000, 500000};
    int num_tests = sizeof(sizes) / sizeof(sizes[0]);

    printf("%-15s | %-20s\n", "N (Elements)", "Time Taken (Seconds)");
    printf("----------------------------------------\n");

    for (int t = 0; t < num_tests; t++) {
        int n = sizes[t];

        int *arr = (int *)malloc(n * sizeof(int));
        if (arr == NULL) {
            return 1;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000000;
        }

        clock_t start_time = clock();
        mergeSort(arr, 0, n - 1);
        clock_t end_time = clock();

        double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        printf("%-15d | %-20.6f\
