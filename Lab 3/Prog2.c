//WAP to perform addition of two given sparse matrix in 3–tuple format.

#include <stdio.h>

int main(){
    //Takes input of Tuple 1
    printf("Enter sparse matrix 1 in 3 tuple format:\n");
    int r1,c1,v1;
    scanf("%d %d %d", &r1,&c1,&v1);
    int tup1[v1+1][3];
    tup1[0][0]=r1;
    tup1[0][1]=c1;
    tup1[0][2]=v1;
    for(int i=1;i<v1+1;i++){
        scanf("%d %d %d", &tup1[i][0],&tup1[i][1],&tup1[i][2]);
    }

    //Takes input of Tuple 2
    printf("Enter sparse matrix 2 in 3 tuple format:\n");
    int r2,c2,v2;
    scanf("%d %d %d", &r2,&c2,&v2);
    int tup2[v2+1][3];
    tup2[0][0]=r2;
    tup2[0][1]=c2;
    tup2[0][2]=v2;
    for(int i=1;i<v2+1;i++){
        scanf("%d %d %d", &tup2[i][0],&tup2[i][1],&tup2[i][2]);
    }

    //Creates Sparse matrix 3 and initializes with 0
    int r3=(r1>r2)?r1:r2;
    int c3=(c1>c2)?c1:c2;
    int sp3[r3][c3];
    for (int i=0;i<r3;i++){
        for (int j=0;j<c3;j++){
            sp3[i][j]=0;
        }
    }
   
    //Converts Tuple 1 into Sparse Matrix 1
    int sp1[tup1[0][0]][tup1[0][1]];
    for (int i=0;i<tup1[0][0];i++){
        for (int j=0;j<tup1[0][1];j++){
            sp1[i][j]=0;
        }
    }
    for (int i=1;i<v1+1;i++){
        sp1[tup1[i][0]][tup1[i][1]]=tup1[i][2];
    }

    //Converts Tuple 2 into Sparse Matrix 2
    int sp2[tup2[0][0]][tup2[0][1]];
    for (int i=0;i<tup2[0][0];i++){
        for (int j=0;j<tup2[0][1];j++){
            sp2[i][j]=0;
        }
    }
    for (int i=1;i<v2+1;i++){
        sp2[tup2[i][0]][tup2[i][1]]=tup2[i][2];
    }

    //Adds Sparse Matrices 1 and 2 and stores in 3
    for (int i=0;i<r1;i++){
        for (int j=0;j<c1;j++){
            sp3[i][j]+=sp1[i][j];
        }
    }
    for (int i=0;i<r2;i++){
        for (int j=0;j<c2;j++){
            sp3[i][j]+=sp2[i][j];
        }
    }

    //Converts Sparse matrix 3 into Tuple 3
    int v3=0;
    for (int i=0;i<r3;i++){
        for (int j=0;j<c3;j++){
            if(sp3[i][j]!=0)
                v3++;
        }
    }
    int tup3[v3+1][3];
    tup3[0][0]=r3;
    tup3[0][1]=c3;
    tup3[0][2]=v3;
    int k=1;
    for (int i=0;i<r3;i++){
        for (int j=0;j<c3;j++){
            if (sp3[i][j]!=0){
                tup3[k][0]=i;
                tup3[k][1]=j;
                tup3[k][2]=sp3[i][j];
                
                k++;
            }
        }
    }

    //Prints Resultant Tuple 3
    printf("Resultant Matrix in 3-tuple format:\n");
    for(int i=0;i<v3+1;i++){
        printf("%d %d %d\n", tup3[i][0],tup3[i][1],tup3[i][2]);
    }
}