#include <stdio.h>

int main()
{
    int heads, legs;

    while (scanf("%d %d", &heads, &legs) != EOF)
    {

        int dogs = (legs - 2 * heads) / 2;
        int people = heads - dogs;

        printf("%d %d\n", dogs, people);
    }

    return 0;
}