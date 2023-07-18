#include <stdio.h>
#include <ctype.h>

int main(void)
{
  int c;

  c = 0x68; //Le code ASCII de 'h' en hexadecimal
  putchar(toupper(c)); // 'H'
  putchar(c - 3); //'e'
  putchar(c + 4); //'l'
  putchar(c + 4); //'l'
  putchar(c + 7); //'o'
  putchar(32); //Le code ASCII de ' ' en decimal
  c += 15; //c vaut maintenant 'w'
  putchar(toupper(c)); // 'W'
  putchar(c - 8); // 'o'
  putchar(c - 5); // 'r'
  putchar(c - 11); // 'l'
  putchar(c - 19); // 'd'
  putchar(0041); // Le code ASCII de '!' en octal
  return (0);
}
