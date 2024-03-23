#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    while (b)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("%d", a);
    return EXIT_SUCCESS;
}