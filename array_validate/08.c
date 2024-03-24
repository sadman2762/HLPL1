#include <stdio.h>

int is_monotone_increasing(int *numbers, int length) {
    for (int i = 1; i < length; i++) {
        if (numbers[i] < numbers[i - 1]) {
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

        printf("%s\n", is_monotone_increasing(numbers, length) ? "True" : "False");
    }

    return 0;
}
