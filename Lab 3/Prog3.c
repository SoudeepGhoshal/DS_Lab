//WAP to represent the polynomial of single variable using 1-D array and perform the addition
//of two polynomial equations.

#include <stdio.h>

int main(){
    int d=0;
    printf("Enter maximum degree of polynomial: ");
    scanf("%d", &d);
    d++;

    int p1[d], p2[d];

    printf("Enter polynomial 1 from lowest degree to highest degree: ");
    for (int i=0;i<d;i++){
        scanf("%d", &p1[i]);
    }

    printf("Enter polynomial 2 from lowest degree to highest degree: ");
    for (int i=0;i<d;i++){
        scanf("%d", &p2[i]);
    }

    int p3[d];
    for (int i=0;i<d;i++){
        p3[i]=p1[i]+p2[i];
    }

    printf("Polynomial 1: ");
    for (int i=0;i<d;i++){
        if (i!=d-1)
            printf("%d x^%d + ", p1[i],i);
        else printf("%d x^%d", p1[i],i);
    }
    printf("\n");

    printf("Polynomial 2: ");
    for (int i=0;i<d;i++){
        if (i!=d-1)
            printf("%d x^%d + ", p2[i],i);
        else printf("%d x^%d", p2[i],i);
    }
    printf("\n");

    printf("Resultant Polynomial: ");
    for (int i=d-1;i>=0;i--){
        if (i!=0)
            printf("%d x^%d + ", p3[i],i);
        else printf("%d x^%d", p3[i],i);
    }

    return(0);
}