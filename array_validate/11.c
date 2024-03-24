#include <stdio.h>

int is_palindrome(int *numbers, int length) {
    for (int i = 0; i < length / 2; i++) {
        if (numbers[i] != numbers[length - i - 1]) {
            return 0; // False
        }
    }
    return 1; // True
}

int main() {
    int length;
    while (scanf("%d", &length) != EOF) {
        int numbers[length];
        for (int i = 0; i < length; i++) {
            scanf("%d", &numbers[i]);
        }
        printf("%s\n", is_palindrome(numbers, length) ? "True" : "False");
    }
    return 0;
}
