#include <stdio.h>

int count_of_non_negatives(int *numbers, int length) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (numbers[i] >= 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);
    
    for (int t = 0; t < test_cases; t++) {
        int length;
        scanf("%d", &length);
        
        int numbers[length];
        for (int i = 0; i < length; i++) {
            scanf("%d", &numbers[i]);
        }
        
        printf("%d\n", count_of_non_negatives(numbers, length));
    }

    return 0;
}
