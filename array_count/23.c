#include <stdio.h>

int count_of_local_minimums(int *numbers, int length) {
    int is_local_minimum(int *arr, int i) {
        if (i == 0)
            return arr[i] < arr[i + 1];
        else if (i == length - 1)
            return arr[i] < arr[i - 1];
        else
            return arr[i] < arr[i - 1] && arr[i] < arr[i + 1];
    }

    int count = 0;

    for (int i = 0; i < length; i++) {
        if (is_local_minimum(numbers, i))
            count++;
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

        printf("%d\n", count_of_local_minimums(numbers, length));
    }

    return 0;
}
