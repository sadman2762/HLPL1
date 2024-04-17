#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    char op;

    scanf("%d %c%d", &a, &op, &b);
    printf("%d %c %d\n", a, op, b);

    switch (op) {
        case '+':
            printf("%d\n", a + b);
            break;
        case '-':
            printf("%d\n", a - b);
            break;
        case '/':
            printf("%d\n", a / b);
            break;
        case '*':
            printf("%d\n", a * b);
            break;
        default:
            printf("%d\n", a % b);
    }

    return EXIT_SUCCESS;
}