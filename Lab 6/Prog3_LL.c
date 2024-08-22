//Write a program to convert infix expression to postfix operation using stack. (Linked List)

#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
};

struct Node* pushStack(struct Node *head,char ele){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ele;
    new->next=NULL;

    if (head==NULL){
        head=new;
    }
    else{
        new->next=head;
        head=new;
    }

    return(head);
}

struct Node* insert(struct Node *head,char ele){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=ele;
    new->next=NULL;

    if (head==NULL){
        head=new;
    }
    else{
        struct Node *temp=head;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new;
    }

    return(head);
}

struct Node* popStack(struct Node *head){
    struct Node *t=head;
    head=head->next;
    free(t);

    return(head);
}

void display(struct Node *head){
    while(head!=NULL){
        printf("%c",head->data);
        head=head->next;
    }
    printf("\n");
}

struct Node* infixToPostfix(struct Node *exp){
    struct Node *out=NULL,*stack=NULL;
    char c='\0';
    while (exp!=NULL){
        c=exp->data;

        if (c==')'){
            while(stack->data!='('){
                out=insert(out,stack->data);
                stack=popStack(stack);
            }
            stack=popStack(stack);;
        }

        else if (c=='^'){
            while(stack!=NULL){
                if(stack->data=='^'||stack->data=='(')
                    break;
                out=insert(out,stack->data);
                stack=popStack(stack);
            }
            stack=pushStack(stack,c);
        }

        else if (c=='*'||c=='/'||c=='%'){
            while(stack!=NULL){
                if(stack->data=='*'||stack->data=='/'||stack->data=='%'||stack->data=='(')
                    break;
                out=insert(out,stack->data);
                stack=popStack(stack);
            }
            stack=pushStack(stack,c);
        }
        
        else if(c=='+'||c=='-'||c=='('){
            stack=pushStack(stack,c);
        }

        else{
            out=insert(out,c);
        }

        exp=exp->next;
    }

    while(stack!=NULL){
        out=insert(out,stack->data);
        stack=popStack(stack);
    }

    return(out);
}

int main(){
    struct Node *exp_out=NULL,*exp_in=NULL,*t1=NULL;
    char exp[50];
    printf("Enter an expression in infix format: ");
    scanf("%s",&exp);
    char c=exp[0];

    //printf("hello");
    
    for (int i=0;c!='\0';i++){
        c=exp[i];
        exp_in=insert(exp_in,c);
    }

    printf("Infix Expression: ");
    display(exp_in);

    exp_out=infixToPostfix(exp_in);
    printf("Postfix Expression: ");
    display(exp_out);

    return(0);
}