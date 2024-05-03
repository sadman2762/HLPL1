#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[16];
    int score;
    int wins;
}HOUSE;

int cmp(const void *a, const void *b){
    HOUSE *left = (HOUSE*)a;
    HOUSE *right=(HOUSE*)b;

    if(left->score != right->score)
        return -(left->score-right->score);
    if(left->wins != right->wins)
        return (left->wins - right->wins);
    return strcmp(left->name,right->name);
}

int main(int argc,char *argv[]){
    char line[101];
    HOUSE houses[20];
    int length=0;

    if(argc==1){
        fprintf(stderr,"The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in=fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s cannot be opened.\n",argv[1]);
        return 2;
    }
    while (fgets(line,101,in))
    {
        strcpy(houses[length].name,strtok(line,";"));
        houses[length].score=atoi(strtok(NULL,";"));
        houses[length].wins=atoi(strtok(NULL,";"));
        length++;
    }

    fclose(in);

    qsort(houses,length,sizeof(HOUSE),cmp);



    if(argc==2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }
    FILE *out=fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s cannot be opened.\n");
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%d;%d\n",houses[i].name,houses[i].score,houses[i].wins);
    }
    fclose(out);
    return EXIT_SUCCESS;
    
    
}
