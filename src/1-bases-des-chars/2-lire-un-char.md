## Lire un char depuis la console

On a vu qu'il existait les fonctions `putchar` et `printf` pour écrire dans la sortie standard. On va maintenant s'occuper de leurs doubles maléfiques, `getchar` et `scanf`, qui lisent des chars depuis l'entrée standard. Voici un programme qui lit un seul caractère en utilisant `getchar`.

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c;

	c = getchar();
	putchar(c);
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
Bouh
B$
```

(Ici c'est l'utilisateur qui a tapé `Bouh`)

Je vous conseille de lancer ce programme pour mieux voir ce qu'il se passe. En fait, lors du `getchar`, le programme se met en attente. On peut tapper des caractères, mais c'est que quand on appuie sur `entrée` qu'ils sont réellement envoyés au programme.

À noter que quand on tappe plusieurs caractères, ils sont conservés dans le buffer de l'entrée standard. Un buffer - en français tampon - désigne un tableau par lequel transitent les données. C'est à dire que quand on tape une ligne, comme Bouh, des appels successifs à `getchar` vont récupérer successivement `B` - `o` - `u` - `h` - `\n`. Et ensuite, si on continue de lire avec `getchar`, le programme va a nouveau attendre que l'utilisateur tape un message.

Par exemple, si on veut faire le perroquet, comme le programme `cat`, il suffit d'enchainer `getchar` et `putchar` :

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c;

	while (1)
	{
		c = getchar();
		putchar(c);
	}
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
Bouh
Bouh
Bonjour
Bonjour
^C
$
```
*Utilisez CTRL-C pour mettre fin au programme.*

CTRL-C tue directement le programme. C'est un peu violent comme manière d'arrêter d'écrire. Et notre programme n'est pas exactement comme `cat` en fait. En realité, il existe un raccourci terminal pour indiquer qu'on a fini d'écrire : CTRL-D. Ce raccourci permet d'arrêter le programme `cat`.

CTRL-D agit en temps normal comme le saut de ligne : il envoie au programme le texte écrit - mais sans saut de ligne. Si la ligne est vide, alors CTRL-D *ferme l'entrée standard*.

Mais si l'entrée standard est fermée, alors qu'est ce que retourne `getchar` dans ce cas ? D'après le man de `getchar`, quand il y a une erreur ou une fin de fichier, `getchar` return *EOF*. EOF est une constante pour `-1`, définie dans `stdio.h`, et dont le nom signifie *End Of File*. Donc après avoir reçu un CTRL-D sur une ligne vide, `getchar` nous retourne *EOF*.

*`getchar` nous retourne un caractère, donc à quel caractère correspond EOF ?*

Aucun, `-1` n'est pas un caractère valide, et ne fait pas partie de la table ASCII. Donc le print nous affiche un symbole non trouvé �. Donc avant d'afficher notre caractère tout à l'heure, on aurait du s'assurer qu'ont ait pas reçu EOF. Vous pouvez revenir sur les exemples précédents et taper CTRL-D pour voir le problème.

Voici donc notre pseudo-cat corrigé :

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c;

	c = getchar();
	while (c != EOF)
	{
		putchar(c);
		c = getchar();
	}
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
Un 
Un
Deux
Deux
Trois
Trois
$
```

*Ici on a utilisé CTRL-D pour correctement finir le programme*

[Un mot à propos des accents qui fonctionnent dans le pseudo-cat ?]

Niquel, vous savez maintenant récupérer un char dans l'entrée standard. Mais je sens qu'on a oublié quelque chose au passage... Ah mince, `scanf` ! Reprenons le dernier exemple mais en l'utilisant.

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c;

	while (scanf("%c", &c) != EOF)
		printf("%c", c);
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
Un 
Un
Deux
Deux
Trois
Trois
$
```
*Oulah ça a un peu changé.*

Oui, j'en ai profité pour mettre un `printf` aussi. 

La différence notable est que `scanf` ne return pas un char. `scanf` lit l'entrée standard et enregistre le résultat dans le ou les pointeurs qu'on lui donne en paramètre (à la suite du string de format). Pour indiquer une erreur ou une fin de fichier, `scanf` return EOF, comme `getchar`. Pour indiquer une réussite, `scanf` return le nombre de formats correctement lus (dans notre cas, un seul).

Sinon rien de particulier, les deux exemples sont strictement équivalents, c'est juste une autre manière de l'écrire. Et tout comme pour `printf`, `scanf` est bien plus populaire que `getchar`.

> Résumé :
> - On peut lire un char avec `c = getchar('A')` ou `scanf("%c", &c)`
> - Les caractères qu'ont tapé l'utilisateur sont envoyés que après un saut de ligne ou un CTRL-D.
> - Une fois reçus, ils sont stockés dans le *buffer de l'entrée standard* et lus petit à petit.
> - Si le buffer de l'entrée standard est vide, le programme attend que l'utilisateur tape autre chose.
> - Si l'utilisateur tape CTRL-D sur une ligne vide, alors l'entrée standard est fermée et `getchar` et `scanf` renvoient une erreur : EOF.
