/*Write a menu driven program to create a structure to represent complex number and perform
the following operation using function :
1. addition of two complex number  (call by value)
2. multiplication of two complex number (call by address)*/

#include <stdio.h>

struct complex{
    int imag, real;
};

void add(int a, int b, int c, int d){
    printf("%d + %di",(a+c),(b+d));
}

void multiply(struct complex c1, struct complex c2){
    printf("%d + %di",((c1.real*c2.real)-(c1.imag*c2.imag)),((c1.real*c2.imag)+(c1.imag*c2.real)));
}

int main(){
    struct complex c1, c2;

    printf("Enter Complex Number 1: ");
    scanf("%d %d", &c1.real, &c1.imag);
    printf("Enter Complex Number 2: ");
    scanf("%d %d", &c2.real, &c2.imag);

    printf("MENU\n1. Addition\n2. Multiplication\nEnter your choice: ");
    int ch=0;
    scanf("%d", &ch);

    switch (ch){
        case 1:
            add(c1.real,c1.imag,c2.real,c2.imag);
            break;
        case 2:
            multiply(c1,c2);
            break;
        default: printf("Wrong Choice");

        return(0);
    }
}