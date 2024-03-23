#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int min;
    int b;
    scanf("%d", &n);
    scanf("%d", &b);
    min = b;

    for (int i = 1; i < n; i++)
    {
        int a;
        scanf("%d", &a);
        if (a < min)
            min = a;
    }
    printf("%.d", min);
    return EXIT_SUCCESS;
}