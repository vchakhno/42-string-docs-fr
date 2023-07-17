#include <stdio.h>

int main(void)
{
  char c;
  char s??(??) = "bonjour\n";

  //scanf("A%c\n", &c);
  //printf("The char : `%c' has been entered\n", c);
  c = 'a';
  if (c != 'b')
    printf("Definitely not equal\n");
  else
    printf("WTF?\n");
  printf("This is my string : %s", s);
  return  (0);
}
