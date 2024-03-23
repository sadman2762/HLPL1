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
    if (a == 1)
        printf("YES");
    else
        printf("NO");

    return EXIT_SUCCESS;
}