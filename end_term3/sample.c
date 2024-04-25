#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char manufacturer[151];
    char model[101];
    int seats;
} AIRCRAFT;

int cmp(const void *a, const void *b) {
    AIRCRAFT *left = (AIRCRAFT *)a;
    AIRCRAFT *right = (AIRCRAFT *)b;

    if (left->seats != right->seats)
        return -(left->seats - right->seats);

    
    if ( strcmp(left->manufacturer, right->manufacturer)!= 0)
        return strcmp(left->manufacturer, right->manufacturer);

    return strcmp(right->model, left->model);
}
char* query(AIRCRAFT *aircrafts, int length, char *manufacturer) {
    for (int i = 0; i < length; i++) {
        if (strcmp(aircrafts[i].model, manufacturer) == 0) {
            return aircrafts[i].manufacturer;
        }
    }
    return NULL;
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
    
    char line[301];
    AIRCRAFT aircrafts[52];
    int length = 0;
    while (fgets(line, 301, fin) != NULL) {
    if (strcmp(line, "END") == 0) break;
    strcpy(aircrafts[length].manufacturer, strtok(line, ","));
    strcpy(aircrafts[length].model, strtok(NULL, ","));
    aircrafts[length].seats = atoi(strtok(NULL, ";"));
    length++;
}
    fclose(fin);

    
    qsort(aircrafts, length, sizeof(AIRCRAFT), cmp);

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
        fprintf(fout, "%s,%s,%d\n",aircrafts[i].manufacturer, aircrafts[i].model, aircrafts[i].seats);
    
    fclose(fout);
    char *manufacturer = "Fokker";
    char *model=query(aircrafts, length,manufacturer);
    if (model)
    printf("%s\n",model );
    else
    printf("not found");

    return EXIT_SUCCESS;
}
