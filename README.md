insaTPinheritance
=================
par Aurélien Bertron et Thomas Losbar

# Présentation
Ce programme est un éditeur de dessin... en ligne de commande! L'utilisateur crée des formes géométriques à l'aide de commandes qu'il rentre dans l'application.

# Compilation
Compilation de base : `make` (exécutable dans le sous-répertoire bin)
Nettoyage : `make clean`
Nettoyage complet : `make mrproper`
Exécution des tests : `make test`
Création de la doc : `doxygen Doxyfile`
Tests de performance : `ruby tests/perfs.rb`

## Ce qui marche
- Ajout de formes (Cercles, Lignes, Polylignes, Rectangles, Objets Agrégés rassemblant d'autres formes)
- Suppression de formes
- Déplacement de formes selon un vecteur
- Chargement d'un fichier de commandes à exécuter
- Sauvegarde du dessin dans un fichier
- Suppression de tous les objets d'un seul coup (!)
- Annulation de la dernière commande (UNDO)
- Annulation de l'annulation de la dernière commande (REDO)

## Ce qui ne marche pas
Il s'agit en fait de petits bugs ou bien des choix que nous avons fait
- Annulation d'un CLEAR impossible : voulu car implique une trop grande utilisation mémoire
- Les seules commandes interprétées dans un LOAD sont ADD, DELETE et MOVE : voulu pour éviter trop de complexité dans les algorithmes de chargement de fichier (et donc une augmentation du temps d'exécution)
- Bug : L'ajout d'Objets agrégés dans un fichier chargé par un LOAD ne fonctionne pas. Il va en effet contrôler si les noms d'objets qu'on lui donne existent alors qu'ils n'ont pas été encore ajoutés au modèle (principe d'ajout différé)
- Bug : Lorsqu'on supprime un élément avec DELETE, il est impossible d'ajouter un nouvel objet du même nom. Cela est dû au fait que l'élément n'est pas complètement supprimé du modèle pour permettre le UNDO du DELETE.
