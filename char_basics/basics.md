
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

La fonction putchar est la premiere fonction a laquelle nous avons affaire 