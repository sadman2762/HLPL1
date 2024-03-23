#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {

        int a, b;
        char op;
        if (scanf("%d %c%d", &a, &op, &b) == EOF)
            break;

        if (op == '+')
            printf("%d\n", a + b);

        else if (op == '-')
            printf("%d\n", a - b);
        else if (op == '*')
            printf("%d\n", a * b);
        else if (op == '/')
            printf("%d\n", a / b);
        else
            printf("%d\n", a % b);
    }

    return EXIT_SUCCESS;
}