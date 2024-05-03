#include <stdio.h>
#include <stdlib.h>

int find_divisors(int num, int *divisors, int *count) {
    *count = 0;
    divisors = (int)malloc(1 * sizeof(int)); // Allocate memory for one integer

    int i;
    for (i = 1; i <= num; i++) {
        if (num % i == 0) {
            divisors[*count] = i;
            (*count)++; // Increment count of divisors
            divisors = (int)realloc(*divisors, (*count + 1) * sizeof(int)); // Reallocate memory
        }
    }
    return *count;
}

int main() {
    int num, count;
    printf("Enter a number: ");
    scanf("%d", &num);
    int arr[100];
    find_divisors(num, arr, &count);

    printf("Divisors: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}