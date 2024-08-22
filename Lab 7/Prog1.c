//Write a menu driven program to create a linear queue using array and perform Enqueue, Dequeue,
//Traverse, IsEmpty, IsFull operations.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

int enqueue(int *a,int rear,int ele){
    if (isFull(rear)==1){
        printf("Queue is full");
        return(rear);
    }
    ++rear;
    *(a+rear)=ele;
    return(rear);
}

int dequeue(int *a,int front,int rear){
    if (isEmpty(rear)==1){
        printf("Stack is empty");
        return(front);
    }
    printf("%d\n",*(a + front++));
    return(front);
}

int isEmpty(int rear){
    if (rear==-1){
        return(1);
    }
    else return(0);
}

int isFull(int rear){
    if (rear==SIZE-1){
        return(1);
    }
    else return(0);
}

void display(int *a, int front, int rear){
    for (int i=front;i<=rear;i++){
        printf("%d\t", *(a+i));
    }
    printf("\n");
}

int main(){
    printf("MENU\n");
    printf("1: Enter element into the Queue\n");
    printf("2: Display and delete element from the Queue\n");
    printf("3: Check whether Queue is empty\n");
    printf("4: Check whether Queue is full\n");
    printf("5: Display Queue elements\n");
    printf("6: Exit\n");

    int a[SIZE];
    int front=-1,rear=-1;
    int ch=-1;
    int ele=0;
    while(ch!=6){
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d",&ele);
                rear=enqueue(a,rear,ele);
                if(front==-1&&rear==0)
                    ++front;
                break;

            case 2:
                front=dequeue(a,front,rear);
                break;

            case 3:
                if(isEmpty(rear)==1)
                    printf("Empty\n");
                else printf("Not Empty\n");
                break;

            case 4:
                if(isFull(rear)==1)
                    printf("Full\n");
                else printf("Not Full\n");
                break;

            case 5:
                display(a,front,rear);
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