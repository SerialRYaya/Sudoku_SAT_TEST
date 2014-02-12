#ifndef REGLES
#define REGLES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Unmonprojet.h"
#include "affichage.h"
#include "satgrille.h"

/* Pour grille de 4 : 64 variables ,   208 clauses pour ligne,   208 clauses pour colonne,    80 clauses pour carré    total =496  */
/* Pour grille de 9 : 729 variables ,   5913 clauses pour ligne,   5913 clauses pour colonne,    2997 clauses pour carré     total=14823  */

void sat_jeu(int taille, int *compteur_clauses_jeu); // appelle les 3 fonctions ligne_grille,colonne_grille et carre_grille
void ligne_grille(int taille, int *compteur_clauses_lignes); // Règle sur ligne pour grille de taille n
void colonne_grille(int taille,int *compteur_clauses_colonnes); // Règle sur colonne pour grille de taille n
void carre_grille(int taille,int *compteur_clauses_carres); // Règle sur carré pour grille de taille n


#endif // REGLES


