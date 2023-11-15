#include <stdio.h>

int main()
{

 int i;

  for (i = 1; i <= 100; ++i)
  {
    if (i % 15 == 0 && i != 0)
    {
      printf("FizzBuzz: %d\n", i);
    }
    else if (i % 3 == 0 && i != 0)
    {
      printf("Fizz: %d\n", i);
    }
    else if (i % 5 == 0 && i != 0)
    {
      printf("Buzz: %d\n", i);
    }
    
  }
    return 0;

}

