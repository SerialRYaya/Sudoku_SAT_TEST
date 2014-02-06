#ifndef monProjet_H
#define monProjet_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "affichage.h"
#include "regles.h"
#include "satgrille.h"

typedef int** Grille;

Grille creer_grille(int dimension);
void raz_grille(Grille G, int dimension);
int verifier_case(Grille G,int l, int c, int valeur,int dim);
int verification_valeur(Grille G,int l, int c, int valeur,int dimension);
void remplir_tableau(Grille G,int dimension);
void saisir_grille(Grille G, int dimension);


#endif // monProjet_H
