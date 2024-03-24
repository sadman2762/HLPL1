#include <stdio.h>

int is_monotone_decreasing(int *numbers, int length) {
    for (int i = 1; i < length; i++) {
        if (numbers[i] > numbers[i - 1]) {
            return 0; // False
        }
    }
    return 1; // True
}

int main() {
    int length;
    while (scanf("%d", &length) == 1) {
        int numbers[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }

        printf("%s\n", is_monotone_decreasing(numbers, length) ? "True" : "False");
    }

    return 0;
}
