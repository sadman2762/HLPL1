#include<stdio.h>
#include<stdlib.h>

int count_of_local_maximums(int* numbers,int length){
    int count=0;
    for(int i=1;i<length-1;i++){
        if(numbers[i]>numbers[i-1] && numbers[i]>numbers[i+1]){
            count++;
        }
    }
    return count;
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
        int result=count_of_local_maximums(numbers,n);
        printf("%d\n",result);
    }
    return EXIT_SUCCESS;
}