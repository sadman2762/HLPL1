#include <stdio.h>

int is_strictly_monotone_decreasing(int *numbers, int length) {
    for (int i = 1; i < length; i++) {
        if (numbers[i] >= numbers[i - 1]) {
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
        for (int i = 0; i < length; i++) {
            scanf("%d", &numbers[i]);
        }
        
        printf("%s\n", is_strictly_monotone_decreasing(numbers, length) ? "True" : "False");
    }
    
    return 0;
}
