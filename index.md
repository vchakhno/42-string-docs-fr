## Bases des chars
### Description
Cette partie explique l'utilisation la plus basique des chars. Normalement l'écrasante majorité des studs a déjà ces notions.
### Placement et utilité
En tout premier, logiquement. C'est un chapitre essentiel.
### Notions
- character literals
- print un char dans la sortie standard avec `putchar` et `printf %c`
- read un char dans l'entrée sortie standard avec `getchar` et `scanf %c`
- mini-cat (boucle avec getchar-putchar) (pas essentiel mais sympa)
- table ASCII
- sequences d'échappement communes (`\n`, `\'`, `\\`, `\t`) 
- intervalle, `signed`, `unsigned`
- arithmetique
- fonctions typiques sur les chars (isupper, isalnum, isspace)

## Bases des strings
### Description
Fondamentaux des strings. On se concentre sur l'utilisation et pas la manipulation. Je ne sais pas si je mets l'écriture (dans le sens modification, pas print) dedans où dans une partie plus tard.
### Placement et utilité
Vient après les Bases des chars. Chapitre essentiel.
### Notions
- string literals
- print un string dans la sortie standard avec `puts` et `printf %s`
- read un string dans l'entrée standard avec `gets` et `scanf %s`
- représentation mémoire (avec le \0)
- fonctions typiques sur les strings (strlen, stcmp, atoi)
- essai d'écrire dans `char *str = ""`. introduction de `char str[] = ""` juste pour permettre l'écriture (str_toupper)

## Arithmetique de pointeurs
### Description
Manipulation directement du pointeur des `char`. Juste avec des strings simples pour l'instant, pas de tableaux de strings.
Je suis pas sur de la pertinence/importance des sous parties.
La notion sur memset aurait peut-être sa place dans une autre partie.
### Placement et utilité
Doit bien sur être après les Bases des strings, mais pas necessairement collé. On peut déplacer cette partie jusqu'avant les tableaux de strings. Ce chapitre est pas essentiel, mais bizarrement très demandé de ce que j'ai vu dans des conversations. J'ai l'impression qu'il y a pas grand chose à dire donc j'ai peut-être oublié des choses importantes.  
### Notions
- Notation `*(str + i)`
- Bouger le pointeur de str directement (strchr)
- `++str` vs `str++`
- `(*str)++` vs `*str++` vs `*(str++)`
- Utiliser les `char *` pour remplacer byte par byte (memset)

## Tableaux de chars (déclaration)
### Description
Parle de détails de la déclaration des tableaux de chars. Ne parle pas de leur lifetime, c'est abordé dans un autre chapitre. Les tableaux sont syntaxiquement assez rigide donc il y a plusieurs règles à suivre.
### Placement et utilité
Doit suivre les Bases des chars, pour comparer avec les `char *` qui sont immutables. Doit précéder les string alloués pour comparer avec leur taille dynamique.
### Notions
- uniquement `char str[] = "..."` ou `char str[] = {...}`, y assigner un `char *` ou un `char []` provoque une erreur de compilation
- on ne peut pas séparer la définition de la déclaration, une fois déclaré on ne peut pas assigner à un `char []`
- taille déduite à la compilation si est omise.
- le string est tronqué si la taille est trop petite
- si la taille est trop grande, rien de particulier juste plus de place
- si la taille dépend d'une variable, ça créé un VLA (peut-être pour plus tard ?)
- comme montré précédemment, modifiable
- peut-être d'autres notions, comme print les addresses pour montrer que les chars sont sur la stack

## Strings const
### Description
Partie à propos du __modifier__ const. Pas des string literals, qui sont pas écrivables. Mais des strings qui ont const dans leur déclaration. C'est le cas de beaucoup de fonctions de la lib standard.
### Placement et utilité
Pas grand chose à dire ici. C'est sympa de savoir les différences de placement de const, mais pas essentiel. Pareil, ce n'est peut-être pas une bonne idée de montrer maintenant qu'on peut virer le const. Je voudrais mettre des parties plus essentielles avant, mais je vois pas quoi. Et ce serait bien d'avoir plus de contenu dans celle-ci.
### Notions
- erreur de compilation si modifiés
- peuvent être lus/copiés sans problème
- `const char *str` vs `char const *str` vs `char *const str`
- cast en `char *` pour virer const

## Copie de strings
### Description
Montre comment copier le contenu d'un string à un autre.
Ça fait beaucoup d'avoir la copie du contenu, la (non-)copie à la déclaration, et les déclarations de fonctions dans le même chapitre.
### Placement et utilité
Doit être après les strings const pour montrer comment utiliser le contenu d'une string const quand même.
Doit être après les tableaux de chars, car ils servent généralement de destination à la copie.
Doit être avant les string alloués, car ils utilisent beaucoup la copie. Surtout pour les réallocations en fait, mais ça vient plus tard.
### Notions
- copie dans un buffer de taille fixe (memcpy, strcpy, strncpy)
- copie de taille dynamique (strdup)
- `char *str2 = str1;` Pas de copie, pointe vers l'original
- `char str2[] = str1;` Pas de copie, erreur de compilation.
- par contre copie valide si on copie une struct qui contient un `char [N]`
- passer un `char *` ou un `char []` en argument passe toujours le pointeur, pas une copie.
- pas possible de return un `char []` (compile pas)

## Strings alloués dynamiquement (malloc)
### Description
Les bases de malloc, dans l'utilisation on est au même niveau que la libft. Pas de réallocation, pas de structure pour conserver la len ou la capacité.
Il faut bien insister sur les leaks, le check de NULL. Montrer avec valgrind.
### Placement et utilité
Après les tableaux de strings, pour comparer la taille fixe des `char []` avec la taille dynamique donnée à malloc.
### Notions
- taille définie au runtime : malloc (sans oublier +1 pour `\0`)
- ne pas oublier de free (sinon leak !)
- ne pas oublier de vérifier le malloc !
- strdup, itoa, strjoin, strtrim, repeatstr

## Écrire/lire dans un fichier
### Description
Le nom de la partie est assez explicite. Couvre open/close et les chars.
Parler de buffered/unbuffered. Dire que c'est + efficace de faire un write plutôt que plusieurs.
### Placement et utilité
Les fd et `FILE *` sont perturbants au début, donc j'ai repoussé cette section à ici. Il n'y a pas vraiment de raison pour le placement ici spécifiquement, mais les autres chapitres étaient plus importants donc ils viennent avant.
### Notions
- `open` et `close`
- écrire un char : `write`, `dprintf %c`, `putc/fputc`, `fprintf %c` -> ft_putnbr
- lire un char : `read`, `dscanf %c`, `getc/fgetc`, `fscanf %c` -> ft_getnbr ?
- écrire un string : `write`, `dprintf %s`, `puts/fputs`, `fprintf %s`
- lire un string : `read`, `dscanf %s`, `gets/fgets`, `fscanf %s`
- peut-être des manips de fichier/fd ? (setbuf, lseek, dup, pipe...)

## Lifetime des strings
### Description
Montrer la durée de vie des strings. C'est vraiment un point important des strings à mes yeux, et des pointeurs en général. C'est une des grosses difficultés du C/C++ de savoir quand est valide un pointeur.
Normalement c'est pas necessaire jusque là, mais c'est vraiment important et un peu avancé donc je suis content d'avoir une chapitre si tardif mais si important.
### Placement et utilité
Je voulais le mettre après avoir introduit les 3 types de strings : litéraux, tableaux, dynamiques. C'est surtout important pour les tableaux donc ça serait bien qu'ils soient un peu plus reliés. C'est aussi pour ça que je l'ai mis avant les tableaux de strings, parce que sinon les utiliser c'est juste suivre une méthode toute faite, ou se tirer dans le pied.
### Notions
- lifetime des variables locales : commencer par return `&c` pour tester (erreur)
- lifetime d'un string literal ou de `char *str = ""`, global
- lifetime d'un `char str[] = ""`, local
- lifetime d'un `char *str = malloc()`, global (enfin manuel jusqu'au free)
- lifetime d'un `char str[]` en tant que variable globale
- lifetime d'un `char str[]` en tant que variable statique (/singleton)

## Tableaux de strings
Todo: beaucoup à dire mais je sais pas dans quel ordre tout mentionner. En tout cas ça me semble le bon endroit pour placer cette partie.

## Réallocation de strings
### Description
Je parle d'append à un string, style get_next_line. L'idée c'est juste de montrer comment s'implémentent les différentes méthodes et de parler des avantages et inconvénients.
### Notions
- réallocation naïve
- par puissances de 2
- par liste chainée

## Read dans un buffer dynamique
TODO
Littéralement GNL ? 

[Surement des parties ici]

## Encodages
Nécessite plus de recherche
### Notions
- unicode dans une string "😃"
- unicode en tant qu'identifier 😃 = 4
- unicode escape sequences \U, \u
- wchar_t, wide character literals L'...', wide string literals L"..."

## String literals en profondeur
### Placement et utilité
Non essentiel. Très simple. C'est plus du trivia. Peut être abordé n'importe quand, si possible après les choses réellement utiles. Pas beaucoup de contenu.
### Notions
- auto concaténation
- type `char []` et donc sizeof valide
- arithmétique de pointeur directement sur le literal
- coupure de literal avec `\0`

## Taille des char
### Placement et utilité
Ça c'est plus un errata sur la partie des bases, et un peu de trivia. Ça ne mérite pas vraiment son propre chapitre, mais ce serait bien de les ajouter pour la complétion.
### Notions
- CHAR_BIT
- char literals : `sizeof('a') == 4`
- promotion historique en int
