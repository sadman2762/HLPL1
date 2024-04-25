#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char title[41];  
    int length;
    int plays;
} TRACK;


int compare_tracks(const void *a, const void *b) {
    TRACK *track1 = (TRACK *)a;
    TRACK *track2 = (TRACK *)b;

    
    if (track1->plays != track2->plays)
        return -(track1->plays - track2->plays);

    
    if (track1->length != track2->length)
        return (track1->length - track2->length);

    
    return strcmp(track1->title, track2->title);
}


double query(TRACK *tracks, int length) {
    double total_length = 0.0;
    for (int i = 0; i < length; i++) {
        total_length += tracks[i].length;
    }
    return total_length / length;
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

    
    
    char line[61]; 
    TRACK tracks[30]; 
    int length = 0;
    while(fgets(line, 61, fin))
    {
        strcpy(tracks[length].title, strtok(line, ";"));
        tracks[length].length = atoi(strtok(NULL, ";"));
        tracks[length].plays = atoi(strtok(NULL, ";"));
        length++;
    }
   
    fclose(fin);

    
    qsort(tracks, length, sizeof(TRACK), compare_tracks);

    
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


    
    for (int i = 0; i < length; i++) {
        fprintf(fout, "%s;%d;%d\n", tracks[i].title, tracks[i].length, tracks[i].plays);
    }
    fclose(fout);

    
    printf("%.6f\n", query(tracks, length));

    return 0;
}
