/*Write a menu driven program to create a stack using array and perform the following operation using function
a. Push
b. Pop
c. check stack is empty or not
d. check stack is full or not
e. display stack elements*/

#include <stdio.h>

#define SIZE 50

int push(int *a,int top,int ele){
    if (isFull(top)==1){
        printf("Stack is full");
        return(top);
    }
    ++top;
    *(a+top)=ele;
    return(top);
}

int pop(int *a,int top){
    if (isEmpty(top)==1){
        printf("Stack is empty\n");
        return(top);
    }
    printf("%d\n",*(a + top--));
    return(top);
}

int isEmpty(int top){
    if (top==-1){
        return(1);
    }
    else return(0);
}

int isFull(int top){
    if (top==SIZE-1){
        return(1);
    }
    else return(0);
}

void display(int *a, int top){
    for (int i=0;i<=top;i++){
        printf("%d\t", *(a+i));
    }
    printf("\n");
}

int main(){
    printf("MENU\n");
    printf("1: Enter element into the stack\n");
    printf("2: Display and delete element from the stack\n");
    printf("3: Check whether stack is empty\n");
    printf("4: Check whether stack is full\n");
    printf("5: Display stack elements\n");
    printf("6: Exit\n");

    int a[SIZE];
    int top=-1;
    int ch=-1;
    int ele=0;
    while(ch!=6){
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("Enter element to push: ");
                scanf("%d",&ele);
                top=push(a,top,ele);
                break;

            case 2:
                top=pop(a,top);
                break;

            case 3:
                if(isEmpty(top)==1)
                    printf("Empty\n");
                else printf("Not Empty\n");
                break;

            case 4:
                if(isFull(top)==1)
                    printf("Full\n");
                else printf("Not Full\n");
                break;

            case 5:
                display(a,top);
                break;

            case 6:
                printf("Terminating...\n");
                break;

            default: printf("Wrong Choice");
        }
    }
    
    printf("Terminated");
    return(0);
}