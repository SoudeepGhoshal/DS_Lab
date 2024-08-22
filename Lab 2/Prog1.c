/*WAP to create a 1-D array of n elements and perform the following menu based operations using function.
a. insert a given element at specific position.
b. delete an element from a specific position of the array.
c. linear search to search an element
d. traversal of the array*/

#include <stdio.h>

void insert(int x[], int pos, int ele)
{

  for (int i = 10; i >= pos; i--)
  {
    x[i + 1] = x[i];
  }

  x[pos] = ele;

  printf ("Modified array:\n");
  for (int i = 0; i < 10; i++)
    {
      printf ("%d\t", x[i]);
    }
}

void delete(int x[], int pos)
{

  for (int i = pos - 1; i < 10; i++)
  {
    x[i] = x[i + 1];
  }

  printf("Modified array:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\t", x[i]);
  }
}

int search(int x[], int ele)
{
  int pos = -1;
  for (int i = 0; i < 10; i++)
  {
    if (x[i] == ele)
    {
      pos = i;
      break;
    }
  }

  return (pos);
}

void traversal(int x[])
{
  printf("Array:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\t", x[i]);
  }
  printf("\n");
}

int main()
{
  int a[50], ele = 0, pos = 0;

  printf("Enter 10 elements:\n");
  for (int i = 0; i < 10; i++)
  {
    scanf("%d", &a[i]);
  }

  printf("Original array:\n");
  for (int i = 0; i < 10; i++)
  {
    printf("%d\t", a[i]);
  }
  printf("\n");

  int ch = -1;
  printf("Enter Choice: ");
  scanf("%d", &ch);

  switch (ch)
  {
  case 1:
    printf("Enter element to be inserted: ");
    scanf("%d", &ele);
    printf("Enter position to be used for insertion: ");
    scanf("%d", &pos);

    insert(a, pos, ele);
    break;

  case 2:

    printf("Enter position to be used for deletion: ");
    scanf("%d", &pos);

    delete (a, pos);
    break;

  case 3:
    printf("Enter element to search: ");
    scanf("%d", &ele);

    int s = search(a, ele);
    if (s == -1)
      printf("Element not found \n");
    else
      printf("Element found at position %d \n", s);
    break;

  case 4:
    traversal(a);
    break;

  default:
    printf("Wrong Choice");
  }

  return (0);
}