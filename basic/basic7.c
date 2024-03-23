#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a;
    int prime = 0;
    scanf("%d", &a);

    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            prime = 1;

            break;
        }
    }
    if (prime == 1)
    {
        printf("NO");
    }
    else
        printf("YES");

    return EXIT_SUCCESS;
}