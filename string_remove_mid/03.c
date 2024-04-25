#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* delete_consonant(char* origin){
    char* result = (char*)calloc(strlen(origin)+1,sizeof(char));

    int pos =0;
    for(int i = 0; i<strlen(origin);i++){
        if(strchr("aeiou",tolower(origin[i])) || !isalpha(origin[i])){
            result[pos++] = origin[i];
        }
    }
    return result;
}

int main(){
    char line[101];
   
    while(strcmp(gets(line),"")!= 0){
        
        
        char* result = delete_consonant(line);
        puts(result);
        free(result);
    }

    return EXIT_SUCCESS;
}