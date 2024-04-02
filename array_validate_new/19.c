#include<stdio.h>
#include<stdlib.h>

int is_twisting(int* numbers, int length){
    for(int i=0;i<length-1;i++){
        if((numbers[i]>=0 && numbers[i+1]>=0) || (numbers[i]<0 && numbers[i+1]<0)){
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
        int result=is_twisting(numbers,length);
        printf("%s\n",result?"True":"False");       
    }
    return EXIT_SUCCESS;
}