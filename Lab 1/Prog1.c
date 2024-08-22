//Write a program to read two numbers and compare the numbers using function call by address.

#include <stdio.h>

void compare(int *a, int *b){
    if (*a==*b){
        printf("%d is equal to %d", *a, *b);
    }
    else if (*a>*b){
        printf("%d is greater than %d", *a, *b);
    }
    else if (*a<*b){
        printf("%d is lesser than %d", *a, *b);
    }
}

int main(){
    int a=0,b=0;

    printf("Enter two values:\n");
    scanf("%d %d", &a, &b);

    compare(&a,&b);

    return(0);
}