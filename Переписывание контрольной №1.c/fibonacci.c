#include <stdio.h>

int main() {
    long long a = 1; 
    long long b = 2;
    long long sum_even = 0; 
    long long next;
  
    sum_even += b;
    while (1) {
        next = a + b;
        if (next > 1000000) {
            break; 
        }
      
        if (next % 2 == 0) {
            sum_even += next;
        }
        a = b;
        b = next;
    }

    printf("%lld", sum_even);

    return 0;
}
