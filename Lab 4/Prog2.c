/*In addition to 4.1, perform following operations using function on the single linked list:
 i. search an element in the list
ii. sort the list in ascending order
iii. reverse the list*/

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

struct Node* swap(struct Node *pt1, struct Node *pt2){
    struct Node *t=pt1;
    pt1=pt2;
    pt2=t;

    return(pt2);
}

int count(struct Node *head){
    struct Node *temp=head->next;

    int k=0;
    while(temp!=NULL){
        k++;
        temp=temp->next;
    }

    return(k);
}

void search(struct Node *head,int ele){
    struct Node *temp=head->next;
    int pos=0,k=1;

    while(temp!=NULL){
        if (temp->value==ele){
            pos=k;
            break;
        }
        k++;
        temp=temp->next;
    }

    if(pos>0)
        printf("Element found at position: %d\n",pos);
    else printf("Element not found.\n");
}

void bsort(struct Node *head){
    struct Node *temp1=head->next,*temp2;
    int length=count(head);
    int t;

    while(temp1!=NULL){
        temp2=temp1;
        while(temp2->next!=NULL){
            if(temp2->value>temp2->next->value){
                t=temp2->value;
                temp2->value=temp2->next->value;
                temp2->next->value=t;
            }
        }
        temp1=temp1->next;
    }  
}

void ssort(struct Node* head){
    struct Node *t1,*t2;
    int t=0;
    t1=head->next;
    while (t1->next!=NULL){
        t2=t1->next;
        while (t2->next!=NULL){
            if(t1->value>t2->value){
                t=t1->value;
                t1->value=t2->value;
                t2->value=t;
            }
            t2=t2->next;
        }
        t1=t1->next;
    }
}

struct Node* reverse(struct Node *head){
    struct Node *prev,*current, *nextNode;
    prev=NULL;
    current=head->next;
    nextNode=head->next->next;
    printf("f");
    
    while (current!=NULL){
        current->next=prev;
        prev=current;
        current=nextNode;
        nextNode=nextNode->next;
    }
    printf("f");
    head->next=prev;
    return(head);
}

void traverse(struct Node *head){
    struct Node *temp=head->next;

    while(temp!=NULL){
        printf("%d\t->\t", temp->value);
        temp=temp->next;
    }

    printf("NULL\n");
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
    printf("1. Searching\n");
    printf("2. Sorting\n");
    printf("3. Reversal\n");
    printf("4. Traversal\n");
    printf("5. Exit\n");

    int ch=0;
    while (ch!=5){
        printf("Enter Choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter element to search: ");
                int ele=0;
                scanf("%d", &ele);
                search(head,ele);

                break;
                
            case 2: 
                ssort(head);
                printf("Sorted in ascending order.\n");

                break;

            case 3:
                head=reverse(head);
                printf("List reversed.\n");

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
    
    return(0);
}