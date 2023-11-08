#include <stdio.h>

int i;
int A[10]={9,8,7,6,5,4,3,2,1,10};

void swap (int *x, int *y) {
  int temp;    

  temp = *x;
  *x = *y;
  *y = temp;
}

void sort (int array[], int array_size) 
{
  int i, j;

  for (i = 0; i < array_size - 1; i++)
  {
    for (j = array_size - 1; j >= i + 1; j--)
    {   
      if (array[j] < array[j-1]) 
      { 
        swap(&array[j], &array[j-1]); 
      }
    }
  }
}

void print()
{
    for (i = 0; i < 10; i++)
     { printf("%d ", A[i]); }
     printf("\n");
}

int main()
{
    print();

    sort(A,10);

    print();

    return 0;

}