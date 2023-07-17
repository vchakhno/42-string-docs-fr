
# Bases des chars

## Character Literals

### Qu'est-ce qu'un literal?

Un **literal** est, en programmation informatique, une valeur **fixe** dans le code source d'un programme.
Par exemple, lorsqu'on ecrit l'assignement `int x = 1;`, la valeur 1 est un "integer literal".
La notion de literal s'oppose donc a celle de variable. Definissons la fonction suivante, pour clarifier l'idee de literal.
```
int	foo(int x)
{
	return (x + 2);
}

int	main(void)
{
	x = foo(3);
	return (0);
}
```
Dans le programme precedent, 3 est un integer literal (une valeur fixe dans le code source) tandis que foo(3), bien que valant toujours 5, n'est pas ecrite telle qu'elle dans le code source et n'est donc pas un literal

### Donc, c'est quoi un character literal?

Comme son nom l'indique maintenant, un character literal est un caractere dont la valeur est ecrite telle qu'elle dans le code source. Par exemple `char c = 'a';`
Il existe plusieurs types de character literals :
- Character literals Ordinaires (ex : `'a'` ou `'\n'` ou `'\13'`)
- UTF-8 (ex : `u8'a'`)
- UTF-16 (ex : `u'猫'`)
- UTF-32 (ex : `U'🍌'`)
- Wide character literals (ex : `L'β'`)
- Multi character constants (ex : `'AB'`) que nous ne detaillerons pas ici car elles ne sont pas portables et peuvent mener a de graves confusions (notamment parce que leur implementation depend du systeme d'exploitation utilise)

Dans cette partie, nous nous concentrerons sur les character literals ordinaires. Nous verrons comment les afficher et les manipuler, ainsi que certain caracteres speciaux que nous manipulons tres souvent en programmation.

## Affichage d'un charactere

### (ft_)putchar

La fonction putchar est la premiere fonction a laquelle nous avons affaire quand il s'agit d'afficher un charactere sur la sortie standard.
Voici son prototype :`int putchar(int c)`. Pour utiliser cette fonction nous passons en parametre un entier entre 0 et 127 que celle-ci affichera sur la sortie standard.

> ### Note pour les etudiants de 42
> On note ici la difference avec la fonction ft_putchar apprise en Piscine. Voici pour rappel son prototype : `void ft_putchar(char c)`.
> -La premiere difference dans le type de retour vient du fait que la fonction putchar permet de detecter une eventuelle erreur lors de l'ecriture (en renvoyant 0 si le charactere n'a pas pu etre ecrit
> -La seconde difference vient des debuts du C. A l'epoque de la creation du C, il n'y avait que deux types : `int` et `double`.
> Tous les characteres qui n'etaient pas des `double` etaient donc stockes comme des `int`. Ainsi, pour des raisons de compatibilite, il est maintenant inscrit dans le standard C que les types plus petits qu'un `int` sont automatiquement convertis en `int` lors d'appels a une fonction ou lors de l'application d'operateurs (`+` ou `&&` par exemple).

### printf
Il est egalement possible d'afficher un charactere grace a la fonction `printf`. Nous donnerons ici un prototype qui, sans etre le vrai prototype de la fonction printf, illustre l'utilisation qu'on en fait pour afficher un caractere. `int printf("%c", int c)`.
Le `man 3` pour la fonction `printf` nous specifie que, comme pour la fonction putchar presentee plus haut et pour les memes raisons, l'argument `c` est converti de `int` a `unsigned char` et affiche sur la sortie standard.

## Lecture d'un charactere

### getchar

Comme fonction reciproque de la fonction putchar, la fonction getchar nous permet de lire un charactere depuis l'entree standard.
Voici son prototype : `int getchar(void)`. Celle-ci nous renvoie le charactere lu depuis l'entree standard ou EOF (un charactere special qui sera detaille dans la section suivante) en cas d'erreur de lecture.

> A ce stade, des cas d'erreur ont ete mentionne sans pour autant etre detailles avec precision. Ils ne rentrent pas dans le cadre de cette partie et ne seront donc pas expliques pour le moment.
> Meme si vous ne les comprenez pas encore, gardez cependant en tete que : En C, il peut ***toujours*** y avoir une erreur.

### scanf

La fonction scanf fonctionne elle aussi comme une fonction reciproque de la fonction printf.
Comme pour la fonction printf, on donnera ici un faux prototype pour illustrer la facon dont on peut s'en servir pour lire un charactere : `int scanf("%c", char *c)`. La fonction scanf prend donc un pointeur sur un char dans lequel sera stocke le charactere que l'on souhaite lire.
Cette fonction renvoie (dans l'exemple ci-dessus) 1 si la lecture s'est bien passe ou EOF en cas d'erreur.

## La table ASCII

### Presentation

Implementee pour la premiere fois en 1963 (bien que le travail ait commence en 1961), la table ASCII avait pour de donner un encodage unique au symboles de l'alphabet anglais. Elle est encodee, dans sa forme la plus communement presentee (et dans le `man ascii`) sur 7 bits.
Les valeurs allant de 0 a 31 ainsi que la valeur 127 sont reservees aux characteres de controle.
Les valeurs allant de 32 a 126 sont reservees aux characteres imprimables.

#### Les characteres de controle

Ces characteres etaient a l'origine utilises pour controller les appareils (par exemple les imprimantes) qui utilisaient la table ASCII. Les characteres importants a connaitre en C sont :
- `NUL` : Code ASCII (0), il se note `^@` et s'ecrit `'\0'` ou `0` dans le code source d'un programme C. Il est maintenant utilise pour indiquer la fin d'une chaine de characteres
- `^C` : Code ASCII (3) . Signifiant a l'origine la fin d'un texte, il est maintenant utilise pour envoyer un `SIGINT` a un programme C en cours d'execution
- `EOT` : Code ASCII (4). Le charactere de fin de transmission. Note `^D`. Le `^D` sert maintenant a envoyer un EOF a un programme C lors de la lecture (depuis un fichier ou l'entree standard).
- `BS` : Code ASCII (8). Le backspace. Note `'\b'` dans le code source d'un programme C, ce charactere permet de bouger le curseur d'un charactere en arriere si le charactere precedent n'est pas un `'\n'`
- `HT` : Code ASCII (9). La tabulation horizontale. Note `'\t'` dans le code source d'un programme C, ce charactere permet de bouger le curseur jusqu'au prochain "tabstop" sur la ligne.
- `LF` : Code ASCII (10). Le retour a la ligne. Note `'\n'` dans le code source d'un programme C, ce charactere permet de bouger le curseur jusqu'a la ligne suivante.
- `FF` : Code ASCII (12). Form feed ou saut de page. Permettait a l'origine d'indiquer a l'appareil le lisant de passer a une nouvelle page. Note `'\f'` dans le code source d'un programme C, il permet maintenant de passer a la ligne suivante tout en restant au meme niveau dans la ligne que sur la ligne precedente (voir programme en exemple pour clarification).
- `CR` : Code ASCII (13). Le retour charriot. Note `'\r'` dans le code source d'un programme C, il permet de replacer le curseur au debut de la ligne (permettant ainsi d'ecraser un a un les characteres deja affiches avec des nouveaux).

> Note sur le charactere `EOF` :
> Le charactere `EOF`(end of file) n'est pas present dans la table ASCII de base. En C, il est defini comme un charactere negatif sans valeur imposee et sert a indiquer l'absence de donnees supplementaires lors de la lecture.

#### Les characteres imprimables

Les characteres imprimables de la table ASCII commencent par l'espace Code ASCII (32) et se terminent par `'~'`.

> Note sur les digraphes et les trigraphes
> Les langages de programmation anterieurs au C et le C lui-meme ont introduit des characteres qui n'etaient a l'origines pas disponibles sur tous les claviers d'ordinateurs (comme `'{'`, `'['` ou '#'). Pour pallier a ce probleme, des combinaisons de characteres furent rendues interpretables par le preprocesseur.
>> Les *digraphes* sont des sequences de deux characteres ayant pour but de remplacer les characteres manquant sur les claviers de l'epoque. Voici par exemple ceux pour les accolades et pour les crochets:
>>- `<%` correspond a `{` et `%>` correspond a `}`
>>- `<:` correspond a `[` et `:>` correspond a `]`
>>L'ecriture `char str<::> = "Hello World";` est donc parfaitement equivalente `char str[] = "Hello World";`
>>Les digraphes sont toujours interpretes par les compilateurs modernes mais ne sont pas consideres comme valides par la norme de 42.
>> Les *trigraphes* sont des sequences de trois characteres visant au meme but de remplacer les characteres manquant. Ils commencent tous par deux ? et se terminent par un charactere qui represente le signe de ponctuation qu'ils remplacent. Voici de meme, ceux pour les accolades et les crochets:
>>- `??)` correspond a `)` et `??(` correspond a `[`
>>- `??<` correspond a `{` et `??>` correspond a `}`
>>Les trigraphes, quant-a-eux, ne sont plus consideres comme valides par les compilateurs (gcc genere un warning et necessite d'ajouter un flag pour la compilation, tandis que clang genere une erreur).

### Exercice