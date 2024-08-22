//Sum of Prime Numbers

#include <stdio.h>

int prime(int x){
    for (int i=2;i<=x/2;i++){
        if (x%i==0)
            return (1);
    }
    
    if (x==1)
        return (1);

    return (0);
}

int main(){
    int a[10];
    
    printf("Enter 10 elements:\n");
    for (int i=0;i<10;i++){
        scanf("%d", &a[i]);
    }
    
    int sum=0;
    for (int i=0;i<10;i++){
        if (prime(a[i])==0)
            sum+=a[i];
    }
    
    printf("SUM of Prime = %d", sum);
    
    return (0);
}