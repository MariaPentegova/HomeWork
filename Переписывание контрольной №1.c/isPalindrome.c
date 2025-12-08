#include <stdio.h>
#include <string.h>

int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str)-1;

    while (left < right) {
        while (left < right && str[left] == ' ')
            left++;
        while (left < right && str[right] == ' ')
            right--;
        if (left >= right)
            break;
        if (str[left] != str[right])
            return 0; 
        left++;
        right--;
    }
    return 1; 
}

int main() {
	char str[256];
    fgets(str, sizeof(str), stdin);
    size_t len = strlen(str);
  
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
  
    if (isPalindrome(str))
        printf("Строка является палиндромом\n");
    else
        printf("Строка НЕ является палиндромом\n");

    return 0;
}
