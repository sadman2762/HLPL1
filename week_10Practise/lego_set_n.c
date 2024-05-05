#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char code[6];
    char name[51];
    char theme [31];
    int bricks;
}LEGO_SET;

int cmp(const void *a, const void *b){
    LEGO_SET *left= (LEGO_SET*)a;
    LEGO_SET *right = (LEGO_SET*)b;

    if(left->bricks != right->bricks)
        return -(left->bricks - right->bricks);
    if(strcmp(left->theme,right->theme) != 0)
        return strcmp(left->theme,right->theme);
    if(strcmp(left->name,right->name)!=0)
        return strcmp(left->name,right->name);
    return strcmp(left->code,right->code);
}

int main(int argc, char *argv[]){
    if(argc == 1){
        fprintf(stderr,"The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in = fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s file cannot be opened.\n",argv[1]);
        return 2;
    }

    char line[102];
    int length=atoi(fgets(line,102,in));
    LEGO_SET sets[length];

    for(int i=0;i<length;i++){
        fgets(line,102,in);
        line[strlen(line)-1] = '\0';

        strcpy(sets[i].code,strtok(line,";"));
        strcpy(sets[i].name,strtok(NULL,";"));
        strcpy(sets[i].theme,strtok(NULL,";"));
        sets[i].bricks = atoi(strtok(NULL,";"));

    }
    fclose(in);

    qsort(sets,length,sizeof(LEGO_SET),cmp);

    if(argc == 2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }
    FILE *out = fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s file cannot be opened.\n",argv[2]);
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%s;%s;%d\n",sets[i].code,sets[i].name,sets[i].theme,sets[i].bricks);
    }
    fclose(out);
    return EXIT_SUCCESS;
}
