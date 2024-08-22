//Write a program to create an array of n elements using dynamic memory allocation.
//Calculate sum of all the prime elements of the array using function and de-allocate the
//memory of the array after its use.

#include <stdio.h>
#include <stdlib.h>

int prime(int x){
    for (int i = 2; i <= x / 2; i++){
        if (x%i==0)
            return (1);
    }

    if (x==1||x==0)
        return (1);

    return (0);
}

int main(){
    int n=0;
    printf("Enter size of array: ");
    scanf("%d",&n);
    int* a=(int*)malloc(n*sizeof(int));

    printf("Enter %d elements:\n", n);
    for (int i=0;i<n;i++){
        scanf("%d", (a+i));
    }

    int sum=0;
    for (int i=0;i<n;i++){
        if (prime(*(a+i))==0)
            sum+=*(a+i);
    }

    printf("Sum = %d", sum);

    free(a);
}