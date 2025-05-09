#include<stdio.h>
#include <math.h>
#define PI 3.1415

//to give the x and y coordinates of all the angles of the clock
int clock_loop(int radius);
int main(){
    int radius;
    printf("enter the radius of the arm of a clock: ");
    scanf("%d",&radius);
    clock_loop(radius);
}

int clock_loop(int radius){
    int i;
    double angle;
    i = 1;
    angle = (PI/2 - PI/6);
    for(;i<13;i+=1,angle -= (PI/6)){
        printf("%d x-coordinate: %lf y-coordinate %lf\n",i, radius*sin(angle),radius*cos(angle));
    }
}