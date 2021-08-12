#include "header.h"

//Le tri par fusion n�c�ssite de diviser le tableau jusqu'� l'obtention de tableaux ne poss�dants qu'un seul �l�ment
//Pour cela, il est n�c�ssaire que le tableau de structures de d�part de 1000 places soit dynamique



///Cr�ation d'un tableau dynamique de 1000 structures///////////
t_identite * creationTabDyna (t_identite tabFix[TAILLE])
{
    ///D�clarations
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
    ///D�clarations
    int i;
    t_identite * tab1;
    t_identite * tab2;

    //allocation des tableaux
    tab1 = (t_identite*)malloc((place/2)*sizeof(t_identite));
    tab2 = (t_identite*)malloc((place - (place/2))*sizeof(t_identite));

    //copie des �lements du tableau dans les deux sous-tableaux
    for(i=0; i<place/2; i++)
    {
        tab1[i] = tableau[i];
    }
    for(i=0; i<(place - (place/2)); i++)
    {
        tab2[i] = tableau[i+(place/2)];
    }

    //actions selon la taille des tableaux
    if (place > 3)   //Si il y a un moins 2 �l�ments par sous-tableaux
    {
        triFusion(tab1, place/2);          //Appel par r�cursivit� du SP pour les deux sous-tableaux
        triFusion(tab2, (place-(place/2)));
    }
    else if(place == 3) //Seulement le premier tableau poss�de plusieurs �l�ments
    {
        triFusion(tab2, place/2 + 1);   //appel du SP r�cursid uniquement pour le premier tableau
    }


    //fusion des deux tableaux de fa�on tri�e
    fusion(tableau, tab1, tab2, place);

    free(tab1);
    free(tab2);
}
////////////////////////////////////////////////////////////////


///FUSION///////////////////////////////////////////////////////
void fusion(t_identite * tableau, t_identite * tab1, t_identite * tab2, int place)
{
    ///D�clarations
    int i,  pos1 = 0, pos2 =0;

    //Fusion des deux sous_tableaux dans le tableau principale de mani�re tri�e
    for(i=0; i<place; i++)
    {
        //Pour cela, on effectue plusieurs test sur la composition des tableaus

        ///1- Le second tableau encore des �l�ments alors que le premier a d�ja donn�
        if((pos1 == place/2) && (pos1 + pos2 < place))
        {
            tableau[i]= tab2[pos2];  //On compl�te avec l'�l�ment en plus du dernier tableau
            pos2 ++;                //Incr�mentation de la place du dernier �l�ment non ajout�
        }
        ///2- Le premier tableau encore des �l�ments alors que le second a d�ja donn�
        else if((((pos2 == place/2) && (place%2) == 0) || ((pos2 == (place/2 + 1)) && (place%2) == 1)) && (pos1 + pos2 < place))//2 cas : le second tableau est paire ou impaire
        {
            tableau[i] = tab1[pos1];
            pos1++;                 //Incr�mentation de la place du dernier �l�ment non ajout�
        }
        ///3- Les deux tableaux sont encore remplis : on prend le plus petit �l�ment
        else if((strcmp(tab1[pos1].numero, tab2[pos2].numero) == 0) || (strcmp(tab1[pos1].numero, tab2[pos2].numero) == -1)) //Les 2 tab sont �gaux ou le premier est plus petit
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
    ///D�clarations
    int i, j, min;
    t_identite tmp;

    for(i=0; i<(TAILLE-1); i++)
    {//parcours du tableau de 999 structures d'appels

        min = i; //min prend la valeur en cours de l'indice de parcours

        for(j=i+1; j<TAILLE; j++)
        {//parcours du tzbleau de 1000 appels

            if (strcmp(liste[j].numero,liste[min].numero)== -1)
            {//si le num de t�l�phone actuelle est plus petit que le num�ro enregistr� pr�c�demment
                min = j; //le mini devient l'indice de la case de ce num�ro
            }
        }
        if(min!=i)
        {//si min � chang� d'�tat durant la boucle
            //�change les 2 structures de place
            tmp = liste[i];
            liste[i] = liste[min];
            liste[min] = tmp;
        }
    }
}
////////////////////////////////////////////////////////////////
