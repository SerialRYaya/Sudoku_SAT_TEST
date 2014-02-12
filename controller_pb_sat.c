#include "controller_pb_sat.h"

void creer_cnf() {
    FILE * f = NULL;
    f = fopen("pbsat.cnf", "w");
    fputs("                              \n",f);
    fclose(f);
}

int nbvariables(int dimension) {
    int nombre_variables = dimension * dimension * dimension;
    return nombre_variables;
}

int nbclauses(int compteur_clauses_grille,int compteur_clauses_jeu,int compteur_clauses_saisies) {
    int nombre_clauses_total;
    nombre_clauses_total = compteur_clauses_grille + compteur_clauses_jeu + compteur_clauses_saisies;
    return nombre_clauses_total;
}

void generer_sat(Grille G,int dimension) {
    // initialisation des compteurs. obligatoires pour l'entête cnf et découpé pour les stats.
    int nombre_variables = 0;
    int nombre_clauses_total = 0;
    int compteur_clauses_grille = 0;
    int compteur_clauses_jeu = 0;
    int compteur_clauses_saisies = 0;
    
    // initialisation du fichier cnf
    creer_cnf();
    
    // générer pb sat : grille puis jeu puis saisies
    generer_sat_grille(G,dimension,&compteur_clauses_grille);
    sat_jeu(dimension,&compteur_clauses_jeu);
    generer_sat_saisies(G,dimension,&compteur_clauses_saisies);
    
    // nb clauses et variables pour entete cnf
    nombre_variables = nbvariables(dimension);
    nombre_clauses_total = nbclauses(compteur_clauses_grille,compteur_clauses_jeu,compteur_clauses_saisies);
    
    //ajout de l'entete cnf
    entete_cnf(nombre_variables,nombre_clauses_total);
    
    //envoie au solver
    resolution_sat4j();
}

void entete_cnf(int nombre_variables, int nombre_clauses_total) {
    FILE * f = NULL;
    f = fopen("pbsat.cnf", "r+");
    rewind(f);
    char entete[30];
    sprintf(entete,"p cnf %i %i\n",nombre_clauses_total,nombre_variables);
    fputs(entete, f);
    fclose(f);
}
