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
    while (1)
    {
        int n;
        scanf("%d",&n);
        if(n==0){
            break;
        }
        int numbers[n];
        for(int i=0;i<n;i++){
            scanf("%d",&numbers[i]);
        }
        int result=is_palindrome(numbers,n);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
    
}