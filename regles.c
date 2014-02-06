#include "regles.h"

void sat_jeu(int taille) {
    ligne_grille(taille);
    colonne_grille(taille);
    carre_grille(taille);
}

// Règle sur ligne pour grille de taille n
void ligne_grille(int taille){
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
            for(j=1;j<=taille;j++){
                for(m=1;m<=taille;m++){
                    if(m!=j){
                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                        fputs(t,f);
                    }
                }
            }
        }
    }

    fclose(f);
    return;
}







// Règle sur ligne pour grille de taille 4
void ligne_grille_4(void){
    int i,j,k,m;
    char t[20]="";
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    for(i=1;i<=4;i++){
        for(k=1;k<=4;k++){
            for(j=1;j<=4;j++){
                sprintf(t,"%d%d%d ",i,j,k);
                fputs(t,f);
            }
            sprintf(t,"0\n");
            fputs(t,f);
            for(j=1;j<=4;j++){
                for(m=1;m<=4;m++){
                    if(m!=j){
                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                        fputs(t,f);
                    }
                }
            }
        }
    }
    fclose(f);
    return;
}







// Règle sur ligne pour grille de taille 9
void ligne_grille_9(void){
    int i,j,k,m;
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char t[20]="";

    for(i=1;i<=9;i++){
        for(k=1;k<=2;k++){
                for(j=1;j<=9;j++){
                    sprintf(t,"%d%d%d ",i,j,k);
                    fputs(t,f);
                }
                sprintf(t,"0\n");
                fputs(t,f);
                for(j=1;j<=9;j++){
                    for(m=1;m<=9;m++){
                        if(m!=j){
                            sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                            fputs(t,f);
                        }
                    }
                }
        }
    }
    fclose(f);
    return;
}

// Règle sur colonne pour grille de taille 4
void colonne_grille_4(void){
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char t[20]="";
    int i,j,k,m;

    for(j=1;j<=4;j++){
        for(k=1;k<=4;k++){
                for(i=1;i<=4;i++){
                    sprintf(t,"%d%d%d ",i,j,k);
                    fputs(t,f);
                }
                sprintf(t,"0\n");
                fputs(t,f);
                for(i=1;i<=4;i++){
                    for(m=1;m<=4;m++){
                        if(m!=j){
                            sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                            fputs(t,f);
                        }
                    }
                }
        }
    }
    fclose(f);
    return;
}


// Règle sur colonne pour grille de taille n
void colonne_grille(int taille){
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
                for(i=1;i<=taille;i++){
                    for(m=1;m<=taille;m++){
                        if(m!=j){
                            sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                            fputs(t,f);
                        }
                    }
                }
        }
    }
    fclose(f);
    return;
}




// Règle sur colonne pour grille de taille 9
void colonne_grille_9(void){
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char t[20]="";
    int i,j,k,m;

    for(j=1;j<=9;j++){
        for(k=1;k<=9;k++){
                for(i=1;i<=9;i++){
                    sprintf(t,"%d%d%d ",i,j,k);
                    fputs(t,f);
                }
                sprintf(t,"0\n");
                fputs(t,f);
                for(i=1;i<=9;i++){
                    for(m=1;m<=9;m++){
                        if(m!=j){
                            sprintf(t,"-%d%d%d -%d%d%d 0\n",i,j,k,i,m,k);
                            fputs(t,f);
                        }
                    }
                }
        }
    }
    fclose(f);
    return;
}


// Règle sur carré pour grille de taille n
void carre_grille(int taille){
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
                for(i1=i;i1<i+d;i1++){
                    for(m=i;m<i+d;m++){
                        if(m!=i1){
                            for(j1=j;j1<j+d;j1++){
                                for(n=j;n<j+d;n++){
                                    if(n!=j1){
                                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i1,j1,k,m,n,k);
                                        fputs(t,f);
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


// Règle sur carré pour grille de taille 4
void carre_grille_4(void){
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char t[20]="";
    int i,j,k,i1,j1,m,n;


    for(k=1;k<=4;k++){
        for(i=1;i<=3;i=i+2){
            for(j=1;j<=3;j=j+2){
                for(i1=i;i1<i+2;i1++){
                    for(j1=j;j1<j+2;j1++){
                        sprintf(t,"%d%d%d ",i1,j1,k);
                        fputs(t,f);
                    }
                }
                sprintf(t,"0\n");
                fputs(t,f);
                for(i1=i;i1<i+2;i1++){
                    for(m=i;m<i+2;m++){
                        if(m!=i1){
                            for(j1=j;j1<j+2;j1++){
                                for(n=j;n<j+2;n++){
                                    if(n!=j1){
                                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i1,j1,k,m,n,k);
                                        fputs(t,f);
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


// Règle sur carré pour grille de taille 9
void carre_grille_9(void){
    FILE *f=NULL;
    f=fopen("pbsat.cnf","a");
    char  t[20]="";
    int i,j,k,i1,j1,m,n;

    for(k=1;k<=9;k++){
        for(i=1;i<=7;i=i+3){
            for(j=1;j<=7;j=j+3){
                for(i1=i;i1<i+3;i1++){
                    for(j1=j;j1<j+3;j1++){
                        sprintf(t,"%d%d%d ",i1,j1,k);
                        fputs(t,f);
                    }
                }
                sprintf(t,"0\n");
                fputs(t,f);
                for(i1=i;i1<i+3;i1++){
                    for(m=i;m<i+3;m++){
                        if(m!=i1){
                            for(j1=j;j1<j+3;j1++){
                                for(n=j;n<j+3;n++){
                                    if(n!=j1){
                                        sprintf(t,"-%d%d%d -%d%d%d 0\n",i1,j1,k,m,n,k);
                                        fputs(t,f);
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

