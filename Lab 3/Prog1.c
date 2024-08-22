//WAP to perform transpose of a given sparse matrix in 3-tuple format.

#include <stdio.h>

int main(){
    printf("Enter rows, columns and number of values of matrix: ");
    int r,c,v;
    scanf("%d %d %d", &r,&c,&v);
    int a[v+1][3];
    
    a[0][0]=r;
    a[0][1]=c;
    a[0][2]=v;

    printf("Enter sparse matrix in 3 tuple format:\n");
    for (int i=1;i<v+1;i++){
        scanf("%d %d %d", &a[i][0],&a[i][1],&a[i][2]);
    }

    printf("Original Matrix:\n");
    for (int i=0;i<v+1;i++){
        for (int j=0;j<3;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    int sp[r][c];

    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            sp[i][j]=0;
        }
    }
    for (int i=1;i<v+1;i++){
        sp[a[i][0]][a[i][1]]=a[i][2];
    }

    int tra[c][r];
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            tra[j][i]=sp[i][j];
        }
    }
    
    int k=1;
    for (int i=0;i<c;i++){
        for (int j=0;j<r;j++){
            if (tra[i][j]!=0){
                a[k][0]=i;
                a[k][1]=j;
                a[k][2]=tra[i][j];
                
                k++;
            }
        }
    }

    a[0][0]=c;
    a[0][1]=r;
    a[0][2]=v;

    printf("Transposed Matrix:\n");
    for (int i=0;i<v+1;i++){
        for (int j=0;j<3;j++){
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}