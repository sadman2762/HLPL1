#include<stdio.h>
#include<stdlib.h>

int is_palindromme(int* numbers, int length){
    if(length==1){
        return 1;
    }
    for(int i=0;i<length/2;i++){
        if(numbers[i] != numbers[length-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    while (1)
    {
        int n;
        if(scanf("%d",&n)==EOF){
            break;
        }
        int numbers[n];

        for(int i=0;i<n;i++){
            scanf("%d",&numbers[i]);
        }
        int result= is_palindromme(numbers,n);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
    
}