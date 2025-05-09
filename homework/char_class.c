#include<stdio.h>
 

int main(){
    int user_inp;
    user_inp = 'y';
    while(user_inp == 'y'){ 
        printf("Please enter one charater :");
        user_inp = getchar();
        if (user_inp >= 'a' && user_inp <= 'z'){
            printf("%c is a lower case letter. ",user_inp);
        }
        else if (user_inp >= 'A' && user_inp <= 'Z'){
            printf("%c is an upper case letter.",user_inp);
        }
        else if (user_inp >= '0' && user_inp <= '9'){
            printf("%c is a digit.\n ",user_inp);
        }
        else {
            printf("%c is neither a digit nor a letter. ",user_inp);
        }
        getchar();
        printf("\ndo you want to continue (y/n)?");
        user_inp = getchar();
        getchar();
        return 0;
    }
}
