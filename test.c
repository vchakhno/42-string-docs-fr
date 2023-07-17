#include <stdio.h>

int	main(void)
{
	signed char		a = 0b10000000;
	unsigned char 	b = 0b10000000;

	if (a == (signed char)b)
		printf("égalité\n");
	printf("%u %d", b, a);
	return (0);
}
