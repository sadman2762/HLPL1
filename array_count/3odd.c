#include <stdio.h>

int count_of_odds(int *numbers, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int length;
    while (1) {
        scanf("%d", &length);
        if (length == 0)
            break;
        
        int numbers[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }

        printf("%d\n", count_of_odds(numbers, length));
    }

    return 0;
}
