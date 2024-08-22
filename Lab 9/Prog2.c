//Write a menu driven program to implement Bubble, Insertion, Selection, Quick and Merge Sort.

#include <stdio.h>

#define SIZE 10

void bubbleSort(int a[]){
    int temp=0;
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void insertionSort(int a[]){
    int key=0;
    for (int i=1;i<SIZE;i++){
        int j=i-1;
        key=a[i];
        while (j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void selectionSort(int a[]){
    int temp=0,minIndex=-1;
    for (int i=0;i<SIZE;i++){
        minIndex=i;
        for (int j=i+1;j<SIZE;j++){
            if(a[minIndex]>a[j])
                minIndex=j;
        }
        if (minIndex!=i){
            temp=a[i];
            a[i]=a[minIndex];
            a[minIndex]=temp;
        }
    }
}

int partition(int a[],int l,int r){
    int pivot=a[r];
    int i=l-1,temp=0;
    for (int j=l;j<r;j++){
        if (a[j]<pivot){
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return(i+1);
}
void quickSort(int a[],int l,int r){
    if (l<r){
        int p=partition(a,l,r);
        quickSort(a,l,p-1);
        quickSort(a,p+1,r);
    }
}

void merge(int a[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1],R[n2];
    for (int i=0;i<n1;i++){
        L[i]=a[l+i];
    }
    for (int j=0;j<n2;j++){
        R[j]=a[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if (L[i]<=R[j]){
            a[k]=L[i];
            i++;
        }
        else{
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[],int l,int r){
    if (l<r){
        int m=l+(r-l)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        merge(a,l,m,r);
    }
}

void display(int a[]){
    for (int i=0;i<SIZE;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

int main(){
    int arr[SIZE];
    printf("Enter %d integers:\n",SIZE);
    for (int i=0;i<SIZE;i++){
        scanf("%d",&arr[i]);
    }

    printf("Original Array:\n");
    display(arr);

    printf("MENU:\n");
    printf("1: Bubble Sort\n");
    printf("2: Insertion Sort\n");
    printf("3: Selection Sort\n");
    printf("4: Quick Sort\n");
    printf("5: Merge Sort\n");

    int ch=0;
    printf("Enter choice: ");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            printf("Bubble Sort selected.\n");
            bubbleSort(arr);
            printf("Sorted Array:\n");
            display(arr);
            break;
        case 2:
            printf("Insertion Sort selected.\n");
            insertionSort(arr);
            printf("Sorted Array:\n");
            display(arr);
            break;
        case 3:
            printf("Selection Sort selected.\n");
            selectionSort(arr);
            printf("Sorted Array:\n");
            display(arr);
            break;
        case 4:
            printf("Quick Sort selected.\n");
            quickSort(arr,0,SIZE-1);
            printf("Sorted Array:\n");
            display(arr);
            break;
        case 5:
            printf("Merge Sort selected.\n");
            mergeSort(arr,0,SIZE-1);
            printf("Sorted Array:\n");
            display(arr);
            break;
        default: printf("Wrong Choice.");
    }
}