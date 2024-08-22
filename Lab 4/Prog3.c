//Write a program to represent the polynomial equation of single variable using single linked list and
//perform the addition of two polynomial equations.

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

void traverse(struct Node *head){
    struct Node *temp=head->next;
    int k=0;

    while(temp!=NULL){
        if (temp->next==NULL)
            printf("%d x^%d\n", temp->value,k);
        else printf("%d x^%d + ", temp->value,k);
        temp=temp->next;
        k++;
    }
}

void add(struct Node *p1,struct Node *p2,struct Node *p3){
    int k=0,v1=0,v2=0;
    while (p1!=NULL&&p2!=NULL){
        if(p1==NULL)
            v1=0;
        else v1=p1->value;
        if(p2==NULL)
            v2=0;
        else v2=p2->value;
        insert(p3,v1+v2,k+1);
        k++;
        p1=p1->next;
        p2=p2->next;
    }
}

int main(){
    struct Node *poly1=(struct Node*)malloc(sizeof(struct Node));
    struct Node *poly2=(struct Node*)malloc(sizeof(struct Node));
    struct Node *poly3=(struct Node*)malloc(sizeof(struct Node));
    poly1->next=NULL;
    poly2->next=NULL;
    poly3->next=NULL;
    int n1=0,n2=0,n=0;

    printf("Enter highest degree of Polynomial 1: ");
    scanf("%d",&n1);
    printf("Enter highest degree of Polynomial 2: ");
    scanf("%d",&n2);

    printf("Enter coefficients of Polynomial 1:\n");
    for (int i=0;i<n1+1;i++){
        printf("x^%d: ",i);
        scanf("%d",&n);
        insert(poly1,n,i+1);
    }
    printf("Enter coefficients of Polynomial 2:\n");
    for (int i=0;i<n2+1;i++){
        printf("x^%d: ",i);
        scanf("%d",&n);
        insert(poly2,n,i+1);
    }

    add(poly1->next,poly2->next,poly3);

    printf("Polynomial 1:\n");
    traverse(poly1);
    printf("Polynomial 2:\n");
    traverse(poly2);
    printf("Resultant Polynomial:\n");
    traverse(poly3);

    return(0);
}