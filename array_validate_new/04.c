#include<stdio.h>
#include<stdlib.h>

int is_monotne_decreasing(int* numbers,int length){
    for(int i=1;i<length;i++){
        if(numbers[i]>numbers[i-1]){
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
        int numbers[n];
        for(int j=0;j<length;j++){
            scanf("%d",&numbers[j]);
        }
        int result=is_monotne_decreasing(numbers,length);
        printf("%s\n",result?"True":"False");
    }
    return EXIT_SUCCESS;
}