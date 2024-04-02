#include<stdio.h>
#include<stdlib.h>

int is_palindrome(int* numbers,int length){
    for(int i=0;i<length/2;i++){
        if(numbers[i] != numbers[length-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int length;
        scanf("%d",&length);
        int numbers[length];
        for(int j=0;j<length;j++){
            scanf("%d",&numbers[j]);
        }
        int result=is_palindrome(numbers,length);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
}