#include <stdio.h>

int	main(void)
{
	unsigned char	c;

	// Erreur de compilation : overflow à +127
	// c = -129;
	// printf("-129: %d\n", c);
	c = -128;
	printf("-128: %d\n", c);
	c = -127;
	printf("-127: %d\n", c);
	c = -1;
	printf("-1: %d\n", c);
	c = 0;
	printf("0: %d\n", c);
	c = 127;
	printf("127: %d\n", c);
	c = 128;
	printf("128: %d\n", c);
	c = 255;
	printf("255: %d\n", c);
	// Erreur de compilation : overflow à 0
	// c = 256;
	// printf("256: %d\n", c);
}
