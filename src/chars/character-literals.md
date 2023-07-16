Un <i>character literal</i> est simplement un caractère [ASCII](chars/ascii.md), délimité par des single quotes (`'`).

Durant l'introduction à ce chapitre nous avons pu voir différentes manière de stocker un même entier dans une variable de type `char`: 
```c
char random_bin = 0b01100001; # binary
char random_hex = 0x61; # hexadecimal
char random_oct = 0141; # octal
char random_char = 'a'; # ASCII character
char random = 97;
```

Dans ce cas précis : `char random_char = 'a'`, `'a'` est donc un <i>character literal</i>.
Votre compilateur C le remplaçera par sa valeur entière correspondante dans la table [ASCII](chars/ascii.md), soit `97`. 

La table [ASCII](chars/ascii.md) étant limité par un set de caractères assez réduit, s'il vous venait à l'idée de stocker un `é` par exemple, vous vous retrouverez très vite avec un avertissement voire une erreur de votre compilateur.

Il existe ainsi les `wide character literals`, qui eux permettent de représenter un set de caractère beaucoup plus large, grâce à la table `Unicode`.

Leur syntax est est similaire, nous ajoutons simplement un `L` :
```c
wchar_t random = L'\u00E9';
```

Nous aborderont les `wide character literals` dans un prochain chapitre.