#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

double mean(int arr[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) sum += arr[i];
    return (double)sum / n;
}

double median(int arr[], int n) {
    qsort(arr, n, sizeof(int), compare);
    if (n % 2 == 0)
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else
        return arr[n/2];
}

void mode(int arr[], int n) {
    int maxCount = 0;
    int modeVals[n];
    int modeSize = 0;

    for(int i = 0; i < n; i++) {
        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) count++;
        }
        if (count > maxCount) {
            maxCount = count;
            modeSize = 0;
            modeVals[modeSize++] = arr[i];
        } else if (count == maxCount) {
            int alreadyAdded = 0;
            for (int k = 0; k < modeSize; k++) {
                if (modeVals[k] == arr[i]) alreadyAdded = 1;
            }
            if (!alreadyAdded) modeVals[modeSize++] = arr[i];
        }
    }

    printf("Mode: ");
    for (int i = 0; i < modeSize; i++) printf("%d ", modeVals[i]);
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Mean: %.2f\n", mean(arr, n));
    printf("Median: %.2f\n", median(arr, n));
    mode(arr, n);

    return 0;
}
