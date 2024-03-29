#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char* double_consonants(char* origin){
    char* result= (char*)calloc(strlen(origin)*2+1,sizeof(char));

    int pos=0;
    for(int i=0; i<strlen(origin); i++){
        if(strchr("bcdfghjklmnpqrstvwxyz",tolower(origin[i]))){
            result[pos++]= origin[i];

        }
        result[pos++]= origin[i];
    }
    return result;
}

int main(){
    char line[101];
    gets(line);
    int n= atoi(line);

    for(int i= 0; i<n; i++){
        gets(line);
        char* result= double_consonants(line);
        puts(result);
        free(result);
        
    }

    return EXIT_SUCCESS;
}