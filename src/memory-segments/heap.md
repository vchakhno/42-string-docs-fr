# La heap

<p>
	Ce segment quant à lui représente une partie de la mémoire dynamique de votre programme, celle que demanderez au cours de son exécution, généralement grâce à malloc.
	<br><br>
	Il démarre après les <i>data segments</i>(.text, .data, .bss..) et sa fin est indiqué par le pointeur <b>Program Break</b>*
</p>

## Malloc

### Petites allocations, (s)brk et Program Break

<p>
	Malloc utilisera la heap pour vous petites(<130 KB)* allocations de mémoire. Les plus grosses quant à elles, allouées grâce à <b>mmap()</b>, ne seront pas dans une région spécifique de la mémoire.
	<br><br>
	Dans le cas de ces petites allocations, malloc utilisera la fonction <b>sbrk()</b> et <b>brk()</b>*, toutes deux servant à manipuler le pointeur <b>Program Break</b>, qui comme indiqué plus haut, indique la fin de la heap. En incrémentant l'adresse qu'elle contient grâce à <b>sbrk()</b>, on redéfinit ainsi la fin de la heap, et pouvons ainsi y stocker plus de données.
	<br><br>
	Ce pointeur spécial est géré par l'OS*, qui lorsque vous le changerez, gérera lui seul la manière dont il mappera, et allouera effectivement la mémoire physique pour votre programme.
	<br><br>
	De la même manière, on peut décrémenter cette adresse pointé par <b>Program Break</b>, et ainsi <i>décroître</i> la taille de la heap.
	<br><br>
	Utiliser malloc revient à abstraire cette gestion complexe de la heap.
</p>


### Autres allocations, mmap

<b>\*</b> <span style="color: grey;font-style: italic"> Peut varier selon votre distro linux, de l'implémentation de malloc que vous utilisez et de sa configuration. </color></span>