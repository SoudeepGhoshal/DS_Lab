#include <stdio.h>

void insert (int x[], int pos, int ele)
{

  for (int i = 10; i >= pos; i--)
    {
      x[i + 1] = x[i];
    }

  x[pos] = ele;
}

void delete (int x[], int pos)
{

  for (int i = pos; i < 10; i++)
    {
      x[i] = x[i + 1];
    }
}

int main ()
{
  int a[50], ele = 0, pos = 0;

  printf ("Enter 10 elements:\n");
  for (int i = 0; i < 10; i++)
    {
      scanf ("%d", &a[i]);
    }

  printf ("Original array:\n");
  for (int i = 0; i < 10; i++)
    {
      printf ("%d\t", a[i]);
    }
  printf ("\n");

  printf ("Enter element to be inserted: ");
  scanf ("%d", &ele);
  printf ("Enter pposition to be used for insertion: ");
  scanf ("%d", &pos);

  insert (a, pos, ele);

  printf ("Enter pposition to be used for deletion: ");
  scanf ("%d", &pos);

  delete (a, pos);

  printf ("Modified array:\n");
  for (int i = 0; i < 10; i++)
    {
      printf ("%d\t", a[i]);
    }

  return (0);
}
