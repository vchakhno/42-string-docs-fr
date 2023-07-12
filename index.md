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

## Strings const
Pas grand chose à dire ici. C'est sympa de savoir les différences de placement de const, mais pas essentiel. Pareil, ce n'est peut-être pas une bonne idée de montrer maintenant qu'on peut virer le const. Je voudrais mettre des parties plus essentielles avant, mais je vois pas quoi. Et ce serait bien d'avoir plus de contenu dans celle-ci.
- Erreur de compilation si modifiés
- Peuvent être lus/copiés sans problème
- `const char *str` vs `char const *str` vs `char *const str`
- cast en `char *` pour virer const

## Tableaux de chars
TODO

## Copie de strings
Apparemment pas dans mes notes ..? Très content d'y avoir pensé là. C'est essentiel et c'était pas couvert. Ça prend sa place juste avant les lifetime, niquel. Par contre ça fait beaucoup d'avoir la copie du contenu, la (non-)copie à la déclaration, et les déclarations de fonctions dans le même chapitre.
- Copie dans un buffer de taille fixe (strcpy, strncpy)
- Copie de taille dynamique (strdup)
- `char *str2 = str1;` Pas de copie, pointe vers l'original
- `char str2[] = str1;` Pas de copie, erreur de compilation.
- Par contre copie valide si on copie une struct qui contient un `char [N]`
- Passer un `char *` ou un `char []` en argument passe toujours le pointeur, pas une copie.
- Pas possible de return un `char []` (compile pas)

## Strings alloués dynamiquement (malloc)
Les bases de malloc, au même niveau que la libft. Pas de réallocation, pas de structure pour conserver la len ou la capacité. Montrer avec valgrind.
- Taille définie au runtime : malloc (sans oublier +1 pour `\0`)
- Ne pas oublier de free (sinon leak !)
- Ne pas oublier de vérifier le malloc !
- strdup, itoa, strjoin, strtrim, repeatstr

## Écrire/lire un char dans un fichier
TODO
### Notions
- `open` et `close`
- `write`, `dprintf %c`, `putc/fputc`, `fprintf %c`
- `read`, `dscanf %c`, `getc/fgetc`, `fscanf %c`

## Écrire/lire un string dans un fichier
TODO
### Notions
- `write`, `dprintf %s`, `puts/fputs`, `fprintf %s`
- `read`, `dscanf %s`, `gets/fgets`, `fscanf %s`

## Lifetime des strings
Peut-être un peu complexe pour être abordé tout de suite, mais c'est une notion qui m'a l'air essentielle ? Montrer avec valgrind.
- lifetime des variables locales : commencer par return `&c` pour tester (erreur)
- lifetime d'un string literal : global
- lifetime d'un `char *str = ""`, pareil donc global
- lifetime d'un `char str[] = ""`, local
- lifetime d'un `char *str = malloc()`, global (enfin manuel jusqu'au free)

## Tableaux de strings
Todo: beaucoup à dire mais je sais pas dans quel ordre tout mentionner. En tout cas ça me semble le bon endroit pour placer cette partie.

## Réallocation de strings
Je parle d'append à un string, style get_next_line. L'idée c'est juste de montrer comment s'implémentent les différentes méthodes et de parler des avantages et inconvénients.
- Réallocation naïve
- Par puissances de 2
- Par liste chainée

## Read dans un buffer dynamique
TODO

[Surement des parties ici]

## Encodages
Nécessite plus de recherche
- unicode dans une string "😃"
- unicode en tant qu'identifier 😃 = 4
- unicode escape sequences \U, \u
- wchar_t, wide character literals L'...', wide string literals L"..."

## String literals en profondeur
Non essentiel. Très simple. C'est plus du trivia. Peut être abordé n'importe quand, si possible après les choses réellement utiles. Pas beaucoup de contenu.
- auto concaténation
- type `char []` et donc sizeof valide
- arithmétique de pointeur directement sur le literal
- coupure de literal avec `\0`

## Taille des char
Ça c'est plus un errata sur la partie des bases, et un peu de trivia. Ça ne mérite pas vraiment son propre chapitre, mais ce serait bien de les ajouter pour la complétion.
- CHAR_BIT
- char literals : `sizeof('a') == 4`
- promotion historique en int
