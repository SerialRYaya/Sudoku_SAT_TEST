#ifndef SATGRILLE
#define SATGRILLE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Unmonprojet.h"
#include "affichage.h"
#include "regles.h"

typedef int** Grille;

//grille de taille "dimension". le problème sat définissant la grille de sudoku est généré par les fonctions ci-dessous.
void entete_cnf(int dimension);//écrit l'entête du fichier cnf (p cnf nbvariables nbclauses)
void generer_sat_grille(Grille G,int dimension); // appelle les deux fonctions qui suivent. le pb sat définissant la grille est la conjonction des deux problèmes "au moins" et "au plus".
void generer_sat_grille_au_moins(int dimension); // renvoie le pb sat "chaque case contient au moins un chiffre entre 1 et dimension"
void generer_sat_grille_au_plus(int dimension); // renvoie le pb sat "chaque case contient au plus un chiffre entre 1 et dimension"
void generer_sat_saisies(Grille G,int dimension); // renvoie le pb sat correspondant aux valeurs saisies dans la grille;
#endif //SATGRILLE

