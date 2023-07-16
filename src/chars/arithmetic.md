Il existe une famille de type contenant des valeurs représentant des entiers : `long`, `int`, `short`, `char`, `long long` (ainsi que leur version non-signé)
<br>
Plusieurs opérations arithmétique entre des données de ces types `entiers` sont possible en C : Les additions, soustractions, multiplications, divisions, modulo, incrémentation et décrémentation :

```c
char random = 97;
char random_hex = 0x61 # 97;
char result;

result = random + random_hex; # addition
result = random * random_hex; # multiplication
result = random % random_hex; # modulo
result = random++; # incrémentation
result = random--; # décrémentation
```

Si vous effectuez une opération arithmétique entre un entier et un pointeur, votre compilateur n'utilisera plus l'arithmetique des entiers, et utilisera l'arithmétique des pointeurs, dans laquelle par exemple la multiplication n'est pas disponible, et où les additions et autres opérations peuvent être interprété d'une manière différente

Exemple :
```c
int tab[2] = {0, 1};
char c = 1;
int	*result;

printf("Before:%p\nAfter:%p\n", tab, tab + c);
```

Output:
```python
Before:0x7ffc12d98e60
After:0x7ffc12d98e64
```

On peut voir que l'opération `tab + c` n'a pas ajouté 1 (la valeur de `c`) à tab , mais bien 4 !
<br>
Car nous ne sommes plus dans l'arithmétique des entiers, mais l'arithmétique des pointeurs. Tout cela est régis par votre compilateur. Nous décrirons l'arithmétique des pointeurs dans le chapitre [Les bases des strings](../strings-basics.md)