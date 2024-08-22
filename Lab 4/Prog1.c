/*Write a program to create a single linked list of n nodes and perform the following menu based
operations on it using function:
i. Insert a node at specific position
ii. Deletion of an element from specific position
iii. Count nodes
iv. Traverse the linked list*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node *next;
};

void insert(struct Node *head,int data,int pos){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->value=data;
    newNode->next=NULL;

    if (pos==1){
        head->next=newNode;
    }

    if (pos>1){
        struct Node *temp = head;
        for (int i=0;i<pos-1;i++){
         temp=temp->next;
        }

        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void delete(struct Node *head,int pos){
    struct Node *temp=head;
    
    if (pos==1)
        head->next=temp->next->next;

    if (pos>1){
        for (int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
}

int count(struct Node *head){
    struct Node *temp=head->next;

    int k=0;
    while(temp!=NULL){
        k++;
        temp=temp->next;
    }

    printf("Number of Nodes = %d\n", k);
    return(k);
}

void traverse(struct Node *head){
    struct Node *temp=head->next;

    while(temp!=NULL){
        printf("%d\t", temp->value);
        temp=temp->next;
    }

    printf("\n");
}

int main(){
    int n=0, pos=0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head=(struct Node*)malloc(sizeof(struct Node));
    head->next=NULL;

    for (int i=0;i<n;i++){
        printf("Enter value %d: ", i+1);
        int v=0;
        scanf("%d", &v);
        insert(head,v,i+1);
    }

    printf("MENU\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Count\n");
    printf("4. Traversal\n");
    printf("5. Exit\n");

    int ch=0;
    while (ch!=5){
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter element to insert: ");
                int ele=0;
                scanf("%d", &ele);
                printf("Enter position to insert: ");
                pos=0;
                scanf("%d", &pos);
                insert(head,ele,pos);

                break;
                
            case 2: 
                printf("Enter position to delete: ");
                pos=0;
                scanf("%d", &pos);
                delete(head,pos);

                break;

            case 3:
                count(head);

                break;

            case 4:
                traverse(head);

                break;

            case 5:
                printf("Terminating...\n");

                break;
            
            default: printf("Wrong Choice.\n");
        }
    }

    printf("Terminated.\n");
    
}