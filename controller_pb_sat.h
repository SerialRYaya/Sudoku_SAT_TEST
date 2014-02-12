#ifndef CONTROLLER_PB_SAT_H
#define	CONTROLLER_PB_SAT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Unmonprojet.h"
#include "affichage.h"
#include "regles.h"
#include "satgrille.h"
#include "decodage.h"

typedef int** Grille;

void creer_cnf(); // crée un fichier cnf vide, il sera vidé s'il existe déjà (option w de fopen).
int nbvariables(int dimension);// renvoie le nombre de variables (dimension au cube)
int nbclauses(int compteur_clauses_grille,int compteur_clauses_jeu,int compteur_clauses_saisies); // additionne clauses grille, jeu et saisies et renvoie le total
void generer_sat(Grille G,int dimension);
void entete_cnf(int nombre_variables,int nombre_clauses_total);// écrit l'entête du fichier cnf (p cnf nbvariables nbclauses)


#endif	/* CONTROLLER_PB_SAT_H */

