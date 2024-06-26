# Vingt et un

## 1. Introduction
Le [langage **C**](https://fr.wikipedia.org/wiki/C_(langage)) est un des premiers langages de programmation accessible gratuitement. Il a été créé pour permettre d’écrire des programmes compilés plus facilement. Aujourd’hui, il est encore souvent utilisé pour écrire des programmes pour des logiciels embarqués qui ont souvent des restrictions de mémoire ou puissance de calcul, car il permet un contrôle total sur la mémoire et puissance utilisée par le programme.

Le jeu du 21, aussi appelé « Black Jack », est un jeu créé en France au XVIIIe siècle. Il est dit que Marie Antoinette y jouait. Ce jeu est parfois joué en casino et c’est l’un des seuls jeux d’argent à avoir un gain supérieur à un, ça veut dire qu’on y gagne plus d’argent qu’on en perd en moyenne. Pour cette raison, beaucoup de casinos choisissent de ne pas le proposer.

Aidez Carty à créer ce jeu de carte !

<br>

## 2. Consignes
- En cas de question, pensez à demander de l’aide à votre voisin de droite. Puis de gauche. Demandez enfin à un Cobra (ceux-là ne mordent pas) si vous êtes toujours bloqué(e). 

- Vous avez tout à fait le droit d’utiliser internet pour trouver des réponses ou pour vous renseigner. (évitez ChatGPT)

- N’hésitez pas à faire des bonus et à ajouter des fonctionnalités lorsque votre projet sera terminé et validé. 

⚠️ - Tout ce qui est écrit après un `//` ou entre `/* ... */` est un commentaire pour t'aider à comprendre

<br>

## 3. Les règles du jeu

Carty va jouer au vingt-et-un avec un jeu de carte modifié. Il n’y a ni Roi ni Reine qui auraient une valeur trop élevée et il n’y a pas non plus les 7 et 8 pour éviter de tomber sur trop ou trop peu, par conséquent de rendre le jeu moins prévisible à la fin. Elle va utiliser 3 jeux de cartes mélangés soit 108 cartes ! C’est 12 fois chaque carte !

Les valeurs des cartes se calculent normalement (l’as vaut 1, le 2 vaut 2, etc.) sauf pour le valet qui vaut soit 11 soit 1 selon le choix du joueur. Lorsque 6 cartes sont tirées sans dépasser 21 le score du joueur est compté comme un 21.

Le jeu se joue contre un croupier et le but d'une partie est de dépasser le nombre du croupier pour récupérer sa mise.

Une partie commence par la distribution de 2 cartes. Le croupier tire un nombre entre 14 et 21. Ensuite le croupier et le Carty misera entre 5 et 10 selon leur main. Puis commencent les tours de Carty au cours desquels il doit se rapprocher au maximum de 21 mais sans le dépasser. A chaque tour, elle demandera une autre carte ou s'arrêtera à sa main actuelle. Si elle fait 21 le croupier double la mise de Carty. À condition que le croupier fait 21 il ramasse les mises directement.

Dans le cas où le croupier a misé 8 et le joueur 7 et qu’elle fait 21, elle remporte 14 (soit le double de sa mise) en plus des 8 du croupier ! Au début de la partie Carty aura 15 pions à miser. Le jeu dure 5 parties et le joueur doit obtenir un maximum de points dans ces 5 parties.

<br>

## 4. Coder un jeu en C

1. Préparer l'environnement de travail

Afin de pouvoir exécuter et travailler sur votre programme, nous vous conseillons d'utiliser la plateforme [repl.it](https://replit.com). (*Cette plateforme permet de vous simplifier la compilation du projet si vous n'êtes pas à l'aise avec le C*)

Une fois sur le site, vous devrez vous connecter ou créer un compte si vous ne disposez pas encore d'un compte sur la plateforme.

Une fois connecté, vous serez sur la page principale. En haut à gauche vous allez voir un bouton avec marqué "**+ Create Repl**". Vous devez cliquer dessus. Plusiueurs templates vous seront proposé. Ce qui nous intéresse c'est le C donc vous devez rechercher le template qui correspond au langage C

Une fois sélectionné, vous pouvez choisir le titre de votre projet, vous pouvez mettre par exemple "Coding Club 2024", puis ensuite cliquer sur "**+ Create Repl**"

2. Importer les fichiers

