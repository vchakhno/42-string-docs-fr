#include <stdio.h>  //for the printf function
#include <unistd.h> //for the write function
#include <string.h> //for the strlen function

void ft_putstr(char *str)
{
  size_t len;

  len = strlen(str);
  write(1, str, len);
}

int main(void)
{
  printf("\\t test\n");
  printf("String\tdocs\n");
  printf("\\b test\n");
  printf("String -\bdocs\n");
  printf("\\f test\n");
  printf("String\fdocs\n");
  printf("\\r test\n");
  /*
  '\r' is not useful when used with the libc printf
  Because it is a buffer that waits for a '\n' (or to be full)
  to be flushed. But when writing your own ft_printf you'll be
  able to implement the fact that it flushes itself after each
  call to ft_printf.
  No '\n' at the end because the '\r' comes back
  at the beginning of the current line and override
  the previous characters
  */
  ft_putstr("This is 1");
  sleep(1);
  ft_putstr("\rThis is 2");
  sleep(2);
  ft_putstr("\rThis is 3\n");
  return (0);
}
