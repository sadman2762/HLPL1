#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int is_squares(int num){
    int root=(int)sqrt(num);
    return root*root == num;
}

int count_of_squares(int* numbers, int length){
    int count=0;
    for(int i=0;i<length;i++){
        if(is_squares(numbers[i])){
            count++;
        }
    }
    return count;
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
        int result=count_of_squares(numbers,n);
        printf("%d\n",result);
    }
    return EXIT_SUCCESS;

}