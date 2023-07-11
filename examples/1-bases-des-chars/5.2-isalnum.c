#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool	ft_isalnum(char c)
{
	return (
		('A' <= c && c <= 'Z')
		|| ('a' <= c && c <= 'z')
		|| ('0' <= c && c <= '9')
	);
}

int	main(void)
{
	printf("Original:\n");
	printf("\t'A': %d\n", isalnum('A'));
	printf("\t'B': %d\n", isalnum('B'));
	printf("\t'H': %d\n", isalnum('H'));
	printf("\t'Z': %d\n", isalnum('Z'));
	printf("\t'a': %d\n", isalnum('a'));
	printf("\t'b': %d\n", isalnum('b'));
	printf("\t'h': %d\n", isalnum('h'));
	printf("\t'z': %d\n", isalnum('z'));
	printf("\t'}': %d\n", isalnum('}'));
	printf("\t'@': %d\n", isalnum('@'));
	printf("\nReproduction:\n");
	printf("\t'A': %d\n", ft_isalnum('A'));
	printf("\t'B': %d\n", ft_isalnum('B'));
	printf("\t'H': %d\n", ft_isalnum('H'));
	printf("\t'Z': %d\n", ft_isalnum('Z'));
	printf("\t'a': %d\n", ft_isalnum('a'));
	printf("\t'b': %d\n", ft_isalnum('b'));
	printf("\t'h': %d\n", ft_isalnum('h'));
	printf("\t'z': %d\n", ft_isalnum('z'));
	printf("\t'}': %d\n", ft_isalnum('}'));
	printf("\t'@': %d\n", ft_isalnum('@'));
}