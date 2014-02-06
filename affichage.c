#include "affichage.h"

/*
    int taille = 4 ;

     int i,j,tab[taille][taille],e=0;
    for (i=0;i<taille;i++){
        for (j=0;j<taille;j++){
            tab[i][j]=0;
            printf("%d ",tab[i][j]);
            }printf("\n");
    }
*/
    void afficher_grille(Grille tab,int taille){
        int i,j,s,racine=sqrt(taille),e=0;
        char interstice[1180]="";
         while ( e < taille ){
                strcat(interstice,"___ ");
                if (e==racine-1){
                    strcat(interstice," ");
                    racine+=sqrt(taille);
                }
                e++;}

        for (i=0;i<taille;i++){
                for (j=0;j<taille;j++){
                        racine=sqrt(taille);
                        for (s=0;s<sqrt(taille)-1;s++){
                           if (j==racine){
                                printf("|");
                            }
                            racine+=sqrt(taille);
                        }
                        printf(" %d  ",tab[i][j]);
                    }
                printf("\n\n");
                racine=sqrt(taille);
                for (s=0;s<sqrt(taille)-1;s++){
                            if (i==racine-1){
                                printf(interstice);
                                printf("\n\n");
                            }
                            racine+=sqrt(taille);
                        }
        }
    }




