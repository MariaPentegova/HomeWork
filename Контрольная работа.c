/*Сортировка*/

#include <stdio.h>

void print_arr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sort(int arr[], int n) {
    int i, j, min_i;
    for (i = 0; i <= n - 2; i++) {
        min_i = i;

        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_i]) {
                min_i = j;
            }
        }
        if (min_i != i) {
            int t = arr[i];
            arr[i] = arr[min_i];
            arr[min_i] = t;
        }
    }
}


int main() {
    int arr[] = {21, 42, 4, 7, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Исходный массив: ");
    print_arr(arr, n);

    sort(arr, n);

    printf("Отсортированный массив: ");
    print_arr(arr, n);

    return 0;
}
 
/*Наибольшее количество цифр в двоичной записи/*

#include <stdio.h>

int counter(int n) {
    int i = 0;
    while (n > 0) {
        n &= (n - 1);
        i++;
    }
    return i;
}

int main() {
    int arr[] = {6, 3, 342, 15, 42, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = -1;

    for (int i = 0; i < n; i++) {
        int b = counter(arr[i]);
        if (b > max) {
            max = b;
        }
    }

    for (int i = 0; i < n; i++) {
        if (counter(arr[i]) == max) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    return 0;
}
