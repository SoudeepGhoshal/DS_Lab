/*Write a program to perform the following operations on a given square matrix using functions: 
i.   Find the no.of nonzero elements
ii.  Display upper triangular matrix
iii. Display the elements of just above and below the main diagonal*/

#include <stdio.h>

void nonZero(int size, int a[size][size]){
    int n=0;
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if (a[i][j]!=0)
                n++;
        }
    }
    printf("Number of non zero elements: %d\n",n);
}

void upperTri(int size, int a[size][size]){
    printf("Upper Triangular Matrix:\n");
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if (i<=j)
                printf("%d\t", a[i][j]);
            else printf("\t");
        }
        printf("\n");
    }
}

void nonDiag(int size, int a[size][size]){
    printf("Non Diagonal Elements:\n");
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            if (i==j){
                printf("\t");
            }
            else printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int size=0;
    printf("Enter size of square matrix: ");
    scanf("%d", &size);
    int a[size][size];
    
    printf("Enter %d elements:\n", (size*size));
    for (int i=0;i<size;i++){
        for (int j=0;j<size;j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    nonZero(size,a);
    upperTri(size,a);
    nonDiag(size,a);
    
    return (0);
}