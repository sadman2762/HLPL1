#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[31];
    char world[31];
    int height;
    int time;
}ROLLER_COASTER;

int cmp(const void *a,const void *b){
    ROLLER_COASTER *left=(ROLLER_COASTER*)a;
    ROLLER_COASTER *right=(ROLLER_COASTER*)b;

    if(left->time != right->time)
        return (left->time - right->time);
    if(left->height != right->height)
        return -(left->height-right->height);
    return strcmp(left->name,right->name);
}


int main(int argc,char *argv[]){
    char line[102];
    ROLLER_COASTER roller_coacters[20];
    int length = 0;

    if(argc==1){
        fprintf(stderr,"The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in = fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s cannot be opened.\n",argv[1]);
        return 2;
    }
    while(1){
        fgets(line,102,in);
        line[strlen(line)-1]='\0';
        if(!strcmp(line,"END")){
            break;
        }
        strcpy(roller_coacters[length].name,strtok(line,";"));
        strcpy(roller_coacters[length].world,strtok(NULL,";"));
        roller_coacters[length].height=atoi(strtok(NULL,";"));
        roller_coacters[length].time = atoi(strtok(NULL,";"));
        length++;
    }
    fclose(in);

    qsort(roller_coacters,length,sizeof(ROLLER_COASTER),cmp);

    if(argc==2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }
    FILE *out = fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s cannot be opened.\n",argv[2]);
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%s;%d;%d\n",roller_coacters[i].name,roller_coacters[i].world,
                                    roller_coacters[i].height,roller_coacters[i].time);
        
    }
    fclose(out);
    return EXIT_SUCCESS;
}