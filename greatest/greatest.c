#include <stdio.h>

int main() {
    while (1) {
        int n, i, highest_value = 0, count = 0;
        scanf("%d", &n);
        
        if (n == 0)
            break;

        for (i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);
            if (num > highest_value) {
                highest_value = num;
                count = 1;
            } else if (num == highest_value) {
                count++;
            }
        }
        
        printf("%d\n", count);
    }
    return 0;
}
