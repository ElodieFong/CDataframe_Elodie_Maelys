CDataframe L1

Contributeurs : 
- Fong Elodie
- de Crouy Chanel Maelys

  Dans l'objectif de créer un logiciel similaire a un tableur, nous devons implémenter une structure de donné à l'aide d'un CDataframe. 
  Un CDataframe peut être décrit comme une matrice de données organisée en colonnes, chaque colonne ayant un type de données homogène mais différent des autres colonnes. Il est prévu de construire cette structure de données en plusieurs étapes, en l'améliorant et en rajoutant progressivement des fonctionnalités. 

    La première étape pour réaliser ce projet est la création de colonnes servant de base pour le CDataframe. Nous sommes parties sur des colonnes ne pouvant contenir que des donnés de type entier. Nous avons mis en place des fonctions afin de pouvoir réaliser des opérations de base sur les colonnes tel que la création de celles-ci, leurs suppressions, la possibilité d'y insérer des valeurs et d'afficher le contenue des colonnes. Nous avons aussi mis en place d'autre fonctions afin de réaliser un plus grand panel d'opération tel que, à l'aide d'une valeur x donner en paramètre, retourner le nombre de d’occurrences de la valeur x, la valeur présente à la position x, le nombre de valeurs qui sont supérieures à x, le nombre de valeurs qui sont inférieures à x et de retourner le nombre de valeurs qui sont égales à x.

    La deuxième étape pour la réalisation du projet est la mise en place du CDataframe lui-même. Nous avons décidé de le concevoir comme un tableau dynamique de pointeur vers les colonnes créé précédemment. Afin de pouvoir rendre le CDataframe utilisable, nous allons implémenter les fonctions auquel l'utilisateur aura accès et qu'il pourra choisir et utiliser grâce à un menu. Les fonctions comprendront des fonctions d'alimentation avec la création et remplissage et CDataframe, l'affichage du CDataframe ou d'élément en particulier, des opérations usuelles sur le CDataframe et enfin des analyse et statistique sur le CDataframe tel que l'affichage du nombre de ligne, colonnes et cellules en lien à une valeur x donné en paramètre.

    Enfin, pour la troisième étape de la réalisation de ce projet, nous allons mettre en place des fonctionnalités basique en implémentant le CDataframe comme une liste doublement chainée et permettre son chargement de données dans un fichier .csv.

