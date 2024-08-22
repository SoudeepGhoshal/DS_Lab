//Write a menu driven program to implement linear queue operations such as Enqueue, Dequeue,
//IsEmpty, Traverse using single linked list.

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node* enqueue(struct Node *rear,int ele){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ele;
    new->next=NULL;
    if (rear==NULL){
        rear=new;
        return(rear);
    }
    rear->next=new;
    rear=new;
    return(rear);
}

struct Node* dequeue(struct Node *front,struct Node *rear){
    if (isEmpty(front)==1){
        printf("Stack is empty\n");
        return(front);
    }
    printf("%d\n",front->data);
    front=front->next;
    return(front);
}

int isEmpty(struct Node *front){
    if (front==NULL){
        return(1);
    }
    else return(0);
}

void display(struct Node *front,struct Node *rear){
    struct Node *temp=front;
    while (temp!=rear->next){
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    printf("MENU\n");
    printf("1: Enter element into the Queue\n");
    printf("2: Display and delete element from the Queue\n");
    printf("3: Check whether Queue is empty\n");
    printf("4: Display Queue elements\n");
    printf("5: Exit\n");

    struct Node *front=NULL,*rear=NULL;
    int ch=-1;
    int ele=0;
    while(ch!=5){
        printf("Enter choice: ");
        scanf("%d", &ch);
        
        switch(ch){
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d",&ele);
                rear=enqueue(rear,ele);
                if(front==NULL)
                    front=rear;
                break;

            case 2:
                front=dequeue(front,rear);
                break;

            case 3:
                if(isEmpty(front)==1)
                    printf("Empty\n");
                else printf("Not Empty\n");
                break;

            case 4:
                display(front,rear);
                break;

            case 5:
                printf("Terminating...\n");
                break;

            default: printf("Wrong Choice");
        }
    }
    
    printf("Terminated");
    return(0);
}