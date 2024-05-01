#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct{
    char code[6];
    char name[51];
    char theme[31];
    int bricks;
}LEGO_SET;

int cmp(const void *a, const void *b){
    LEGO_SET *left = (LEGO_SET*)a;
    LEGO_SET *right= (LEGO_SET*)b;

    if(left->bricks != right->bricks){
        return -(left->bricks - right->bricks);
    }
    if(strcmp(left->theme,right->theme)!=0){
        return strcmp(left->theme,right->theme);
    }
    if(strcmp(left->name,right->name)!=0){
        return strcmp(left->name,right->name);
    }
    
        return strcmp(left->code,right->code);
    

}

int main(int argc, char *argv[]){
    char line[101];
    LEGO_SET lego_sets[20];
    int length=0;
    if(argc==1){
        fprintf(stderr,"The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in= fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s cannot be opened.\n");
        return 2;
    }
    while(fgets(line,101,in)){
        strcpy(lego_sets[length].code,strtok(line,";"));
        strcpy(lego_sets[length].name,strtok(NULL,";"));
        strcpy(lego_sets[length].theme,strtok(NULL,";"));
        lego_sets[length].bricks = atoi(strtok(NULL,";"));
        length++;
    }
    fclose(in);
    if(argc == 2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }
    qsort(lego_sets,length,sizeof(LEGO_SET),cmp);
    FILE *out = fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s cannot be opened.\n");
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%s;%s;%d\n",lego_sets[i].code,lego_sets[i].name,
                                    lego_sets[i].theme,lego_sets[i].bricks);
    }
    fclose(out);
    return EXIT_SUCCESS;

}