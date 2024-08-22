//Write a program to convert infix expression to postfix operation using stack. (Array)

#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

char* push(char *a,int top,char ele){
    ++top;
    *(a+top)=ele;
    return(a);
}

char pop(char *a,int top){
    return(*(a+top));
}

void display(char *a, int top){
    for (int i=0;i<=top;i++){
        printf("%d\t", *(a+i));
    }
    printf("\n");
}

char* infixToPostfix(char *exp){
    char *out=(char*)malloc(sizeof(char)*SIZE);
    char *stack=(char*)malloc(sizeof(char)*SIZE);
    int l=sizeof(exp)/sizeof(char);
    int top=-1;
    int index=-1;
    char ch='\0';
    for (int i=0;*(exp+i)!='\0';i++){
        ch=*(exp+i);
        if (ch==')'){
            while(*(stack+top)!='('){
                *(out + ++index)=pop(stack,top--);
            }
            top--;
        }
        else if (ch=='^'){
            while(top!=-1){
                if(*(stack+top)=='^'||*(stack+top)=='(')
                    break;
                *(out + ++index)=pop(stack,top--);
            }
            stack=push(stack,top++,ch);
        }
        else if (ch=='*'||ch=='/'||ch=='%'){
            while(top!=-1){
                if(*(stack+top)=='*'||*(stack+top)=='/'||*(stack+top)=='%'||*(stack+top)=='(')
                    break;
                *(out + ++index)=pop(stack,top--);
            }
            stack=push(stack,top++,ch);
        }
        else if(ch=='+'||ch=='-'||ch=='('){
            stack=push(stack,top++,ch);
        }
        else *(out + ++index)=ch;

    }

    while (top!=-1){
        *(out + ++index)=pop(stack,top--);
    }

    return(out);
}

int main(){
    char exp_in[SIZE];
    char *exp_post;

    printf("Enter an expression in infix format: ");
    scanf("%s",&exp_in);
    exp_post=infixToPostfix(exp_in);
    printf("Infix Expression: %s\n",exp_in);
    printf("Postfix Expression: %s",exp_post);

    return(0);
}