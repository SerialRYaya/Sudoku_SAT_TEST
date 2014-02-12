#include "Unmonprojet.h"

Grille creer_grille(int dimension) {
    int i;
    Grille G = NULL;
    G = (Grille) malloc(dimension * sizeof (int*));
    for (i = 0; i < dimension; i++) {
	G[i] = (int*) malloc(dimension * sizeof (int));
    }
    return G;
}

void raz_grille(Grille G, int dimension) {
    int i, j;
    for (i = 0; i < dimension; i++) {
	for (j = 0; j < dimension; j++) {
	    G[i][j] = 0;
	}
    }
}



int verifier_case(Grille G,int l, int c, int valeur,int dim){
    int i,j;
    double a = (double)dim;

    //on verifie seulement le carree de 3 par 3
    for(i=l;i<a-sqrt(a)+1;i++){
       for(j=c;j<a-sqrt(a)+1;j++){
        if(G[i-1][j-1]==valeur){
            return 0;
        }
       }
    }
     return 1;

}

int verification_valeur(Grille G,int l, int c, int valeur,int dimension){ //return 1 si valeur autoris�
    int i;
     if(valeur == 0) {return 1;}
     else if (valeur < 1 || valeur > dimension) {return 0;}
     else if (verifier_case(G,l,c,valeur,dimension)==0) {return 0;}

     for (i=1; i<= dimension; i++)
            if(G[l-1][i] == valeur)
                return 0;
      for (i=1; i<= dimension; i++)
                if(G[i-1][c] == valeur)
                    return 0;

    return 1;
}

void remplir_tableau(Grille G,int dimension){
int i;
int j;
int k;
    printf("Choisissez la ligne : " );
    scanf("%d",&i);
    while (i < 1 || i > dimension) {
        printf("Erreur : la valeur doit etre superieure ou egale a 1 et inferieure a %d \n ",dimension);
		printf("Choisissez la ligne : " );
		scanf("%d",&i);
    }
    if (i >= 1 && i <= dimension)
    {
		printf("Choisissez la colone : ");
		scanf("%d",&j);
		while (j < 1 || j > dimension){
        printf("Erreur : la valeur doit etre superieure ou egale a 1 et inferieure a %d ",dimension);
		printf("Choisissez la colone : ");
		scanf("%d",&j);
		}
        if (j >= 1 && j <= dimension){

            if(G[i-1][j-1] == 0) //seulement si case vide
            {
                //if(nombre_possibilite_case(G,i,j,dimension)>0){

                    printf("(0 si vous voulez laisser la case vide) \nSaisir une valeur a la case %d %d :",i,j);
                    scanf("%d",&k);
                    while(verification_valeur(G,i,j,k,dimension)==0){
                        printf("Saisissez une autre valeur .\n");
                        scanf("%d",&k);

                    }
                    G[i-1][j-1]=k;
                }

            }

        }

    }


void saisir_grille(Grille G, int dimension) {
    int choix=0;
    while (choix != 4) {
	afficher_grille(G, dimension);
	printf("\n########## MENU GENERAL ##########\n\n");
	printf("1 - Saisir une case : tapez 1\n");
	printf("2 - Resoudre la grille : tapez 2\n");
	printf("3 - Remettre la grille a 0 : tapez 3\n");
	printf("4 - Quitter : tapez 4\n");
	printf("Votre choix : ");
	scanf("%i", &choix);
	switch (choix) {
	    case 1:
		remplir_tableau(G, dimension);
		break;
	    case 2:
		generer_sat(G, dimension);
		break;
	    case 3:
		raz_grille(G, dimension);
		break;
		case 4:
		break;

	}
    }
}

