- Bases des chars
	- character literals
	- table ascii
	- sequences d'échappement communes (\n, \t) 
	- range, signed, unsigned
	- arithmetique
- Bases des strings
	- string literals
	- print un string (write, printf)
	- représentation mémoire (avec le \0)
	- différence de base entre char str[] = "" et char *str = ""
	- fonctions typiques sur les strings (strlen, atoi, strdup)
- Arithmetique de pointeurs
	- Bouger le pointeur de str directement (strchr)
	- Notation *(str + i)
	- Utiliser les char * pour remplacer byte par byte (memset)

// Ordre pas encore défini
- Data segments
	/*
		Obligé de le placer ici pour parler de la mémoire + en détail ?
		Finalement je trouverais ça mieux de progressivement parler des différents segments au fur et à mesure
		Càd aborder `data` tôt quand on dit que la string est pas modifiable, sans détailler
		Puis parler brievement de la `stack` en disant que `char str[] = "text"` copie la string
		(sans parler des stack frame, juste dire "bon bah les variables de la stack sont stockées juste le temps de l'appel de la fonction")
		Ensuite la heap une fois sur `strdup` et `strsplit`
		(toujours sans détail, juste parler de malloc, de leak, de free, de gestion d'erreur ?)
	*/
- 
- Encodages
	- unicode dans une string "😃"
	- unicode en tant qu'identifier 😃 = 4
	- unicode escape sequences \U, \u
	- wchar_t & wide character literals L"..."
- ???
	- compound literals
	- control characters


