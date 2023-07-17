## Manipulation des chars

Je pense qu'on peut féliciter la rédaction de cette doc pour avoir réussi à cacher tout ce temps que les chars sont... des nombres.

*Quoi comment ça ?*

En fait, les `char`, tout comme les `int` font partie des types qui représentent des nombres entiers. Les `char` en particulier sont le type C le petit en mémoire : ils prennent sur la quasi totalité des machines seulement 8 bits.

On a vu comment les utiliser avec des symboles, mais les chars peuvent aussi stocker des nombres :

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c = 42;

	printf("%d\n");
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
42
$
```

On a vu tout à l'heure `"%c"` qui permet d'afficher un caractère, voici `"%d"` qui permet d'afficher un nombre.

*Donc un char peut stocker soit un symbole soit un nombre ?*

Non, c'est plus les deux à la fois. En fait chaque nombre correspond à un symbole. C'est aussi ce qu'il y avait dans la table ASCII, si vous êtes allé y jeter un oeil plus tôt. Par exemple, le symbole `A` correspond à la valeur `95`.

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c = 'A';

	printf("%c\n");
	printf("%d\n");
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
A
95
$
```

J'ai mentionné que les chars étaient le plus petit type en mémoire. Ce qui veut aussi dire qu'ils ne peuvent pas représenter beaucoup de nombres.

Comme les chars n'ont que 8 bits, il y a 2^8 combinaisons. Donc 256 nombres possibles.
- Pour les `signed char`, les valeurs vont de `-128` à `127`.
- Pour les `unsigned char`, les valeurs vont de `0` à `255`.
- Pour les `char` ... ça dépend. Le standard ne spécifie par si ils sont signés ou non par défaut. Mais je les ai vus plus souvent signés.

Comme pour des `int`, on peut effectuer des opérations arithmétiques sur les `char`. Je vais vous épargner tout l'exemple, mais on peut utiliser `+`, `-`, `*`, `/`, `%`... et d'autres.

Ce qui est interressant, c'est que ces calculs ont donc un impact sur le char représenté. Par exemple `++` fait passer au prochain caractère de la table ASCII. Et comme les caractères sont ordonnés alphabetiquement, on peut d'en servir pour afficher l'alphabet :

*main.c*
```c
#include <stdio.h>

int main(void)
{
	for (char c = 'A'; c <= 'Z'; c++)
		printf("%c", c);
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
ABCDEFGHIJKLMNOPQRSTUVWXYZ$
```

Malheureusement les __symboles__ de `0` à `9` ne correspondent pas à la valeur `0` à `9`, mais `48` à `57`. Pour afficher un nombre entre `0` et `9` sans passer par `printf %d`, on peut donc lui ajouter `48` et le print en tant que char.

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c = 7;

	printf("%c\n", c + 48);
	printf("%c\n", c + '0'); // équivalent
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
7
7
$
```

Toujours d'après la table ASCII, on peut voir que l'alphabet minuscule est décallé de 32 après l'alphabet majuscule. On peut exploiter ça pour faire notre version de la fonction `tolower`, présente dans la libft sous le nom `ft_tolower`.

*main.c*
```c
#include <stdio.h>

char ft_tolower(char c)
{
	if ('A' <= c || c <= 'Z')
		return (c - 'A' + 'a'); // aussi écrivable c + 32
	return (c);
}

int main(void)
{
	printf("%c", ft_tolower('M'));
	printf("%c", ft_tolower('A'));
	printf("%c", ft_tolower('J'));
	printf("%c", ft_tolower('U'));
	printf("%c", ft_tolower('S'));
	printf("%c", ft_tolower('C'));
	printf("%c", ft_tolower('U'));
	printf("%c", ft_tolower('L'));
	printf("%c", ft_tolower('E'));
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
majuscule$
```

> Résumé :
> - Les chars sont en fait des entiers numériques.
> - On peut print un entier avec `printf %d`
> - On peut vérifier ou changer la nature d'un char selon sa position dans la table ASCII

> Petits exercices :
> - Implémenter `isalnum`, `isspace`, `tolower`
> - Utiliser les parties d'avant pour implémenter un cat qui répète tout en majuscule
> - Bonus : Faire une fonction qui lit un int depuis l'entrée standard avec seulement `getchar`.
