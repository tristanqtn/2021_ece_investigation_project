#include "header.h"

///Inititalisation//////////////////////////////////////////////
void initialisation (int tableau [25])
{
    ///Déclaration
    int i;

    for(i=0; i<25; i++)
    {//remplir le tableau d'entiers de 0 pour pouvoir incrémenter les compteurs
        tableau[i]=0;
    }
}

///Remplir
void remplir (int tab [1000])
{
    ///Déclarations
    int i;

    for(i=0; i<1000; i++)
    {// remplir le tableau de 1000 entiers avec des entiers aléatoires entre 0 et 24 bornes comprises
        tab[i] = rand() %25;
    }
}
////////////////////////////////////////////////////////////////


///Création du premier histogramme//////////////////////////////
void histogrammeI (int tabAlea [1000], int tableau [25][2])
{
    ///Déclarations
    int i, j;

    //initialisation du tableau de l'histogramme
    for(i=0; i<25; i++)
    {
        tableau[i][0]= -1; //initialisation à -1 pour qu'aucune valeur aléatoire ne corresponde
        tableau[i][1]= 0;  //initialisation à 0 des compteur pour incrémentation
    }


    for(i=0; i<1000; i++)
    {//parcours du tableau de 1000 entiers aléatoires
        j=0; //mise à 0 de l'indice de parcours j
        while(j<25)
        {//parcours du tableau de l'histogramme
            if(tabAlea[i] == tableau[j][0])
            {//si une case du tableau est déjà prise par un entier entre 0 et 24
                tableau[j][1]++; //incrémentation du compteur d'occurence de cet entier
                j=25; //on sort de la boucle TANT QUE
            }
            else if(tableau[j][0] == -1)
            {//si cet entier ne figure pas encore dans le tableau,
                tableau[j][0] = tabAlea[i]; //on stock la valeur de cet entier dans la première dimension du tableau
                tableau[j][1] = 1;//on met à 1 le nombre d'occurence de ce nouvel entier dans la deuxième dimension du tableau
                j = 25; //on sort de la boucle TANT QUE
            }
            j++; //incrémentation de la variable de parcours
        }
    }
}

///Création du deuxième histogramme
void histogrammeII (int tabAlea [1000], int tableau [25])
{
    ///Déclarations
    int i;

    for(i=0; i<1000; i++)
    {//parcours du tableau de 1000 aléatoires
        tableau[tabAlea[i]] ++; //incrémentation du compteur à chaque détecttion d'occurence
    }
}
////////////////////////////////////////////////////////////////


///Affichage du premier histogramme/////////////////////////////
void affichageHistoI (int tablo [25][2])
{
    ///Déclarations
    int i, j;

    for(i=0; i<25; i++)
    {//parcours du tableau de 25 entiers
        printf("Suspect %d\t: %d     ", tablo[i][0], tablo[i][1]); //affichage des occurences

        for(j=0; j<tablo[i][1]; j++)    //dessin d'une caase en blanc pour chaque occurences
        {
            color(15,15);
            printf("_");

        }
        //correction des bugs graphiques
        color(0,0);
        printf("_");
        color(15,0);
        printf("\n\n");

    }

}
////////////////////////////////////////////////////////////////


///Affichage du deuxième histogramme////////////////////////////
void affichageHistoII (int tablo [25])
{
    ///Déclarations
    int i, j;

    for(i=0; i<25; i++)
    {//parcours du tableau de 25 entiers
        printf("Suspect %d\t: %d     ", i, tablo[i]);//affichage des occurences

        for(j=0; j<tablo[i]; j++) //dessin d'une caase en blanc pour chaque occurences
        {
            color(15,15);
            printf("_");

        }

        //correction des bugs graphiques
        color(0,0);
        printf("_");
        color(15,0);
        printf("\n\n");
    }
}
////////////////////////////////////////////////////////////////
