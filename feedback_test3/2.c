#include<stdio.h>
#include<stdlib.h>

int has_matching_parity(int* numbers,int length){
    for(int i=0;i<length;i++){
        if((i%2 ==0 && numbers[i]%2 != 0) || (i%2 != 0 && numbers[i]%2 ==0)){
            return 0;
        }
    }
    return 1;
}

int main(){
    while(1){
        int n;
        if(scanf("%d",&n)==EOF){
            break;
        }
        int numbers[n];
        for(int i=0;i<n;i++){
            scanf("%d",&numbers[i]);
        }
        int result=has_matching_parity(numbers,n);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
}