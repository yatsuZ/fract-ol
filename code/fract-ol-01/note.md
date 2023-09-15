# Prise de note

1. J'ai ramené les bibliothèques minilibx et libft.

2. Structure :
``` md
.
┃
┠━	library/	┓
┃				┠━	libft/
┃				┗	minilibx-linux/
┠━	header/
┠━	src/
┗	makefile, notes.md et verif_norminette_fractol.sh
```

| Nom | Description |
|-----|-------------|
| ./library/ | Dossier contenant toutes mes bibliothèques, y compris libft et minilbx. |
| ./header/ | Dossier contenant tous mes fichiers d'en-tête, les fichiers .h. |
| ./src/ | Dossier contenant tout mon code source, les fichiers .c et mon main. |
| makefile | Fichier makefile qui me permettra de compiler le tout et de générer mon fichier exécutable. |
| notes.md | Fichier md qui prend en note la progression du projet. |
| verif_norminette_fractol.sh | Petit script bash que j'ai ecris qui me permetra de verifier les erreurs de norm. |

3. Crée mes fichier princpaux c'est a dire un header un main.c et mon makefile.

4. Pour debuter je vais jute essaye d'ecrire "HELLO WORLD!" et que le makefile puisse tout compilée.

5. A présent que mon make marche je vais commence à faire ma to do liste que j'ai fais sur ma racine de mon repos.

---

|       CE QUE JE DOIS FAIRE        |  valide      |
| ----------------------------- | ------------ |
|      Crée une fenetre         | ✅ 01/09/2023 |
| Faire qu'en appuyant sur echap la fenetre se ferme | ✅ 01/09/2023 |
|      Deplacer la fenetre      | ✅ 01/09/2023 |
| Faire que en appuyant sur la croix la fenetre se ferme |✅ 01/09/2023 |
| Parsing pour choix de la fractal. |✅ 01/09/2023|
| Essaye d'apliquer les ensembles de Julia et Mandelbrot. |      ✅       |
| Pouvoir zoomer et dezoome avec la souris |      ✅       |
| Pouvoir deplacer la camera avec les fleches |      ✅       |
| Au moins un paramètre est passé en ligne de commande pour définir quel type de fractale est à afficher dans la fenêtre. |      ✅       |
| Il doit y avoir un jeu de couleur minimum pour ressentir la profondeur de chaque fractale. |      ✅       |
| Malgres les redimension que la fenetre sadapte |      ✅       |
| Si aucun paramètre n’est fourni ou si le paramètre est invalide, le programme doit afficher la liste des paramètres disponibles et quitter proprement. |      ✅       |
| En donnant des paramètres différents au programme, il doit être possible de créer différents ensembles de Julia. |      ✅       |
| Il est possible de gérer des paramètres en plus afin de les utiliser pour le rendu. |      ✅       |

```
Au moins un paramètre est passé en ligne de commande pour définir quel type de
fractale est à afficher dans la fenêtre.
◦ Il est possible de gérer des paramètres en plus afin de les utiliser pour le rendu.
◦ Si aucun paramètre n’est fourni ou si le paramètre est invalide, le programme
doit afficher la liste des paramètres disponibles et quitter proprement.
```