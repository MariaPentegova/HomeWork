#include <stdio.h>

void gnomeSort(int arr[], int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || arr[i - 1] <= arr[i]) {
            i++;
        } 
        else {
            int t = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = t;
            i--;
        }
    }
}

int main() {
    int arr[] = {346, 2, 15, 34, 1043, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    gnomeSort(arr, n);
    printf("Отсортированный массив:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
