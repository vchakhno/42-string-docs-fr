# Les chars

Les <i>chars</i> en C sont un type de donnée contenant une valeur entière(1, 45, 30 etc..), représenté par une série de 8 bits stockés en mémoire.<br>

```c
char random = 97 # represents the character 'a' in ASCII
```

Ici, à l'adresse mémoire de notre variable `random`, sera stocké notre entier `97` en une série de 8 bits représentant notre valeur, soit : `0110 0001`

Etant limité à 8 bits, nous sommes donc intrinséquement limité à 256 valeurs différentes représentable. De l'entier `0` représenté en binaire par `0000 0000` - à l'entier `255` représenté en binaire par `1111 1111`.[^1]

On pourrait aussi écrire indiqué le caractère que l'on souhaite stocké directement durant l'initialisation :

```c
char random = 'a'
```

Ici, votre compilateur C remplaçera `'a'` par la valeur entière [ASCII](chars/ascii.md) correspondante, soit `97`. 'a' est un `character literal` et nous verront cela plus en détail dans la suite de ce chapitre

Nous aurions pu aussi indiqué une valeur binaire, hexadecimal, octal etc:

```c
char random_bin = 0b01100001; # binary
char random_hex = 0x61; # hexadecimal
char random_oct = 0141; # octal
```

Ici toutes ces valeurs en hexadécimal/binaire/octal représentent ultimement l'entier `97`, et seront stockés en mémoire sur 8 bits par la même valeur: `0110 0001`
<hr>

[^1]: Il existe une notion de `type signé` et `type non-signé` qui changeront cette plage d'entier, et nous verront cela dans un autre chapitre.