#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool	ft_isupper(char c)
{
	return ('A' <= c && c <= 'Z');
}

int	main(void)
{
	printf("Original:\n");
	printf("\t'A': %d\n", isupper('A'));
	printf("\t'B': %d\n", isupper('B'));
	printf("\t'H': %d\n", isupper('H'));
	printf("\t'Z': %d\n", isupper('Z'));
	printf("\t'a': %d\n", isupper('a'));
	printf("\t'b': %d\n", isupper('b'));
	printf("\t'h': %d\n", isupper('h'));
	printf("\t'z': %d\n", isupper('z'));
	printf("\t'0': %d\n", isupper('0'));
	printf("\t'5': %d\n", isupper('5'));
	printf("\t'9': %d\n", isupper('9'));
	printf("\t'}': %d\n", isupper('}'));
	printf("\t'@': %d\n", isupper('@'));
	printf("\nReproduction:\n");
	printf("\t'A': %d\n", ft_isupper('A'));
	printf("\t'B': %d\n", ft_isupper('B'));
	printf("\t'H': %d\n", ft_isupper('H'));
	printf("\t'Z': %d\n", ft_isupper('Z'));
	printf("\t'a': %d\n", ft_isupper('a'));
	printf("\t'b': %d\n", ft_isupper('b'));
	printf("\t'h': %d\n", ft_isupper('h'));
	printf("\t'z': %d\n", ft_isupper('z'));
	printf("\t'0': %d\n", ft_isupper('0'));
	printf("\t'5': %d\n", ft_isupper('5'));
	printf("\t'9': %d\n", ft_isupper('9'));
	printf("\t'}': %d\n", ft_isupper('}'));
	printf("\t'@': %d\n", ft_isupper('@'));
}