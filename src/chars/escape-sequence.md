# Séquence d'échappements

Les séquences d'échappements sont des suites de caractères qui représentant certains caractères spéciaux, qui ne pourraient autrement pas être facilement représenté par un programmeur<br><br>
Ils commencent forcément par un backslash `\` et sont suivi par un ou plusieurs caractères. Il est important de noté qu'une séquence, exemple `\n`, sera remplaçé par votre compilateur par leur valeur décimal correspondante. `\n` sera remplaçé par l'entier `10`, et c'est cet entier qui sera stocké en mémoire(sur 8 bits toujours).<br><br>
Pour illustrer cela, un exemple :
```c
char c = '\n';
char b = 10;
```
`c` et `b` sont égaux, ils contiennent tout d'eux en mémoire l'entier 10, il n'y a aucune différence entre eux. L'entier `10` représente un saut de ligne, et `\n` sera remplaçé par l'entier `10` par votre compilateur.<br>
Au moment d'afficher cet entier à l'écran, grâce à `printf()`, `putchar()` ou tout autre fonction, ce sont ces fonctions qui se chargeront de représenter visuellement ce saut de ligne.<br><br>
Il est intéressant de noter qu'il n'est pas tout le temps question uniquement de représentation visuel. La séquence d'échappement `\a` (sa valeur décimal est `7`) par exemple, permet lorsqu'elle est imprimé à l'écran avec `printf`, d'émettre une alerte sonore. Rien ne sera visuellement affiché.<br><br>
Voici une liste non-exhaustive de séquences d'échappement:

| Escape sequence | Description |
| :----: | :--- | 
| \n | Saute à la ligne |
| \0 | Représente le caractère null, qui en C représente typiquement la fin d'un chaîne de caractère |
| \t | Tabulation |
| \r | Retour chariot. Déplace le curseur au début de la ligne actuel  |
| \a | Emet une alerte sonore  |

# Séquence d'échappement Octal / Hexadecimal

En addition des séquences classique d'échappements représentés par un `\` suivi d'un caractère (`\n`, `\?`, `\'`, `\t` etc), il existe aussi les séquences d'échappements commençant par un `\` suivi d'une valeur hexadécimal ou octal.

Pour l'octal : `\ooo` où `ooo` représente jusqu'à trois chiffres en octal. <br>
Pour l'hexadécimal : `\xHH` où `HH` représente jusqu'à deux chiffres en hexadécimal

Les valeurs octals/hexadécimal de ces séquences ne peuvent dépasser `255`, soit la même plage de valeurs possible pour 1 byte de donnée ! Coïncidence ?!<br>
Donc `\xFF` est le maximum pour les séquences en hexa (`FF` représente la valeur décimal 255). Et `\377` le maximum pour celles en octal (En octal `377` représente aussi la valeur décimal `255`)<br>
Indiquer une valeur supérieur entraînera un avertissement de votre compilateur.<br><br>
Il existe d'autres séquence d'échappements, notamment celle `unicode` mais nous ne les aborderont pas ici.
