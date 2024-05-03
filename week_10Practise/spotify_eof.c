#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char title[41];
    int length;
    int plays;
}TRACK;

int cmp(const void *a,const void *b){
    TRACK *left = (TRACK*)a;
    TRACK *right = (TRACK*)b;

    if(left->plays != right->plays)
        return -(left->plays - right->plays);
    if(left->length != right->length)
        return (left->length - right->length);
    
    return strcmp(left->title,right->title);
}

int main(int argc,char *argv[]){
    char line[62];
    TRACK tracks[20];
    int length=0;

    if(argc==1){
        fprintf(stderr,"The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in= fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s cannot be opened.\n",argv[1]);
        return 2;
    }
    while(fgets(line,62,in)){
        line[strlen(line)-1]='\0';
        strcpy(tracks[length].title,strtok(line,";"));
        tracks[length].length = atoi(strtok(NULL,";"));
        tracks[length].plays = atoi(strtok(NULL,";"));
        length++;
    }
    fclose(in);
    qsort(tracks,length,sizeof(TRACK),cmp);

    if(argc==2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }
    FILE *out= fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s cannot be opened.\n");
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%d;%d\n",tracks[i].title,tracks[i].length,tracks[i].plays);
    }
    fclose(out);
    return EXIT_SUCCESS;

}