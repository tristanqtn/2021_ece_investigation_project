#include "header.h"

///Inititalisation//////////////////////////////////////////////
void initialisation (int tableau [25])
{
    ///D�claration
    int i;

    for(i=0; i<25; i++)
    {//remplir le tableau d'entiers de 0 pour pouvoir incr�menter les compteurs
        tableau[i]=0;
    }
}

///Remplir
void remplir (int tab [1000])
{
    ///D�clarations
    int i;

    for(i=0; i<1000; i++)
    {// remplir le tableau de 1000 entiers avec des entiers al�atoires entre 0 et 24 bornes comprises
        tab[i] = rand() %25;
    }
}
////////////////////////////////////////////////////////////////


///Cr�ation du premier histogramme//////////////////////////////
void histogrammeI (int tabAlea [1000], int tableau [25][2])
{
    ///D�clarations
    int i, j;

    //initialisation du tableau de l'histogramme
    for(i=0; i<25; i++)
    {
        tableau[i][0]= -1; //initialisation � -1 pour qu'aucune valeur al�atoire ne corresponde
        tableau[i][1]= 0;  //initialisation � 0 des compteur pour incr�mentation
    }


    for(i=0; i<1000; i++)
    {//parcours du tableau de 1000 entiers al�atoires
        j=0; //mise � 0 de l'indice de parcours j
        while(j<25)
        {//parcours du tableau de l'histogramme
            if(tabAlea[i] == tableau[j][0])
            {//si une case du tableau est d�j� prise par un entier entre 0 et 24
                tableau[j][1]++; //incr�mentation du compteur d'occurence de cet entier
                j=25; //on sort de la boucle TANT QUE
            }
            else if(tableau[j][0] == -1)
            {//si cet entier ne figure pas encore dans le tableau,
                tableau[j][0] = tabAlea[i]; //on stock la valeur de cet entier dans la premi�re dimension du tableau
                tableau[j][1] = 1;//on met � 1 le nombre d'occurence de ce nouvel entier dans la deuxi�me dimension du tableau
                j = 25; //on sort de la boucle TANT QUE
            }
            j++; //incr�mentation de la variable de parcours
        }
    }
}

///Cr�ation du deuxi�me histogramme
void histogrammeII (int tabAlea [1000], int tableau [25])
{
    ///D�clarations
    int i;

    for(i=0; i<1000; i++)
    {//parcours du tableau de 1000 al�atoires
        tableau[tabAlea[i]] ++; //incr�mentation du compteur � chaque d�tecttion d'occurence
    }
}
////////////////////////////////////////////////////////////////


///Affichage du premier histogramme/////////////////////////////
void affichageHistoI (int tablo [25][2])
{
    ///D�clarations
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


///Affichage du deuxi�me histogramme////////////////////////////
void affichageHistoII (int tablo [25])
{
    ///D�clarations
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
