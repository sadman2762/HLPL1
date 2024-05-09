#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct{
    char name[31];
    char world[31];
    int height;
    int time;
}RC;

int cmp(const void *a, const void *b){
    RC *left=(RC *)a;
    RC *right=(RC *)b;

    if(left->time != right->time){
        return (left->time - right->time);
    }

    if(left->height != right->height){
        return -(left->height - right->height);
    }

    return strcmp(left->name,right->name);
}

int main(int argc,char *argv[]){
    /* char line[102];
    RC rc[20];
    int length=0; */

    if(argc==1){
        fprintf(stderr,"The command-line arguement is not present.\n");
        return 1;
    }

    FILE *in=fopen(argv[1],"r");

    if(!in){
        fprintf(stderr,"%s cannot be opened",argv[1]);
        return 2;
    }

    //EOF
    /* while(fgets(line,102,in)){

        strcpy(rc[length].name,strtok(line,";"));
        strcpy(rc[length].world,strtok(NULL,";"));
        rc[length].height=atoi(strtok(NULL,";"));
        rc[length].time=atoi(strtok(NULL,";"));
        length++;
    }
 */
    //END
   /*  while(1){
        fgets(line,102,in);
        if (!strcmp(line,"END")){
            break;
        }
         strcpy(rc[length].name,strtok(line,";"));
        strcpy(rc[length].world,strtok(NULL,";"));
        rc[length].height=atoi(strtok(NULL,";"));
        rc[length].time=atoi(strtok(NULL,";"));
        length++;
    } */

    char line[102];
    int length=atoi(fgets(line,102,in));
    RC rc[length];

     for(int i=0;i<length;i++){
        fgets(line,102,in);

        strcpy(rc[length].name,strtok(line,";"));
        strcpy(rc[length].world,strtok(NULL,";"));
        rc[length].height=atoi(strtok(NULL,";"));
        rc[length].time=atoi(strtok(NULL,";"));
     }


    fclose(in);
    qsort(rc,length,sizeof(RC),cmp);

    if(argc==2){
        fprintf(stderr,"The command-line arguement is not present\n");
        return 3;
    }

    FILE *out=fopen(argv[2],"w");
    if(!out){
        fprintf(stderr,"The file is not present\n");
        return 4;
    }


    for(int i=0;i<length;i++){
        fprintf(out,"%s;%s;%d;%d\n",rc[i].name,rc[i].world,rc[i].height,rc[i].time);
    }
    fclose(out);
    return EXIT_SUCCESS;

}