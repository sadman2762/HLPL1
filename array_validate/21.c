#include <stdio.h>
#include <stdlib.h> 

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

    while (1) {
        scanf("%d", &length);
        if (length == 0) break;

        int numbers[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }

        printf("%s\n", is_twisting(numbers, length) ? "True" : "False");
    }

    return 0;
}
