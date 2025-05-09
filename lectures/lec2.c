#include <stdio.h>
// a++ is the same as ++a
// a-- is the same as --a
/*&& - and, || - or, !a - not a*/
/*while loop:
int i
i = 0
while (i<10) {
i ++} */
/*you can omit any of the parts in a for loop header*/
/*infinite loops anre a common error*/
/* declaration int a = 0,b*/
/* for the increment in the for loop the values are executed from the left to right */
/*char holds only one char eg: 'c'
char c = 'D' + 1 --the value is E*/
/* int d = 'c' - 'a' -- the value will be 2*/
/*c = 'c' + ('A' - 'a')*/
int main(){
    int a,b=0;
    char c;
    c = 'D' - ('A'-'a');
    printf("%c\n",c);
    for(a = b;b < 10;a= b+1, b=b+1){
        printf("a is %d\n",a);
        printf("b is %d\n",b);
}
}
