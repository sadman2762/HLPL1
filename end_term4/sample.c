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
    HOUSE *right = (HOUSE*)b;

    if(left->score != right->score)
        return -(left->score - right->score);

    if(left->wins != right->wins)
        return (left->wins - right->wins);
    
    return strcmp(left->name,right->name);
}

int query(HOUSE *houses, int length){
    int count=0;
    for(int i=0;i<length;i++){
        if(houses[i].wins >= 1){

            count++;
        }
    }
    return count;
}

int main(int argc,char *argv[]){
    char line[42];
    HOUSE houses[20];
    int length=0;

    if(argc == 1){
        fprintf(stderr,"The first command line argument is missing.\n");
        return 1;
    }
    FILE *in = fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s file cannot be opened.\n",argv[1]);
        return 2;
    }

    while(fgets(line,42,in)){
        line[strlen(line)-1] = '\0';
        strcpy(houses[length].name,strtok(line,";"));
        houses[length].score = atoi(strtok(NULL,";"));
        houses[length].wins = atoi(strtok(NULL,";"));
        length++;
    }
    fclose(in);

    qsort(houses,length,sizeof(HOUSE),cmp);

    if(argc == 2){
        fprintf(stderr,"Second command line argument is missing.\n");
        return 3;
    }
    FILE *out = fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s file cannnot be opened.\n",argv[2]);
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%d;%d\n",houses[i].name,houses[i].score,houses[i].wins);

    }
    
    printf("%d\n",query(houses,length));
    fclose(out);
    return EXIT_SUCCESS;

}
