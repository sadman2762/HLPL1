#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* double_uppers(char* origin){
    char* result=(char*)calloc(strlen(origin)*2+1,sizeof(char));

    int pos=0;
    for(int i=0;i<strlen(origin);i++){
        if(isupper(origin[i])){
            result[pos++]=origin[i];
        }
        result[pos++]=origin[i];
    }
    return result;
}

int main(){
    char line[101];
    while(gets(line)){
        
        char* result=double_uppers(line);
        puts(result);
        free(result);
        
    }
}