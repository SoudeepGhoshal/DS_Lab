//Swap two variables using Pass by Value and Pass by Reference

#include <stdio.h>
void swap1(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
    printf("inside function for call by value: ");
	printf("a = %d, b = %d\n", a, b);
}

void swap2(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

int main() {
    int num1,num2;
	printf("enter the two numbers to be swapped");
	scanf("%d%d",&num1,&num2);

    printf("Before swapping:\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    swap1(num1, num2);

    printf("After swapping (Call by Value):\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);
	
	swap2(&num1, &num2);

    printf("After swapping (Call by Reference):\n");
    printf("num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}