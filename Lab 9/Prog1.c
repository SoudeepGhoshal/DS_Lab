//WAP  to implement Binary Search Tree (create and traverse)

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *L;
    struct Node *R;
};

struct Node* createNode(int item){
    struct Node *new=(struct Node*)malloc(sizeof(struct Node));
    new->data=item;
    new->L=NULL;
    new->R=NULL;
    return(new);
}

struct Node* insert(struct Node *node, int key){
    if (node==NULL){
        return(createNode(key));
    }
    if (key<node->data){
        node->L=insert(node->L,key);
    }
    else if (key>node->data){
        node->R=insert(node->R,key);
    }
    return(node);
}

void inorder(struct Node *root){
    if (root!=NULL){
        inorder(root->L);
        printf("%d\t",root->data);
        inorder(root->R);
    }
}

void preorder(struct Node *root){
    if (root!=NULL){
        printf("%d\t",root->data);
        inorder(root->L);
        inorder(root->R);
    }
}

void postorder(struct Node *root){
    if (root!=NULL){
        inorder(root->L);
        inorder(root->R);
        printf("%d\t",root->data);
    }
}

int main(){
    /* Let us create following BST 
              50 
           /     \ 
          30      70 
         /  \    /  \ 
       20   40  60   80 
   */
    struct Node* root = NULL;
 
    /*root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);*/
    
    /*root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 100);
    root = insert(root, 10);
    root = insert(root, 60);*/

    printf("MENU:\n");
    printf("1: Insert Node\n");
    printf("2: Inorder Traversal\n");
    printf("3: Preorder Traversal\n");
    printf("4: Postorder Traversal\n");
    printf("5: Exit\n");
    int ch=0,ele=0;

    while (ch!=5){
        printf("Enter Choice: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);
                root=insert(root,ele);
                break;
            case 2:
                printf("Inorder Traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 3:
                printf("Preorder Traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal:\n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Termninating...");
                break;
            default: printf("Wrong Choice\n");
        }
    }
    
    printf("Terminated.");

    return 0;
}