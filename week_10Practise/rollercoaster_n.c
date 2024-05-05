#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[31];
    char world[31];
    int height;
    int time;
}ROLLAR_COASTER;

int cmp(const void *a,const void *b){
    ROLLAR_COASTER *left = (ROLLAR_COASTER*)a;
    ROLLAR_COASTER *right = (ROLLAR_COASTER*)b;

    if(left->time != right->time)
        return (left->time - right->time);
    if(left->height != right->height)
        return -(left->height - right->height);
    return strcmp(left->name,right->name);
}

int main(int argc,char *argv[]){
    if(argc==1){
        fprintf(stderr,"The first command-line argument is missing.\n");
        return 1;
    }
    FILE *in=fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s file cannot be opened.\n",argv[1]);
        return 2;
    }
    char line[102];
    int length=atoi(fgets(line,102,in));
    ROLLAR_COASTER coasters[length];

    for(int i=0;i<length;i++){
        fgets(line,102,in);
        line[strlen(line)-1]='\0';

        strcpy(coasters[i].name,strtok(line,";"));
        strcpy(coasters[i].world,strtok(NULL,";"));
        coasters[i].height = atoi(strtok(NULL,";"));
        coasters[i].time = atoi(strtok(NULL,";"));
    }

    fclose(in);
    qsort(coasters,length,sizeof(ROLLAR_COASTER),cmp);

    if(argc==2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }
    FILE *out = fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s file cannot be opened.\n",argv[2]);
        return 4;
    }
    for(int i =0;i<length;i++){
        fprintf(out,"%s;%s;%d;%d\n",coasters[i].name,coasters[i].world,
                                        coasters[i].height,coasters[i].time);
    }
    fclose(out);
    return EXIT_SUCCESS;
}
