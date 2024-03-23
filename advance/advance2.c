#include <stdio.h>

int main()
{
    int num1, den1, num2, den2;

    while (scanf("%d %d %d %d", &num1, &den1, &num2, &den2) && (num1 || den1 || num2 || den2))
    {

        if (num1 * den2 < num2 * den1)
        {
            printf("<\n");
        }
        else if (num1 * den2 > num2 * den1)
        {
            printf(">\n");
        }
        else
        {
            printf("=\n");
        }
    }

    return 0;
}
