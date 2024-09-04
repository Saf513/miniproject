#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//defintion de structure livre
typedef struct {
    char titre[20];
    char auteur[30];
    float prix;
    int stock;
} livre;
//definir des variables globale
int i;
int n; //le nombre totale des livres
int nbr; //le nombre des livres a ajouter
livre L[100];

//fonction d'ajouter un  seul livre
void ajout_unique()
{
    printf("veuiller remplir les informations de livre : \n");
    printf("le titre de livre : \n");
    scanf(" %[^\n]s",L[n].titre) ;
    printf("l'auteur de livre : \n");
    scanf(" %[^\n]s",L[n].auteur) ;
    printf("le prix de livre : \n");
    scanf("%f",&L[n].prix) ;
    printf("la quantite de stock : \n");
    scanf("%d",&L[n].stock) ;
    n++;
}

//fonction d'ajouter pleusieures livres
void ajout_multiple()
{
    printf("veuillez saisir le nombre des livres a ajouter :\n");
    scanf("%d",&nbr);
    for (i = n ; i < n+nbr ; i++ ) {
        printf("veuiller remplir les informations de livre %d : \n",i+1);
        printf("le titre de livre : \n");
        scanf(" %[^\n]s",L[i].titre) ;
        printf("l'auteur de livre : \n");
        scanf(" %[^\n]s",L[i].auteur) ;
        printf("le prix de livre : \n");
        scanf("%f",&L[i].prix) ;
        printf("la quantite de stock : \n");
        scanf("%d",&L[i].stock) ;
    }
    n+=nbr;
}

//fonction d'afficher tous les livres disponible
void afficher()
{
    for (i = 0 ; i < n ; i++ ) {
        printf(" les informations de livre %d : \n",i+1);
        printf("\t le titre de livre : %s \n",L[i].titre);
        printf("\t l'auteur de livre : %s\n",L[i].auteur);
        printf("\t le prix de livre :%.2f \n",L[i].prix);
        printf("\t la quantite de stock : %d\n",L[i].stock);
    }
}
//fonction de recherche
int rechercher()
{
    char cherche[20];
    printf("veuillez entrer le titre de livre : \n");
    scanf(" %[^\n]s",cherche) ;
    for(i = 0 ; i < n ; i++) {
        if(strcmp(L[i].titre,cherche)==0) {
            return i;
        }

    }
    return -1;
}
//fonction d'afficher un livre cherche par son titre
void afficher_titre()
{
    int pos;
    pos=rechercher();
    if(pos == -1)
        printf("ce livre est indisonible \n");
    else {
        printf(" les informations de livre %d : \n",pos+1);
        printf("\t le titre de livre : %s \n",L[pos].titre);
        printf("\t l'auteur de livre : %s \n",L[pos].auteur);
        printf("\t le prix de livre :%.2f \n",L[pos].prix);
        printf("\t la quantite de stock : %d \n",L[pos].stock);
    }
}
//fonction de tri par ordre croissant par apport le prix
void triprix_croissant()
{
    int index,j;
    livre temp;
    for (i = 0 ; i < n-1 ; i++ ) {
        index=i;
        for (j = i+1 ; j < n ; j++ ) {
            if(L[j].prix<L[index].prix)
                index=j;
        }
        temp=L[i];
        L[i]=L[index];
        L[index]=temp;
    }
    }

//fonction de tri par ordre decroissant par apport le prix
    void triprix_decroissant() {
        int index;
        livre temp;
        int j;
        for (i = 0 ; i < n-1 ; i++ ) {
            index=i;
            for (j =i+ 1 ; j < n ; j++ ) {
                if(L[j].prix>L[index].prix)
                    index=j;
            }
            temp=L[i];
            L[i]=L[index];
            L[index]=temp;

        }
    }
//fonction de supprimer un livre
        void supprimer() {
            int pos;
            pos=rechercher();
            if(pos == -1){
                printf("ce livre est indisonible \n");}
            else {
                for (i = pos ; i < n-1 ; i++ ) {
                    L[i]  = L[i+1];
                }
                n--;
            }
            printf("la supression effectue par succes \n");

        }

//fonction qui calcule le stock
        void totale_stock() {
            int totale;
            for(i =0 ; i < n ; i++) {
                totale+=L[i].stock;
            }
            printf("le nombre totale des livres dans le stock est %d \n",totale)  ;
        }
//la fonction de modification de l'auteur
void modifier_auteur()
{
 char nouvel[20];
 int pos;
    pos=rechercher();
    if(pos == -1)
        printf("ce livre est indisonible \n");
    else {
        printf("veullez saisir le nouvelle nom d'auteur \n");
        scanf(" %[^\n]s",nouvel) ;
        strcpy(L[pos].auteur,nouvel);
    }
   printf(" modification effectue par succes \n\n");

}

//la fonction de modification de titre
void modifier_titre()
{
 char titre_nouv[20];
 int pos;
    pos=rechercher();
    if(pos == -1)
        printf("ce livre est indisonible \n");
    else {
        printf("veullez saisir le nouvelle titre \n");
        scanf(" %[^\n]s",titre_nouv) ;
       strcpy(L[pos].titre,titre_nouv);
    }
   printf(" modification effectue par succes \n\n");

}


//la fonction de modification de titre
void modifier_prix()
{
 float prix_nouv;
 int pos;
    pos=rechercher();
    if(pos == -1)
        printf("ce livre est indisonible \n");
    else {
        printf("veullez saisir le nouveau prix \n");
        scanf("%f",&prix_nouv) ;
        L[pos].prix=prix_nouv;
    }
   printf(" modification effectue par succes \n\n");

}

//la fonction de modification de stock
void modifier_stock()
{
 int stock_nouv;
 int pos;
    pos=rechercher();
    if(pos == -1)
        printf("ce livre est indisonible \n");
    else {
        printf("veullez saisir la nouvelle quantite \n");
        scanf("%d",&stock_nouv) ;
        L[pos].stock=stock_nouv;
    }
   printf(" modification effectue par succes \n\n");

}



//menu d'ajoute
        void menu_ajout() {
            int choix;
            printf("1->ajouter un seul livre \n");
            printf("2->ajouter pleusieures livre \n\n");
            printf("veuiller entrer votre choix : \n ");
            scanf("%d",&choix);
            switch(choix) {
            case 1:
                ajout_unique();
                break;
            case 2:
                ajout_multiple();
                break;
            default :
                printf(" choix invalide !!\n");
                break;
            }
        }

//menu d'affichage
        void menu_afficher() {
            int choix;
            printf("1->afficher un seul livre \n");
            printf("2->afficher tout les livres \n");
            printf("3->afficher les livres en ordre croissant par apport le prix \n");
            printf("4->afficher les livres en ordre decroissant par apport le prix \n");
            printf("veuiller entrer votre choix : \n ");
            scanf("%d",&choix);
            switch(choix) {
            case 1:
                  afficher_titre();
                break;
            case 2:
                afficher();
                break;
            case 3:
                triprix_croissant();
                afficher();
                break;
            case 4:
                triprix_decroissant();
                afficher();
                break;

            default :
                printf(" choix invalide !!");
                break;
            }
        }

        //menu de modification
void menu_modification()
{
 int choix;
            printf("1->modifier l'auteur \n");
            printf("2->modifier le titre \n");
            printf("3->modifier le prix \n");
            printf("4->modifier le stock \n");
            printf("veuiller entrer votre choix : \n ");
            scanf("%d",&choix);
            switch(choix) {
            case 1:
                   modifier_auteur();
                break;
            case 2:
                 modifier_titre();
                break;
            case 3:
                modifier_prix();
                break;
            case 4:
                 modifier_stock();
                break;

            default :
                printf(" choix invalide !!");
                break;
            }

}
//menu principal
        void menu_principal() {
            int choix;
            do{
            printf("1->afficher les livres \n");
            printf("2->ajouter des livres \n");
            printf("3->supprimer un livre \n");
            printf("4->afficher le nombre totale des livres en stock \n");
              printf("5->modifier les donnees \n");
            printf("6->sortir \n");
            printf("veuiller entrer votre choix : \n ");
            scanf("%d",&choix);
            switch(choix) {
            case 1:
               menu_afficher();
                break;
            case 2:
               menu_ajout();
                break;
            case 3:
                supprimer();
                break;
            case 4:
                totale_stock();
                break;
                case 5:
               menu_modification();
                break;
            case 6:
                return;
                break;
            default :
                printf(" choix invalide !!");
                break;
            }
        }while(choix !=6);}


// MENU PRINCIPAL
        int main(){
            printf("__________bienvenue dans votre gestionnaire________\n\n");
            menu_principal();
            return 0;
        }

