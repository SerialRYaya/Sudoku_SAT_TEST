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

void sat_jeu(int taille); // appelle les 3 fonctions ligne_grille,colonne_grille et carre_grille

void ligne_grille(int taille); // Règle sur ligne pour grille de taille n
void ligne_grille_4(void); // Règle sur ligne pour grille de taille 4
void ligne_grille_9(void); // Règle sur ligne pour grille de taille 9

void colonne_grille(int taille); // Règle sur colonne pour grille de taille n
void colonne_grille_4(void); // Règle sur colonne pour grille de taille 4
void colonne_grille_9(void); // Règle sur colonne pour grille de taille 9

void carre_grille(int taille); // Règle sur carré pour grille de taille n
void carre_grille_4(void); // Règle sur carré pour grille de taille 4
void carre_grille_9(void); // Règle sur carré pour grille de taille 9

#endif // REGLES


