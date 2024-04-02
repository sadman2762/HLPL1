#include<stdio.h>
#include<stdlib.h>

int is_strictly_monotone_decreasing(int* numbers,int length){
    for(int i=1;i<length;i++){
        if(numbers[i]>=numbers[i-1]){
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
        int result= is_strictly_monotone_decreasing(numbers,n);
        printf("%s\n",result?"True":"False");

    }
    return EXIT_SUCCESS;
    
}