#include <stdio.h>
#include <math.h>

int is_prime(int num) {
    if (num <= 1)
        return 0; 
    if (num <= 3)
        return 1; 
    if (num % 2 == 0 || num % 3 == 0)
        return 0; 
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return 0; 
    }
    
    return 1; 
}

int count_of_primes(int *numbers, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (is_prime(numbers[i])) {
            count++;
        }
    }
    return count;
}

int main() {
    int length;
    while (scanf("%d", &length) != EOF) {
        int numbers[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }
        printf("%d\n", count_of_primes(numbers, length));
    }

    return 0;
}
