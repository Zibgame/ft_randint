# 🎲 ft_randint

Petit projet perso en C qui génère des nombres pseudo-aléatoires **sans utiliser `<stdlib.h>`**.  
Pas de `rand()`, pas de `srand()`, juste un peu de logique, des adresses mémoire, et le nombre d’or 💫

---

## ⚙️ Fonctionnement

`ft_randint` utilise :
- les **adresses mémoire** de variables locales et de la fonction elle-même 🧠  
- une **constante du nombre d’or** (`0x9e3779b97f4a7c15UL`)  
- et un **seed statique** mis à jour à chaque appel ⚡  

Le tout permet de produire un résultat assez imprévisible, sans aucune dépendance.

```c
mix = (unsigned long)&local
    ^ (unsigned long)&max
    ^ (unsigned long)&ft_randint;
seed += mix + 0x9e3779b97f4a7c15UL;
return (seed % (unsigned long)max);
