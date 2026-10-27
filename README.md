# Game with letter and number

##Letter game

Ce petit programme a pour but d'imiter le jeu Des chiffres et des lettres, et notamment la partie des lettres

Voilà ce que fait le programme en 3 étapes :

-- On tire d'abord de façon aléatoire 9 lettres
    Avec au minimum 2 voyelles

-- Le programme cherche ensuite dans le fichier Dictionnary.txt un mot qu'il peut faire avec
    On essaie d'abord un mot à 9 lettres
    Cas échéant à 8 lettres etc

-- On affiche tous les mots possibles avec le maximum de lettre 
    Ex : 3 mots à 9 lettres 
    Ou 7 mots à 8 lettres

Le 27/10/26 :
Les diffiérentes fonctions ont été placées dans des fichiers séparés du main
-- jeu.hpp permet l'annonce de toutes les fonctions utilisées dans le main
-- letter-drawing.cpp contient les fonctions CountVowels et RandomLetters permettant d'avoir un tirage de 9 lettres avec au minimum 2 voyelles
-- read-file.cpp permet de lire le fichier dictionnary.txt
-- make-word.cpp vérifie quel mots (les plus grands possible) peuvent être formés avec le tirage effectué


##Number-game
Ici on a un tirage de 6 nombres parmis la liste suivante : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 25, 50, 75 et 100
Et un resultat à atteindre entre 100 et 999
Le but est d'atteindre ce nombre avec un maximum de nombre du tirage en utilisant les QUATRES opérations élémantires (+ - x ÷)
-- number-drawing.cpp permet de tirer les 6 nombres et de choisir le resultat à atteindre