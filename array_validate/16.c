#include <stdio.h>

int is_strictly_monotone_increasing(int *numbers, int length) {
    for (int i = 1; i < length; i++) {
        if (numbers[i] <= numbers[i - 1]) {
            return 0; // False
        }
    }
    return 1; // True
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int length;
        scanf("%d", &length);
        
        int numbers[length];
        for (int j = 0; j < length; j++) {
            scanf("%d", &numbers[j]);
        }
        
        printf("%s\n", is_strictly_monotone_increasing(numbers, length) ? "True" : "False");
    }

    return 0;
}