#include <stdio.h>

int count_of_local_maximums(int *numbers, int length) {
    int is_local_maximum(int *arr, int i, int length) {
        if (i == 0)
            return arr[i] > arr[i + 1];
        else if (i == length - 1)
            return arr[i] > arr[i - 1];
        else
            return arr[i] > arr[i - 1] && arr[i] > arr[i + 1];
    }

    int count = 0;

    for (int i = 0; i < length; i++) {
        if (is_local_maximum(numbers, i, length))
            count++;
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

        printf("%d\n", count_of_local_maximums(numbers, length));
    }

    return 0;
}
