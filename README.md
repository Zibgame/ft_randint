# 🎲 ft_randint

Petit projet perso en C pour générer des **nombres pseudo-aléatoires**,  
sans utiliser la fonction `rand()` de la librairie standard.  
L’idée, c’est de créer un comportement imprévisible basé sur la **mémoire**,  
le **XOR** et le **nombre d’or** 💫

---

## ⚙️ Principe

La fonction utilise une variable `static unsigned long seed`, qui garde sa valeur  
entre les appels.  
À chaque appel, elle melange plusieurs adresses memoire (celles d’une variable locale,  
du parametre et de la fonction elle-meme) pour creer une base un peu aleatoire.  
Ensuite, elle ajoute une constante liee au **nombre d’or** en hexadecimal  
(`0x9e3779b97f4a7c15`) pour decaler la valeur du seed à chaque aqppel.

```c

int	ft_randint(int max)
{
	static unsigned long	seed;
	int						local;
	unsigned long			mix;

	if (max <= 0)
		max = 1;
	mix = (unsigned long)&local
		^ (unsigned long)&max
		^ (unsigned long)&ft_randint;
	seed += mix + 0x9e3779b97f4a7c15;
	return (seed % (unsigned long)max);
}
