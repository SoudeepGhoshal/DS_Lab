//WAP to implement Priority Queue

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    int priority;
    struct Node *next;
};

struct Node* insert(struct Node *front,int ele,int pri){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ele;
    new->priority=pri;
    new->next=NULL;
    if (front==NULL || front->priority<pri){
        new->next=front;
        front=new;
        return(front);
    }
    struct Node* temp=front;
    while(temp->next!=NULL && temp->next->priority>=pri){
        temp=temp->next;
    }
    new->next=temp->next;
    temp->next=new;
    return(front);
}

struct Node* delete(struct Node *front){
    if (front==NULL){
        printf("Empty Queue\n");
        return(NULL);
    }
    struct Node *temp=front;
    front=front->next;
    printf("%d\n",temp->data);
    free(temp);
    return(front);
}

void display(struct Node *front){
    while (front!=NULL){
        printf("%d(%d)\t",front->data,front->priority);
        front=front->next;
    }
    printf("\n");
}

int main(){
    printf("MENU:\n");
    printf("1: Insert Element\n");
    printf("2: Delete Element\n");
    printf("3: Display Queue\n");
    printf("4: Exit\n");
    int ch=0,ele=0,pr=0;
    struct Node *front=NULL;

    while(ch!=4){
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d",&ele);
                printf("Enter priority:");
                scanf("%d",&pr);
                front=insert(front,ele,pr);
                break;
            case 2:
                front=delete(front);
                break;
            case 3:
                printf("Queue: ");
                display(front);
                break;
            case 4:
                printf("Terminating...\n");
                break;
            default: printf("Wrong Choice\n");
        }
    }
    printf("Terminated.");

    return(1);
}