#include<stdio.h>
#include<stdlib.h>

int has_matching_parity(int* numbers,int length){
    for(int i=0;i<length;i++){
        if((i%2 ==0 && numbers[i]%2 !=0) || (i%2 != 0 && numbers[i]%2 == 0)){
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
        int result=has_matching_parity(numbers,length);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
    
}