#include<stdio.h>
#include<stdlib.h>

int is_twisting(int* numbers,int length){
    for(int i=0;i<length-1;i++){
        if((numbers[i]>=0 && numbers[i+1]>=0) || (numbers[i]<0 && numbers[i+1]<0)){
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
        int result=is_twisting(numbers,n);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
}