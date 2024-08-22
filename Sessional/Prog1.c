//Create and Linked List and delete Duplicate elements

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head,int ele){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ele;
    new->next=NULL;
    if (head==NULL){
        head=new;
        return(head);
    }
    struct Node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new;
    return(head);
}

struct Node *deleteDupli(struct Node *head) {
    struct Node *current = head, *nextNode = NULL, *duplicate = NULL;
    while (current != NULL && current->next != NULL) {
        nextNode = current;
        while (nextNode->next != NULL) {
            if (current->data == nextNode->next->data) {
                duplicate = nextNode->next;
                nextNode->next = nextNode->next->next;
                free(duplicate);
            } else {
                nextNode = nextNode->next;
            }
        }
        current = current->next;
    }

    return(head);
}


int main(){
    struct Node *head=NULL;
    printf("Enter number of elements: ");
    int n,ele;
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i=0;i<n;i++){
        scanf("%d", &ele);
        head=insert(head,ele);
    }

    deleteDupli(head);
    printf("Final LL:-\n");

    struct Node *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    return(0);
}