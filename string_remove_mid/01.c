#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


char* delete_consonants(char* original) {
    char* result =(char*) calloc(strlen(original)+1,sizeof(char));
    int pos = 0;
    for (int i = 0; i < strlen(original); i++) {
        char c = original[i];
    
        if (strchr("aeiouAEIOU", c) || !isalpha(c)) {
            result[pos++] = c;
        }
    }
    
    return result;
}

int main(){
    char line[101];
    gets(line);
    int n = atoi(line);

    for(int i = 0; i < n; i++){
        gets(line);
        char *result= delete_consonants(line);
        puts(result);
        free(result);
    }
}

