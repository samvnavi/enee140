#include<stdio.h>
int binary_conversion(int num);

int main(){
    int num;
    printf("program to convert decimal to binary\n");
    printf("enter a positive integer:");
    scanf("%d",&num);
    printf("hexadecimal value : %x\n",num);
    printf("octal value : %o\n",num);
    printf("binary value: ");
    int binary_array = binary_conversion(num);
    printf("\n");

}

int binary_conversion(int num){
    int quotient, remainder,i,j;
    int arr[8] = {0,0,0,0,0,0,0,0};
    remainder = 0;
    quotient = num;
    i = 7;
    for(; quotient >= 0; num = quotient, i -= 1){
        quotient = num / 2;
        remainder = num % 2;
        arr[i] = remainder;
        if (quotient == 0){
            break;
        }
    };
    for(j = 0; j <8 ; j+= 1){
        printf("%d",arr[j]);
    }
}
