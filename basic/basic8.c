#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a;

        scanf("%d", &a);

        if (a >= 80)
            printf("exellent\n");
        else if (a >= 70)
            printf("good\n");
        else if (a >= 60)
            printf("satisfactory\n");
        else if (a >= 50)
            printf("pass\n");
        else
            printf("fail\n");
    }
    return EXIT_SUCCESS;
}