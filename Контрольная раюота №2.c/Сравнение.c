#include <stdio.h>
#include <stdbool.h>

int compare(bool arr1[], int len1, bool arr2[], int len2) {
    
    int max_len = (len1 > len2) ? len1 : len2;

    int start1 = 0;
    int start2 = 0;

    while (start1 < len1 && arr1[start1] == false) 
        start1++;
    while (start2 < len2 && arr2[start2] == false) 
        start2++;

    int effective_len1 = len1 - start1;
    int effective_len2 = len2 - start2;

    if (effective_len1 == 0 && effective_len2 == 0) 
        return 0;

    if (effective_len1 > effective_len2) 
        return 1;
    if (effective_len1 < effective_len2) 
        return -1;

    for (int i = start1; i < len1; i++) {
        int j = start2 + (i - start1);
        if (arr1[i] != arr2[j]) {
            return arr1[i] ? 1 : -1; 
        }
    }
    return 0;
}

int main() {
    
    bool num1[] = {true, true, false};           
    int len1 = sizeof(num1)/sizeof(num1[0]);
    bool num2[] = {false, true, false, true};     
    int len2 = sizeof(num2)/sizeof(num2[0]);

    int res = compare(num1, len1, num2, len2);

    if (res > 0)
        printf("Первое число больше\n");
    else if (res < 0)
        printf("Второе число больше\n");
    else
        printf("Числа равны\n");

    return 0;
}
