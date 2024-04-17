#include<stdio.h>
#include<stdlib.h>

int is_monotone_decreasing(int* numbers, int length){
    for(int i=0;i<length;i++){
        if(numbers[i]>numbers[i-1]){
            return 0;
        }
    }
    return 1;
}

int main(){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0){
            break;
        }
        int numbers[n];
        for(int i=0;i<n;i++){
            scanf("%d",&numbers[i]);
        }
        int result=is_monotone_decreasing(numbers,n);
        printf("%s\n",result?"True":"False");
        
            
        }
        return EXIT_SUCCESS;
    }
