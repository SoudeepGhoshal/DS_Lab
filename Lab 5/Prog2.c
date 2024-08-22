//Write a program to create a circular linked list and display the elements of the list.

#include <stdio.h>

struct Node{
    int value;
    struct Node *next;
};

struct Node* insert(struct Node *head,int data,int pos){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->value=data;
    newNode->next=head;

    if (head==NULL){
        head=newNode;
        return (head);
    }
    
    if (pos==1){
        newNode->next=head;
        head=newNode;
        return (head);
    }

    if (pos>1){
        struct Node *temp = head;
        for (int i=0;i<pos-1;i++){
         temp=temp->next;
        }

        newNode->next=temp->next;
        temp->next=newNode;
        return (head);
    }
}

void delete(struct Node *head,int pos){
    struct Node *temp=head,*del=NULL;
    
    if (pos==1){
        del=head;
        head=head->next;
    }
    if (pos>1){
        for (int i=0;i<pos-1;i++){
            temp=temp->next;
        }
        del=temp->next;
        temp->next=temp->next->next;
    }
    free(del);
}

void traverse(struct Node *head){
    struct Node *temp=head->next;

    printf("%d->", head->value);
    while(temp!=head){
        printf("%d->", temp->value);
        temp=temp->next;
    }
    printf("%d->...", temp->value);
}

int main(){
    int n=0, pos=0;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    struct Node *head=NULL;

    for (int i=1;i<=n;i++){
        printf("Enter value %d: ", i+1);
        int v=0;
        scanf("%d", &v);
        head=insert(head,v,i);
    }

    printf("MENU\n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Traversal\n");
    printf("4. Exit\n");

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
                head=insert(head,ele,pos);

                break;
                
            case 2: 
                printf("Enter position to delete: ");
                pos=0;
                scanf("%d", &pos);
                delete(head,pos);

                break;

            case 3:
                traverse(head);

                break;

            case 4:
                printf("Terminating...\n");

                break;
            
            default: printf("Wrong Choice.\n");
        }
    }

    printf("Terminated.\n");
    
}