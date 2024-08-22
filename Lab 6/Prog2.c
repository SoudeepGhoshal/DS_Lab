/*Write a menu driven program to create a stack using linked list and perform the following operation using function
a. Push
b. Pop
c. IsEmpty
d. display the stack elements*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *push(struct Node *head,int val){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;

    if (head==NULL){
        head=newNode;
        return(head);
    }

    newNode->next=head;
    head=newNode;

    return(head);
}

struct Node *pop(struct Node *head){
    if (isEmpty(head)==1){
        printf("Stack is empty\n");
        return(1);
    }
    else{
        struct Node *temp=head;
        int val=head->data;
        printf("%d\n",val);
        head=head->next;
        free(temp);
        return(head);
    }
}

int isEmpty(struct Node *head){
    if (head==NULL){
        return(1);
    }
    return(0);
}

void display(struct Node *head){
    while (head!=NULL){
        printf("%d\t",head->data);
        head=head->next;
    }
    printf("\n");
}

int main(){
    struct Node *head=NULL,*t=NULL;

    printf("MENU\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Check for Empty\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    int ch=0,v=0;
    while (ch!=5){
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter element to push: ");
                int ele=0;
                scanf("%d", &ele);
                head=push(head,ele);

                break;
                
            case 2: 
                head=pop(head);
                
                break;

            case 3:
                v=isEmpty(head);
                if(v==1)
                    printf("Empty Stack\n");
                else printf("Not Empty\n");

                break;

            case 4:
                display(head);

                break;

            case 5:
                printf("Terminating...\n");

                break;
            
            default: printf("Wrong Choice.\n");
        }
    }

    printf("Terminated.\n");
    
}