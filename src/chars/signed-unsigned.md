# Quelle différence entre signé et non-signé ?<br><br>

## Dans la représentation décimal d'une donnée en mémoire
-

## Dans la mémoire
Si l'on stock la valeur binaire `0101 1111` dans un char signé ou non-signé, en mémoire on aura toujours `0101 1111`. Il n'y a donc là aucune différence.

## Dans votre programme
Prenons un exemple :

```c
signed char		a = 0b10000000;
unsigned char 	b = 0b10000000;

if (a == b)
	printf("égalité\n");
```

Ici, nos variables `a` et `b` contiennent toutes deux <ins>en mémoire</ins> le byte `1000 0000`.<br>
Cependant notre programme lui va interpréter cette donnée en mémoire, selon le type de la variable.<br><br>
Pour un type `char signé` notre programme considérera que la donnée `1000 0000` équivaudra à l'entier `-128`. Mais pour un type `char non-signé` alors notre programme considérera que cette même donnée équivaudra à l'entier `128`.<br><br>
Et donc quand il compare les deux valeurs, pour lui, elles ne sont pas égales. Car il ne compare pas la donnée en mémoire, mais la représentation de cette donnée qu'il en fait.<br><br>
Nous aurions pu indiquer à notre programme, qu'au moment de comparer les deux valeurs, nous voulions que toutes deux soient interpréter comme des `char signé` :

```c
signed char		a = 0b10000000;
unsigned char 	b = 0b10000000;

if (a == (signed char)b)
	printf("égalité\n");
```

Grâce à ce `cast explicite`, nous avons indiqué que `b` au moment de sa comparaison avec `a`, devrait être considérer en tant que `char signé`, et nous passeront ainsi dans la condition.

# Char, signed char, équivalent ?

Cela dépend majoritairement de votre compilateur, il n'y a pas de bonne réponse ici. Si vous utilisez `gcc` vous pouvez utiliser pouvez utiliser le flag `-fsigned-char` ou `-funsigned-char` pour indiquer si `char` est par défaut signé ou non-signé.