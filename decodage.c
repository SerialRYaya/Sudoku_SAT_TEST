#include "decodage.h"


void appel_sat4j(){

    system("start batch.bat" ); // " java -jar sat4j-sat.jar test1.cnf > patate2.txt " appel avec test1.cnf en paramètre et écriture dans patate2.txt
    }


/*
char *decoupage (const char *fichier){
        char chaine[7000]="";
        while ( fgets(chaine,7000, fichier) != NULL )
            {

                 if ( chaine[0]== 'v' ){
                    return chaine;
                }
            }
            return;
}
*/
char *decoupage_sat4j (FILE *fichier){
        char *chaine = malloc (sizeof (*chaine) * 5000);
        while ( fgets(chaine,5000, fichier) != NULL )
            {
                 if ( chaine[0]== 'v' ){
                            return chaine;
                }
            }
        return "IMPOSSIBLE";
}

char *resolution_sat4j(){
    appel_sat4j();
    FILE *decode = NULL;
    Sleep(2000);
    decode = fopen("patate2.txt","r");
    char *solution = malloc (sizeof (*solution) * 1000);
    if (decode == NULL){
        printf("Le fichier ne peut pas etre ouvert \n ");
        return 0;
        }
    solution=decoupage_sat4j(decode);
    if (solution=="IMPOSSIBLE"){
        printf("Il n'existe pas de solution a ce probleme .");
        return 0;
    }
    fclose(decode);
    printf("SOLUTION : %s",solution);
    return solution;
}

void resoudre(Grille G,int dimension) {
    generer_sat_grille(G,dimension);
    sat_jeu(dimension);
    resolution_sat4j();
}

void lecture_resultat_sat4j(const char *solution){

}
