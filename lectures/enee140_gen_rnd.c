/*
 * enee140_gen_rnd.c
 *
 * Generate random numbers, in different ranges and
 * from various distributions.
 *
 */
 #include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <assert.h>
 /*
 * Public API‐‐ Function prototypes
 */
 void seed_rnd (unsigned seed, int algorithm);
 void get_rnd_max();
 unsigned gen_rnd();
 unsigned gen_rnd_limit(unsigned limit);
 int gen_rnd_range(int min_gen, int max_gen);
 float gen_rnd_float(float min_gen, float max_gen);
 float gen_rnd_exp(float mean);
 int menu_choice(int max);
 int menu_functions(int choice);
 
 //int menu_loop(choice_one);
 /*
 * State variables of the RNG.
 */
unsigned X; // Current value of RNG
unsigned m; // Modulus exponent: M = 2^m
unsigned A; // Multiplier
unsigned B; // Increment

int array_count = 0;
int main(){
    int choice_one, algorithm,seed;
    printf("Welcome to the ENEE140 pseudo‐random number generator!\n");
    printf("1: Print RND_MAX\n");
    printf("2: Generate uniformly‐distributed positive integers\n");
    printf("3: Generate uniformly‐distributed positive integers, up to a given limit\n");
    printf("4: Generate uniformly‐distributed integers, from a given range\n");
    printf("5: Generate uniformly‐distributed floats, from a given range\n");
    printf("6: Generate exponentially‐distributed floats\n");
    choice_one = menu_choice(6);
    if (choice_one == 0){
        return 0;
    }
    printf("Select the algorithm to use.\n");
    algorithm = menu_choice(3);
    if (algorithm == 0){
        return 0;
    }
    printf("select seed for the random number generator:");
    scanf("%d",&seed);
    seed_rnd(seed,algorithm);
    menu_functions(choice_one);
}


int menu_choice(int max){
    int choice;
    int count_two = 1;
    while (count_two <= 3){
        printf("Enter your choice (1‐%d):",max);
        scanf(" %d",&choice);
        if ((choice > max) || (choice < 1)){
            printf("Sorry, that is not a valid option\n");
            count_two ++;
        } else {
            return choice;
        }
    if (count_two > 3){
        printf("You have entered 3 invalid options. Goodbye!");
        return 0;
    }
    }
}
int menu_functions(int choice){
    int returned_choice;
    unsigned no_of_values;
    if (choice == 1){
        get_rnd_max();
        printf("enter another choice from the main menu.\n");
        returned_choice = menu_choice(6);
        menu_functions(returned_choice);
    }else if (choice == 2){
        int i = 0;
        unsigned value;
        printf(" How many numbers should I generate:");
        scanf("%u",&no_of_values);
        for(;i < no_of_values; i++){
            value = gen_rnd();
            printf("%u ",value);
        }
        printf("\n");

    }else if (choice == 3){
        int max_val,rnd_val;
        printf("How many numbers should I generate:");
        scanf("%u",&no_of_values);
        printf("Enter the maximum number to generate:");
        scanf("%u",&max_val);
        int i = 1;
        for(;i <=no_of_values;i ++){
            rnd_val = gen_rnd_limit(max_val);
            printf("%u ",rnd_val);
        }
        printf("\n");
    } else if (choice == 4){
        int min_gen,max_gen,rnd_val;
        printf("How many numbers should I generate:");
        scanf("%u",&no_of_values);
        printf("Enter the minimum number to generate:");
        scanf("%d",&min_gen);
        printf("Enter the maximum number to generate:");
        scanf("%d",&max_gen);
        int i = 1;
        for(;i <=no_of_values;i ++){
            rnd_val = gen_rnd_range(min_gen,max_gen);
            printf("%u ",rnd_val);
        }
        printf("\n");
    } else if (choice == 5){
        float min_gen,max_gen,rnd_val;
        printf("How many numbers should I generate:");
        scanf("%u",&no_of_values);
        printf("Enter the minimum number to generate:");
        scanf("%f",&min_gen);
        printf("Enter the maximum number to generate:");
        scanf("%f",&max_gen);
        int i = 1;
        for(;i <=no_of_values;i ++){
            rnd_val = gen_rnd_float(min_gen,max_gen);
            printf("%.2f ",rnd_val);
    }
    }else if (choice == 6){
        float mean,rnd_val;
        printf("How many numbers should I generate:");
        scanf("%u",&no_of_values);
        printf("Enter the mean of distribution:");
        scanf("%f",&mean);
        if (mean < 0){
            printf("ERROR: the mean must be positive");
            menu_functions(6);
        } else {
            int i = 1;
            for(;i <=no_of_values;i ++){
                rnd_val = gen_rnd_exp(mean);
                printf("%.2f ",rnd_val);
        }
    }
}
}
void seed_rnd (unsigned seed, int algorithm){  //function 5
    if (algorithm == 1){
        m = 32;
        A = 214013;
        B = 2531011;
        
    }else if (algorithm == 2){
        m = 32;
        A = 1103515245;
        B = 12345;
    }else {
        m = 31;
        A = 1103515245;
        B = 12345;
    } 
    X = seed;
    return;
}

void get_rnd_max(){
    double pwr,rand_max;
    //rand_max = 2^m - 1
    pwr = pow(2,m);
    rand_max = pwr - 1;
    printf("%lf\n",rand_max);
    
}

unsigned gen_rnd(){
    X = ((A*X) + B) % m;
    return X;
}

unsigned gen_rnd_limit(unsigned limit){
    printf("not implemented yet");
    return 0; 
}

int gen_rnd_range(int min_gen, int max_gen){
    printf("not implemented yet");
    return 0;
}

float gen_rnd_float(float min_gen, float max_gen){
    printf("not implemented yet");
    return 0;
}

float gen_rnd_exp(float mean){
    printf("not implemented yet");
    return 0;
}