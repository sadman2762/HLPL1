#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char title[41];
    int length;
    int plays;
}TRACK;

int cmp(const void *a, const void *b){
    TRACK *left = (TRACK*)a;
    TRACK *right = (TRACK*)b;

    if(left->plays != right->plays)
        return -(left->plays - right->plays);
    if(left->length != right->length)
        return (left->length - right->length);
    return strcmp(left->title,right->title);
}

int main(int argc,char *argv[]){
    if(argc == 1){
        fprintf(stderr,"The first command line argument is missing.\n");
        return 1;
    }
    FILE *in = fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s file cannot be opened.\n",argv[1]);
        return 2;
    }
    char line[62];
    int length=atoi(fgets(line,62,in));
    TRACK tracks[length];

    for(int i=0;i<length;i++){
        fgets(line,62,in);
        line[strlen(line)-1]='\0';

        strcpy(tracks[i].title,strtok(line,";"));
        tracks[i].length = atoi(strtok(NULL,";"));
        tracks[i].plays = atoi(strtok(NULL,";"));
    }
    fclose(in);

    qsort(tracks,length,sizeof(TRACK),cmp);

    if(argc==2){
        fprintf(stderr,"The second-command line argument is missing.\n");
        return 3;
    }
    FILE *out = fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s file cannot be opened.\n",argv[2]);
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%d;%d\n",tracks[i].title,tracks[i].length,tracks[i].plays);
    }
    fclose(out);
    return EXIT_SUCCESS;
}
