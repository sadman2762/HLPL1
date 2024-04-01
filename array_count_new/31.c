#include<stdio.h>
#include<stdlib.h>

int count_of_decreasing_neighbours(int* numbers,int length){
    int count=0;
    for(int i=1;i<length;i++){
        if(numbers[i]<=numbers[i-1]){
            count++;
        }
    }
    return count;
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
        int result=count_of_decreasing_neighbours(numbers,length);
        printf("%d\n",result);
    }
    return EXIT_SUCCESS;
}