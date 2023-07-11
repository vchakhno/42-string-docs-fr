#include <stdio.h>

int	main(void)
{
	// On cherche a print une quote simple
	// Ne compile pas
	// putchar(''');
	// Doit être écrit comme ça :
	putchar('\'');
	
	// On cherche a print un backslash	
	// Ne compile pas : 
	// putchar('\');
	// Doit être écrit comme ça :
	putchar('\\');

	// Pour que le prompt du terminal s'affiche correctement
	putchar('\n');
}
