#include <stdio.h>
#include <stdlib.h> // for abs function

int is_twisting(int *numbers, int length) {
    for (int i = 1; i < length; i++) {
        if (abs(numbers[i]) * numbers[i - 1] >= 0) {
            return 0; // False
        }
    }
    return 1; // True
}

int main() {
    int length;

    while (scanf("%d", &length) != EOF) {
        int numbers[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }

        printf("%s\n", is_twisting(numbers, length) ? "True" : "False");
    }

    return 0;
}
