//Find greatest and lowest of 10 numbers

#include <stdio.h>

int main(){
    int a[10];
    printf("Enter 10 elements:\n");
    for (int i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    
    int g=a[0], l=a[0];
    for (int i=1;i<10;i++){
        if (a[i]>g)
            g=a[i];
        else if (a[i]<l)
            l=a[i];
    }
    
    printf("Greatest = %d\n", g);
    printf("Lowest = %d", l);
    
    return(0);
}