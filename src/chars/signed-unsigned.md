> `char` et `signed char` sont <ins>équivalent</ins>. Ils seront utilisé inter-changeablement le long de ce chapitre, par soucis de clarté. Il n'y a pas de différence entre ces deux termes. Un char est considéré signé, sauf s'il est explicitement indiqué `non-signé`

# Quelle différence entre signé et non-signé ?<br><br>

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
Nous aurions pu indiqué à notre programme, qu'au moment de comparer les deux valeurs, nous voulions que toutes deux soient interpréter comme des `char signé` :

```c
signed char		a = 0b10000000;
unsigned char 	b = 0b10000000;

if (a == (signed char)b)
	printf("égalité\n");
```

Grâce à ce `cast` explicite, nous avons indiqué que `b` au moment de sa comparaison avec `a`, devrait être considérer en tant que `char signé`, et nous passeront dans la condition.