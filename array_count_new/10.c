#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_square(int num){
    int root =(int)sqrt(num);
    return root*root == num;
}

int count_of_squares(int* numbers,int length){
    int count=0;
    for(int i=0;i<length;i++){
        if(is_square(numbers[i])){
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
        int result= count_of_squares(numbers,length);
        printf("%d\n",result);
    }
    return EXIT_SUCCESS;
}