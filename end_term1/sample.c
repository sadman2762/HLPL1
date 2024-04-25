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

int cmp (const void *a, const void *b) {
    AIRPORT *left = (AIRPORT *) a;
    AIRPORT *right = (AIRPORT *) b;

    if (left -> runways != right -> runways)
        return -(left -> runways - right -> runways);

    if (left -> time != right -> time)
        return -(left -> time - right -> time);

    return strcmp(left -> name, right -> name);
}

int query(AIRPORT * airports, int length) {
    int max = airports[0].runways;
    for(int i = 1; i < length; i++) {
        if (airports[i].runways > max)
        {
            max = airports[i].runways;
        }
    }
    return max;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "No input file specified.\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if(!fin) {
        fprintf(stderr, "Input file does not exist.\n");
        return 2;
    }
    
    char line[102];
    AIRPORT airports[20];
    int length = 0;
    while(fgets(line, 102, fin))
    {
        strcpy(airports[length].name, strtok(line, ";"));
        strcpy(airports[length].city, strtok(NULL, ";"));
        airports[length].runways = atoi(strtok(NULL, ";"));
        airports[length].time = atoi(strtok(NULL, ";"));
        length++;
    }

    fclose(fin);

    /*
    for(int i = 0; i < length; i++)
        printf("%s %s %d %d\n", airports[i].name, airports[i].city, airports[i].runways, airports[i].time);
    */

    qsort(airports, length, sizeof(AIRPORT), cmp);

    if (argc < 3) {
        fprintf(stderr, "No output file specified.\n");
        return 3;
    }

    FILE *fout = fopen(argv[2], "w");
    if (!fout)
    {
        fprintf(stderr, "Output file cannot be opened.\n");
        return 4;
    }

    for(int i = 0; i < length; i++)
        fprintf(fout, "%s;%s;%d;%d\n",airports[i].name, airports[i].city, airports[i].runways, airports[i].time);
    
    fclose(fout);

    printf("%d\n", query(airports, length));

    return EXIT_SUCCESS;
}