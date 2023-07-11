#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

bool	ft_isspace(char c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}

int	main(void)
{
	printf("Original:\n");
	printf("\t'H': %d\n", isspace('H'));
	printf("\t'Z': %d\n", isspace('Z'));
	printf("\t'h': %d\n", isspace('h'));
	printf("\t'z': %d\n", isspace('z'));
	printf("\t'}': %d\n", isspace('}'));
	printf("\t' ': %d\n", isspace(' '));
	printf("\t'\\t': %d\n", isspace('\t'));
	printf("\t'\\n': %d\n", isspace('\n'));
	printf("\nReproduction:\n");
	printf("\t'H': %d\n", ft_isspace('H'));
	printf("\t'Z': %d\n", ft_isspace('Z'));
	printf("\t'h': %d\n", ft_isspace('h'));
	printf("\t'z': %d\n", ft_isspace('z'));
	printf("\t'}': %d\n", ft_isspace('}'));
	printf("\t' ': %d\n", ft_isspace(' '));
	printf("\t'\\t': %d\n", ft_isspace('\t'));
	printf("\t'\\n': %d\n", ft_isspace('\n'));
}