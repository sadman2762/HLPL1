#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int max;
    int b;
    scanf("%d", &n);
    scanf("%d", &b);
    max = b;

    for (int i = 1; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a > max)
            max = a;
    }
    printf("%d", max);
    return EXIT_SUCCESS;
}