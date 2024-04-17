#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* double_spaces(char* origin){
    char* result= (char*)calloc(strlen(origin)*2+1,sizeof(char));

    int pos=0;
    for(int i=0;i<strlen(origin);i++){
        if(origin[i] == ' '){
            result[pos++] = origin[i];
        }
        result[pos++] = origin[i];
    }
    return result;
}

int main(){
    char line[101];

    while(1){
        gets(line);
        if(strcmp(line,"")==0){
            break;
        }
        char* result= double_spaces(line);
        puts(result);
        free(result);
    }
    return EXIT_SUCCESS;
}