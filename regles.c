#include "regles.h"

void sat_jeu(int taille, int *compteur_clauses_jeu) {
    int compteur_clauses_lignes = 0;
    int compteur_clauses_colonnes = 0;
    int compteur_clauses_carres = 0;
    
    ligne_grille(taille,&compteur_clauses_lignes);
    colonne_grille(taille,&compteur_clauses_colonnes);
    carre_grille(taille,&compteur_clauses_carres);
    
    *compteur_clauses_jeu = compteur_clauses_lignes + compteur_clauses_colonnes + compteur_clauses_carres;
}

// Règle sur ligne pour grille de taille n
void ligne_grille(int taille, int *compteur_clauses_lignes){
    FILE *f = NULL;
    f=fopen("pbsat.cnf","a");
    int i,j,k,m;
    char t[20]="";

    for(i=1;i<=taille;i++){
        for(k=1;k<=taille;k++){
            for(j=1;j<=taille;j++){
                sprintf(t,"%d%d%d ",i,j,k);
                fputs(t,f);
            }
            sprintf(t,"0\n");
            fputs(t,f);
	    (*compteur_clauses_lignes)++;
            for(j=1;j<=taille;j++){
                for(m=1;m<=taille;m++){
                    if(m!=j){
                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                        fputs(t,f);
			(*compteur_clauses_lignes)++;
                    }
                }
            }
        }
    }

    fclose(f);
    return;
}

// Règle sur colonne pour grille de taille n
void colonne_grille(int taille,int *compteur_clauses_colonnes){
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char t[20]="";
    int i,j,k,m;

    for(j=1;j<=taille;j++){
        for(k=1;k<=taille;k++){
                for(i=1;i<=taille;i++){
                    sprintf(t,"%d%d%d ",i,j,k);
                    fputs(t,f);
                }
                sprintf(t,"0\n");
                fputs(t,f);
		(*compteur_clauses_colonnes)++;
                for(i=1;i<=taille;i++){
                    for(m=1;m<=taille;m++){
                        if(m!=j){
                            sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                            fputs(t,f);
			    (*compteur_clauses_colonnes)++;
                        }
                    }
                }
        }
    }
    fclose(f);
    return;
}

// Règle sur carré pour grille de taille n
void carre_grille(int taille,int *compteur_clauses_carres){
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char t[20]="";
    int i,j,k,i1,j1,m,n;
    int d=sqrt(taille), q=taille-sqrt(taille)+1;

    for(k=1;k<=taille;k++){
        for(i=1;i<=q;i=i+d){
            for(j=1;j<=q;j=j+d){
                for(i1=i;i1<i+d;i1++){
                    for(j1=j;j1<j+d;j1++){
                        sprintf(t,"%d%d%d ",i1,j1,k);
                        fputs(t,f);
                    }
                }
                sprintf(t,"0\n");
                fputs(t,f);
		(*compteur_clauses_carres)++;
                for(i1=i;i1<i+d;i1++){
                    for(m=i;m<i+d;m++){
                        if(m!=i1){
                            for(j1=j;j1<j+d;j1++){
                                for(n=j;n<j+d;n++){
                                    if(n!=j1){
                                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i1,j1,k,m,n,k);
                                        fputs(t,f);
					(*compteur_clauses_carres)++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(f);
    return;
}


