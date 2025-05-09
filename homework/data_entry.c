#include <stdio.h>

int get_section();
float get_gpa();
int get_course_load();
int get_credits();
int main(){
    int section = get_section();
    getchar();
    float gpa = get_gpa();
    getchar();
    int courses = get_course_load();
    getchar();
    int credits = get_credits();
    getchar();
    printf("\nSection:    %4c\nCurrent gpa:   %3.2f\nCourses:    %4d\nCredits:    %4d\n",section, gpa, courses, credits);
}  

int get_section(){
    printf("\nenter your section number(1,2 or 3):");
    int section = getchar();
    return section;
}

float get_gpa(){
    float gpa;
    printf("\nwhat is your current gpa?:");
    scanf("%f",&gpa);
    return gpa;
}

int get_course_load(){
    int courses;
    printf("\nhow many courses are you taking this semester?:");
    scanf("%d",&courses);
    return courses;
}

int get_credits(){
    int credits;
    printf("\nhow many credits are you taking?:");
    scanf("%d",&credits);
    return credits;
}