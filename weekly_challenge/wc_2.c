 /*
 * temperature_conversion_function.c
 *
 * Rewrite the temperature conversion program to use a function.
 * K&R Exercise 1.15
 */
#include <stdio.h>
#define LOWER  -100.0
#define UPPER 100.0
#define STEP 10.0
float celsius2fahrenheit(float celsius);
int main()
 {
    celsius2fahrenheit(LOWER);
 };

float celsius2fahrenheit(float celsius){
    printf("celsius     fahrenheit\n");
    for(; celsius <= UPPER; celsius += STEP ){
        printf("%6.1f   %9.1f\n",celsius,((celsius* 9.0/5.0) +32.0));
    }
}