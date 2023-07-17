#include <stdio.h>

void ft_print_alphabet(void)
{
  int c = 'a';

  while (c <= 'z')
    {
      if (putchar(c) == 0)
	return ;
      c++;
    }
}

int main(void)
{
  ft_print_alphabet();
  return (0);
}
