#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char name[31];
    char world[31];
    int height;
    int time;
    
}ROLLER_COSTER;

int cmp(const void *a, const void *b){

    ROLLER_COSTER *left = (ROLLER_COSTER*)a;
    ROLLER_COSTER *right=(ROLLER_COSTER*)b;

    if(left->time != right->time)
        return (left->time - right->time);

    if(left->height != right->height)
        return -(left->height - right->height);

    return strcmp(left->name,right->name);
}

int main(int argc,char *argv[]){
    char line[102];
    ROLLER_COSTER roller_costers[21];
    int length = 0;

    if(argc==1){
        fprintf(stderr,"first command line argument is missing.\n");
        return 1;
    }

    FILE *in = fopen(argv[1],"r");
    if(!in){
        fprintf(stderr,"%s cannot be opened",argv[1]);
        return 2;
    }

    while(fgets(line,102,in)){
        

        strcpy(roller_costers[length].name,strtok(line,";"));
        strcpy(roller_costers[length].world,strtok(NULL,";"));
        roller_costers[length].height = atoi(strtok(NULL,";"));
        roller_costers[length].time = atoi(strtok(NULL,";"));
        length++;
    }
    fclose(in);

    qsort(roller_costers,length,sizeof(ROLLER_COSTER),cmp);

    if (argc == 2){
        fprintf(stderr,"The second command-line argument is missing.\n");
        return 3;
    }

    FILE *out=fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"%s cannot be opened.\n");
        return 4;
    }
    for(int i=0;i<length;i++){
        fprintf(out,"%s;%s;%d;%d\n",roller_costers[i].name,
                                    roller_costers[i].world,
                                    roller_costers[i].height,
                                    roller_costers[i].time);

        }
    fclose(out);
    return EXIT_SUCCESS;
}
