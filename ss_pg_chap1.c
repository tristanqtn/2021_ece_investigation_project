#include "header.h"



///Creation du tab//////////////////////////////////////////////
void creation(t_identite liste[TAILLE])
{
    ///Déclaration
    char inutile;
    int i;

    ///Fichier
    FILE * dossier;

    //ouverture
    dossier = fopen("releve.txt", "r");

    //erreur
    if(dossier == NULL)
    {
        printf("\n Erreur d'ouverture du fichier de numeros");
    }

    //lecture des TAILLE appels
    else
    {
        for(i=0; i<TAILLE; i++)
        {

            //lecture de l'esapce
            fflush(stdin);
            fscanf(dossier, "%c", &inutile);

            //lecture du plus
            fflush(stdin);
            fscanf(dossier, "%c", &inutile);

            //lecture du num
            fflush(stdin);
            fscanf(dossier, "%s", liste[i].numero);

            //lecture du nom
            fflush(stdin);
            fscanf(dossier, "%s", liste[i].nom);

            //lecture du prenom
            fflush(stdin);
            fscanf(dossier, "%s", liste[i].prenom);

            //lecture du type d'appel
            fflush(stdin);
            fscanf(dossier, "%s", liste[i].appel);

            //lecture du caractère de fin de ligne
            fflush(stdin);
            fscanf(dossier, "%c", &inutile);
        }

        //fermeture
        fclose(dossier);
    }
}
////////////////////////////////////////////////////////////////


///Affichage////////////////////////////////////////////////////
void afficherTableau(t_identite tableau[TAILLE])
{
    //pour les TAILLE appels
    for (int i=0; i<TAILLE; i++)
    {
        printf("Num : +%s\t", tableau[i].numero);
        printf("ID : %s ", tableau[i].prenom);
        printf("%s \t", tableau[i].nom);
        printf("Type d'appel : %s\n", tableau[i].appel);
    }
}
////////////////////////////////////////////////////////////////


///Tri a bulle//////////////////////////////////////////////////
void triBulle(t_identite liste[TAILLE])
{
    ///Déclarations
    int i,j;
    t_identite tmp;

    //Parcours du tableau de 1000 structures
    for (i=0; i<TAILLE; i++)
    {
        //Parcours du tableau de 1000-i structures
        for (j=0 ; j<TAILLE-i; j++)
        {
            //si le num de la struct précédente est supérieur au num de la struct suivante
            if ( strcmp(liste[j].numero,liste[j+1].numero)== 1)
            {//échange les 2 structures de place
                tmp = liste[j];
                liste[j] = liste[j+1];
                liste[j+1] = tmp;
            }
        }
    }
}
////////////////////////////////////////////////////////////////


///Tri insertion////////////////////////////////////////////////
void triInsertion(t_identite liste[TAILLE])
{
    ///Déclarations
    int i, j;
    t_identite tmp, echange;

    //Parcours du tableau de 1000 structures
    for(i=0; i<TAILLE; i++)
    {
        tmp = liste[i];
        j=i;
        //tant que la structure n'est pas à la bonne place
        while(j>0 && (strcmp(liste[j-1].numero, tmp.numero)== 1))
        {//échange des valeurs pour lui donner la bonne place
                echange = liste[j-1];
                liste[j-1] = liste[j];
                liste[j] = echange;
                j--;
        }
        liste[j] = tmp;
    }
}
////////////////////////////////////////////////////////////////





