#include <stdio.h>

int main(void)
{
  int c;
  int err;

  c = getchar();
  while (c != EOF)
    {
      err = putchar(c);
      if (err != c)
	{
	  printf("An error occured while printing char : %c\n", c);
	  return (1);
	}
      c = getchar();
    }
  return (0);
}
