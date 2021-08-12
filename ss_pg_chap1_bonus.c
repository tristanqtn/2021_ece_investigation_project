#include "header.h"

//Le tri par fusion nécéssite de diviser le tableau jusqu'à l'obtention de tableaux ne possédants qu'un seul élément
//Pour cela, il est nécéssaire que le tableau de structures de départ de 1000 places soit dynamique



///Création d'un tableau dynamique de 1000 structures///////////
t_identite * creationTabDyna (t_identite tabFix[TAILLE])
{
    ///Déclarations
    int i;
    t_identite * monTab;

    monTab = (t_identite *) malloc (sizeof(t_identite) * TAILLE);

    //copie des structures du tableau fixe vers dynamique
    for (i=0; i<TAILLE; i++)
    {
        monTab[i] = tabFix[i];
    }

    return monTab; //rendu du tableau dynamique
}
///////////////////////////////////////////////////////////////


///TRI FUSION//////////////////////////////////////////////////
void triFusion (t_identite * tableau, int place)
{
    ///Déclarations
    int i;
    t_identite * tab1;
    t_identite * tab2;

    //allocation des tableaux
    tab1 = (t_identite*)malloc((place/2)*sizeof(t_identite));
    tab2 = (t_identite*)malloc((place - (place/2))*sizeof(t_identite));

    //copie des élements du tableau dans les deux sous-tableaux
    for(i=0; i<place/2; i++)
    {
        tab1[i] = tableau[i];
    }
    for(i=0; i<(place - (place/2)); i++)
    {
        tab2[i] = tableau[i+(place/2)];
    }

    //actions selon la taille des tableaux
    if (place > 3)   //Si il y a un moins 2 éléments par sous-tableaux
    {
        triFusion(tab1, place/2);          //Appel par récursivité du SP pour les deux sous-tableaux
        triFusion(tab2, (place-(place/2)));
    }
    else if(place == 3) //Seulement le premier tableau possède plusieurs éléments
    {
        triFusion(tab2, place/2 + 1);   //appel du SP récursid uniquement pour le premier tableau
    }


    //fusion des deux tableaux de façon triée
    fusion(tableau, tab1, tab2, place);

    free(tab1);
    free(tab2);
}
////////////////////////////////////////////////////////////////


///FUSION///////////////////////////////////////////////////////
void fusion(t_identite * tableau, t_identite * tab1, t_identite * tab2, int place)
{
    ///Déclarations
    int i,  pos1 = 0, pos2 =0;

    //Fusion des deux sous_tableaux dans le tableau principale de manière triée
    for(i=0; i<place; i++)
    {
        //Pour cela, on effectue plusieurs test sur la composition des tableaus

        ///1- Le second tableau encore des éléments alors que le premier a déja donné
        if((pos1 == place/2) && (pos1 + pos2 < place))
        {
            tableau[i]= tab2[pos2];  //On complète avec l'élément en plus du dernier tableau
            pos2 ++;                //Incrémentation de la place du dernier élément non ajouté
        }
        ///2- Le premier tableau encore des éléments alors que le second a déja donné
        else if((((pos2 == place/2) && (place%2) == 0) || ((pos2 == (place/2 + 1)) && (place%2) == 1)) && (pos1 + pos2 < place))//2 cas : le second tableau est paire ou impaire
        {
            tableau[i] = tab1[pos1];
            pos1++;                 //Incrémentation de la place du dernier élément non ajouté
        }
        ///3- Les deux tableaux sont encore remplis : on prend le plus petit élément
        else if((strcmp(tab1[pos1].numero, tab2[pos2].numero) == 0) || (strcmp(tab1[pos1].numero, tab2[pos2].numero) == -1)) //Les 2 tab sont égaux ou le premier est plus petit
        {
            tableau[i] = tab1[pos1];
            pos1++;
        }
        else if(strcmp(tab1[pos1].numero, tab2[pos2].numero) == 1) //le 1er tab est plus grand que le 2eme
        {
            tableau[i] = tab2[pos2];
            pos2++;
        }
    }
}
////////////////////////////////////////////////////////////////


///AFFICHAGE////////////////////////////////////////////////////
void afficherTableauDyn(t_identite * tableau)
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


///TRI SELECTION////////////////////////////////////////////////
void triSelection (t_identite liste [TAILLE])
{
    ///Déclarations
    int i, j, min;
    t_identite tmp;

    for(i=0; i<(TAILLE-1); i++)
    {//parcours du tableau de 999 structures d'appels

        min = i; //min prend la valeur en cours de l'indice de parcours

        for(j=i+1; j<TAILLE; j++)
        {//parcours du tzbleau de 1000 appels

            if (strcmp(liste[j].numero,liste[min].numero)== -1)
            {//si le num de téléphone actuelle est plus petit que le numéro enregistré précédemment
                min = j; //le mini devient l'indice de la case de ce numéro
            }
        }
        if(min!=i)
        {//si min à changé d'état durant la boucle
            //échange les 2 structures de place
            tmp = liste[i];
            liste[i] = liste[min];
            liste[min] = tmp;
        }
    }
}
////////////////////////////////////////////////////////////////
