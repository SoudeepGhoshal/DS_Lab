/*Write a program to create a structure to store the information of n number of Employees.
Employee’s information includes data members: Emp-id, Name, Designation, basic_salary, hra%, da%.
Display the information of employees with gross salary. Use array of structure.*/

#include <stdio.h>

struct Emp{
    char name[50];
    char desg[50];
    long sal;
    int hra, da;
    long gross;
};

int main(){
    int n=0;
    printf("Enter number of employees: ");
    scanf("%d", &n);

    struct Emp emp[n];
    for (int i=0; i<n; i++){
        printf("Enter details of employee %d\n", i+1);
        scanf("%s", &emp[i].name);
        scanf("%s", &emp[i].desg);
        scanf("%ld", &emp[i].sal);
        scanf("%d", &emp[i].hra);
        scanf("%d", &emp[i].da);
        emp[i].gross=emp[i].sal+(emp[i].hra*emp[i].sal/100)+((emp[i].da*emp[i].sal/100));
    }
    
    printf("Employee Information:\n");
    for (int i=0; i<n; i++){
        printf("Employee %d details:\n", i+1);
        printf("Name: %s\n", emp[i].name);
        printf("Designation: %s\n", emp[i].desg);
        printf("Basic Salary: %ld\n", emp[i].sal);
        printf("HRA: %d%%\n", emp[i].hra);
        printf("DA: %d%%\n", emp[i].da);
        printf("Gross Salary: %d\n", emp[i].gross);
    } 
}