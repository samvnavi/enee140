#include<stdio.h>

int main(){
    int user_inp,sum_of_square;
    printf("enter a value:");
    scanf("%d",&user_inp);
    sum_of_square = 0;
    while (user_inp > 0){
        sum_of_square += (user_inp * user_inp);
        user_inp -= 1;

    }
    printf("the value of the sum of squares is: %d",sum_of_square);
    return 0;
}