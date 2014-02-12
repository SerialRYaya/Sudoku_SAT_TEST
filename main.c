#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Unmonprojet.h"
#include "affichage.h"
#include "regles.h"
#include "satgrille.h"
#include "decodage.h"*

/*
 *
 */



void main(int argc, char** argv) {

    printf("############################################################\n");
    printf("###################    SUDOKU AVEC SAT    ##################\n");
    printf("############################################################\n");
    int dimension = 0;
    while (dimension != 4 && dimension != 9) {
        printf("\nSaisissez la largeur desiree (4 ou 9): ");
        scanf("%i", &dimension);
        if (dimension != 4 && dimension != 9) {
            printf("Erreur : les deux seules largeurs possibles sont 4 ou 9.");
        }
    }
    printf("\n");
    Grille G;
    G = creer_grille(dimension);
    raz_grille(G, dimension);
    saisir_grille(G, dimension);
}

