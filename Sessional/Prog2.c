//Represent a Sparse Matrix in three Tuple Format

#include <stdio.h>

int main(){
    int r=0,c=0;
    printf("Enter size of sparse matrix: ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    
    int n=0;
    printf("Enter %d elements:\n", (r*c));
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            scanf("%d", &a[i][j]);
            
            if (a[i][j]!=0)
                n++;
        }
    }
    
    printf("Sparse matrix:\n");
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    
    int b[n][3];
    b[0][0]=r;
    b[0][1]=c;
    b[0][2]=n;
    
    int k=1;
    for (int i=0;i<r;i++){
        for (int j=0;j<c;j++){
            if (a[i][j]!=0){
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                
                k++;
            }
        }
    }
    
    printf("Sparse matrix in 3-tuple format:\n");
    for (int i=0;i<n+1;i++){
        for (int j=0;j<3;j++){
            printf("%d\t",b[i][j]);
        }
        printf("\n");
    }
    
    return (0);
}