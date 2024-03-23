#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int sum;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d",&a);
        sum += a;
    }
    printf("%.2f",sum/n);
    return EXIT_SUCCESS;
}