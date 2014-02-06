#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>


typedef int** Grille;

void appel_sat4j();
char *decoupage_sat4j(FILE *decode); // prend une chaine en paramètre et la découpe a partir du "v"
char *resolution_sat4j();// renvoie la solution brute
void resoudre(Grille G,int dimension);
void lecture_resultat_sat4j();
