//Write a menu driven program to implement circular queue operations such as Enqueue, Dequeue,
//Traverse, IsEmpty, IsFull using array.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int isEmpty(int front,int rear){
    if (front==-1||rear==-1)
        return(1);
    return(0);
}

int* enqueue(int *a,int ele,int front,int rear){
    if(front==-1)
        ++front;
    rear=(rear+1)%SIZE;
    if (front == (rear + 1) % SIZE) {
        printf("Queue is Full.\n");
        int* b = (int*)malloc(3 * sizeof(int));
        *(b + 0) = -999;
        *(b + 1) = front;
        *(b + 2) = rear;
        return (b);
    }
    *(a+rear)=ele;
    int *b=(int*)malloc(3*sizeof(int));
    *(b+0)=0;
    *(b+1)=front;
    *(b+2)=rear;
    return(b);
}

int* dequeue(int *a,int front,int rear){
    int *b=(int*)malloc(3*sizeof(int));
    if(isEmpty(front,rear)==1){
        printf("Stack is Empty.\n");
        *(b+0)=-999;
    }
    else{
        *(b+0)=*(a+front);
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else ++front;
        if(front==SIZE)
        front=0;
    }
    *(b+1)=front;
    *(b+2)=rear;
    return(b);
}

void traverse(int *a,int front,int rear){
    while(front!=rear+1){
        printf("%d\t",*(a+front));
        ++front;
        if(front==SIZE)
            front=0;
    }
    printf("\n");
}

int main(){
    printf("MAIN:\n");
    printf("1: Enqueue\n");
    printf("2: Dequeue\n");
    printf("3: Traverse\n");
    printf("4: isEmpty\n");
    printf("5: Exit\n");

    int ch=0;
    int ele=0,rear=-1,front=-1,x=0;
    int *stack=(int*)malloc(SIZE*sizeof(int));
    int *b=NULL;

    while(ch!=5){
        printf("Enter choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d",&ele);
                b=enqueue(stack,ele,front,rear);
                front=*(b+1);
                rear=*(b+2);
                break;
            case 2:
                b=dequeue(stack,front,rear);
                x=*(b+0);
                front=*(b+1);
                rear=*(b+2);
                printf("%d\n",x);
                break;
            case 3:
                traverse(stack,front,rear);
                break;
            case 4:
                x=isEmpty(front,rear);
                if (x==1)
                    printf("Stack is Empty.\n");
                else printf("Stack is not Empty\n");
                break;
            case 5:
                printf("Terminating...\n");
                break;
            default:
                printf("Wrong choice");
        }
    }
    printf("Terminated.");
}