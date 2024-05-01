#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[31];
    char city[31];
    int runways;
    int time;
} AIRPORT;

int cmp(const void *a, const void *b)
{
    AIRPORT *left = (AIRPORT *)a;
    AIRPORT *right = (AIRPORT *)b;

    if (left->runways != right->runways)
    {
        return -(left->runways - right->runways);
    }

    if (left->time != right->time)
    {
        return -(left->time - right->time);
    }

    return strcmp(left->name, right->name);
}

int main(int argc, char *argv[])
{
    char line[102];

    AIRPORT airports[20];
    int length = 0;

    if (argc == 1)
    {
        fprintf(stderr, "The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    if (!in)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[1]);
        return 2;
    }

    while (1)
    {
        fgets(line, 102, in);
        line[strlen(line) - 1] = '\0';
        if (!strcmp(line, "END"))
        {
            break;
        }

        strcpy(airports[length].name, strtok(line, ";"));
        strcpy(airports[length].city, strtok(NULL, ";"));
        airports[length].runways = atoi(strtok(NULL, ";"));
        airports[length].time = atoi(strtok(NULL, ";"));
        length++;
    }

    fclose(in);

    qsort(airports, length, sizeof(AIRPORT), cmp);

    if (argc == 2)
    {
        fprintf(stderr, "The second command-line argument is missing.\n");
        return 3;
    }
    FILE *out = fopen(argv[2], "w");
    if (!out)
    {
        fprintf(stderr, "%s cannot be opened.\n", argv[2]);
        return 4;
    }

    for (int i = 0; i < length; i++)
    {
        fprintf(out, "%s;%s;%d;%d\n", airports[i].name, airports[i].city, airports[i].runways, airports[i].time);
    }
    fprintf(out, "END\n");

    fclose(out);

    return EXIT_SUCCESS;
}