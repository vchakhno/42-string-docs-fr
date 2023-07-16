## Bases des chars

Les strings sont des chaines de caractères. En C, les caractères sont représentés par le type `char`. Et donc pour comprendre comment fonctionnent les strings, il faut d'abord se familiariser avec les chars.

Ce chapitre couvre l'utilisation basique du type `char`, seul.

### Afficher un char dans la console

Commençons par le plus simple : afficher un char.

*main.c* :
```c
#include <stdio.h>

int main(void)
{
	char c = 'A';

	putchar(c);
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
A$
```

> **Attention :**
> Cette documentation ne couvre pas le shell, la compilation, ou les bases du C hors des strings. Si vous ne savez pas ce qu'est la fonction main, ou que vous ne comprenez pas comment est lancé l'exemple ci-dessus, il est préférable d'apprendre le C depuis une autre source, et de revenir à cette documentation une fois le sujet plus clair.

Une fois lancé, ce programme affiche le caractère écrit entre les apostrophes dans la console grâce à la fonction `putchar`. `putchar` est déclaré dans le header `stdio.h` - pour standard input/output - c'est pour ça qu'on l'inclut en haut de notre fichier. `stdio.h` fait partie de la librairie standard du C, et les fonctions à l'intérieur de ce header permettent de lire ou écrire vers la console.

On se sert souvent du terme *simple quotes* (de l'anglais) pour désigner les apostrophes. Les quotes sont necessaires pour différentier entre la lettre `A` et la variable `A`.

> En C un caractère entre simple quotes se nomme un *character literal*.

On peut utiliser d'autres caractères, et donc afficher un message, même si ce n'est pas pratique de le faire un char à la fois. D'ailleurs on peut directement remplacer `c` par le char literal pour être plus concis.

*main.c* :
```c
#include <stdio.h>

int main(void)
{
	putchar('H');
	putchar('e');
	putchar('l');
	putchar('l');
	putchar('o');
	putchar('!');
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
Hello!$
```

Mais attention, on ne peut pas mettre n'importe quel caractère dans un char literal. Par exemple on ne peut pas mettre d'accents.

*main.c* :
```c
#include <stdio.h>

int main(void)
{
	putchar('é');
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
main.c: In function ‘main’:
main.c:5:17: error: multi-character character constant [-Werror=multichar]
    5 |         putchar('é');
      |                 ^~~
cc1: all warnings being treated as errors
```
*Multi-character character constant ?*

Oui. Les caractères non-autorisés prennent en fait plusieurs "places". D'ailleurs on a le même warning on écrivant 'AA'. Mais nous nous pencherons sur ça dans un autre chapitre.

> Pour l'instant, ce qu'il faut retenir c'est que les character literals peuvent uniquement contenir des caractères de la [table ASCII]().

La table ASCII est un standard qui regroupe plusieurs symboles et leur donne une valeur unique. Malheureusement la table ASCII est plutôt petite avec ses 128 caractères et ne contient donc pas les caractères accentués.

Mais elle inclut déjà pas mal de symboles :
- l'alphabet majuscule et minuscule
- les chiffres de 0 à 9
- espace
- la ponctuation `,.;?!`
- les tirets `-` et underscore `_`
- les parenthèses `()`, crochets `[]`, accolades `{}`
- les apostrophes `''`, les guillements '""', les chevrons `<>`
- les symboles mathématiques `+-=*/%`

Et encore d'autres, visibles sur wikipedia ou dans `man ascii`.
La table ASCII contient aussi quelques bizarreries dont nous parlerons dans d'autres chapitres.

Revenons à la fonction `putchar`. En fait putchar est rarement utilisée. Déjà parce que print les chars un par un, c'est pas du tout pratique. Et aussi car pour afficher un message dans la console en C, on utilise presque toujours la fonction `printf`, qui est aussi dans `stdio.h`.

`printf` - pour print formatted - permet d'afficher non seulement des chars, mais aussi des strings, des entiers, des réels... Voici la réécriture du premier exemple en utilisant `printf`.

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c = 'A';

	printf("%c", c);
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
A$
```
Vous voyez ce `"%c"` ? Et bien c'est encore tôt, mais c'est le premier string literal qu'on utilise ! D'ailleurs `printf` est une fonction bien plus puissante que `putchar`, on peut directement lui passer un message. `printf` lit `%c` comme un *format* et le remplace directement par le caractère.

*main.c*
```c
#include <stdio.h>

int main(void)
{
	char c = 'A';

	printf("Le caractère est: %c", c);
}
```
*Terminal* :
```sh
$ gcc -Wall -Wextra -Werror main.c
$ ./a.out
Le caractère est: A$
```
Incroyable non ? Bon la plupart d'entre vous ont sûrement déjà vu un printf, donc pas si incroyable.

*Attends... il y a un accent là...?*

Eeeh oui. J'ai dit tout à l'heure que les caractères hors table ASCII prennaient plus de place, pas juste qu'ils étaient interdits. Et dans un string, et bien on a cette place :). Par contre bien sûr c'est toujours interdit de le stocker dans le `char c`. Ce n'est que la surface, on en reparlera dans un prochain chapitre.

> Résumé :
> - On peut print un char avec `putchar('A')` ou `printf("%c", 'A')`
> - Un char literal s'écrit avec un caractère de la table ASCII entre simple quotes
> - Les autres caractères sont trop gros pour aller dans un char literal (et un char tout court), mais peuvent aller dans un string
###
---
### Notions
[x] character literals
[x] print un char dans la sortie standard avec `putchar` et `printf %c`
[ ] read un char dans l'entrée sortie standard avec `getchar` et `scanf %c`
[ ] mini-cat (boucle avec getchar-putchar) (pas essentiel mais sympa)
[x] table ASCII
[ ] sequences d'échappement communes (`\n`, `\'`, `\\`, `\t`) 
[ ] intervalle, `signed`, `unsigned`
[ ] arithmetique
[ ] fonctions typiques sur les chars (isupper, isalnum, isspace)