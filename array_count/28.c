#include <stdio.h>

int count_of_increasing_neighbours(int *numbers, int length) {
    int count = 0;
    for (int i = 1; i < length; i++) {
        if (numbers[i] >= numbers[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    int num_test_cases;
    scanf("%d", &num_test_cases);

    for (int t = 0; t < num_test_cases; t++) {
        int length;
        scanf("%d", &length);

        int numbers[length];
        for (int i = 0; i < length; i++) {
            scanf("%d", &numbers[i]);
        }

        printf("%d\n", count_of_increasing_neighbours(numbers, length));
    }

    return 0;
}
