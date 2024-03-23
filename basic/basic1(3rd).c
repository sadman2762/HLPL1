#include <stdio.h>
#include <stdlib.h>

int main()
{
    while (1)
    {

        int a, b;
        char op;
        (scanf("%d %c%d", &a, &op, &b) == EOF);
        if (a == 0 || b == 0)
            break;

        else if (op == '+')
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