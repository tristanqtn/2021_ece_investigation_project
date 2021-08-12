#include "header.h"

///Tracer le graphique//////////////////////////////////////////
void graphe()
{
    int i;
    system("CLS");

    printf("NB d'appels \n^\n"); //Fl�che et l�gende
    for (i=0; i<25; i++)
    {
        printf("%c\n", 0xB3);    //barres verticales
    }

    printf("%c", 0xC0);         //Coin en bas � gauche
    for (i=0; i<110; i++)
    {
        printf("%c", 0xC4);     //barres horizontales
    }
    printf("> Suspects\n");      //Fl�che et l�gende

    gotoligcol(4, 100);         //L�gende couleurs
    color(15, 12);
    printf("Appels Entrants");
                                    //Correction bug d'affichage en grand �cran
                                    color(0, 0);
                                    printf("_");
    gotoligcol(3, 100);             //L�gende couleurs
    color(15, 10);
    printf("Appels Sortants");
                                    //Correction bug d'affichage en grand �cran
                                    color(0, 0);
                                    printf("_");
}
////////////////////////////////////////////////////////////////


///Affichage des barres de l'histogramme et profil des suspects/
void resultat(t_maillonID * ancre)                //Il y a parfois peu de commentaires car une grande partie du code est prise par les fonctions d'affichage gotoligcol() et color()
{
    //D�clarations
    int i, z, j = 4;

    t_maillonID * parcours;
    t_maillonID * coupable;

    //Initialisations
    parcours = ancre;
    coupable = ancre;

    //Affichage du graphe
    graphe();

    while(parcours!= NULL)  //On parcourt toute la liste cha�n�e
    {
        for (i = 26; i> 26-((parcours->compteur )/6); i--) //On affiche en vert le nombre total d'appel en baton
        {
            gotoligcol(i, j);
            color(10,10);
            printf("_");
            color(0,0);
            printf("__");
        }

        gotoligcol(i, j-1);
        color(15,0);
        printf("%d", parcours->compteur);  //On affiche le nombre d'appels total en haut de chaque baton


        for (i = 26; i> 26 -((parcours->appelEntrant )/6); i--)    //On affiche par dessus en rouge le nombre d'appels entrant en baton
        {
            gotoligcol(i, j);
            color(12,12);
            printf("_");
            color(0,0);
            printf("__");
        }

        if(j%8== 0)   //On affiche en quinconce les initiales des suspects par manque de place gr�ce � l'utilisation du modulo
            z=29;

        else
            z=30;

        gotoligcol(z, j-1);
        color(15, 0);
        printf("%c.%c ", parcours->suspect.prenom[0], parcours->suspect.nom[0]);   //On explicite la correspondance des initiales avec les identit�s des personnes

        gotoligcol(32 ,0);              //Utilisation de la fonction gotoligcol() car les \t ne suffisent pas � aligner les diff�rentes cat�gories
        printf("Initiales");
        gotoligcol(32 ,12);             //Titres du tableau
        printf("Prenom NOM");
        gotoligcol(32 ,34);
        printf("Numero");
        gotoligcol(32,50);
        printf("NB appels");
        gotoligcol(32,62);
        printf("NB appels entrant");

        gotoligcol(j/4+33 ,0);
        printf("%c. %c :", parcours->suspect.prenom[0], parcours->suspect.nom[0]);    //corps du tableau
        gotoligcol(j/4+33 ,8);
        printf("%s %s", parcours->suspect.prenom, parcours->suspect.nom );
        gotoligcol(j/4+33 ,33);
        printf("+%s", parcours->suspect.numero);
        gotoligcol(j/4+33 ,55);
        printf("%d", parcours->compteur);
         gotoligcol(j/4+33 ,65);
        printf("%d", parcours->appelEntrant);



        if(parcours->compteur > coupable->compteur) //On cherche le suspect avec le compteur le plus important
        {
            coupable = parcours;
        }

        j+= 4; //Incr�mentation pour la localisation du baton du suspect suivant
        parcours = parcours->suivant;    //Incr�mentation de la liste cha�n�e vers le maillon suivant

    }

    //Affichage du nom du coupable
    gotoligcol(j/4 +35, 0);
    color(0, 12);


    if(coupable->appelEntrant > (coupable->compteur - coupable->appelEntrant))
    {
        printf("Le coupable est %s %s avec %d appels dont %d entrants", coupable->suspect.prenom, coupable->suspect.nom, coupable->compteur, coupable->appelEntrant);
    }

    else
    {
        printf("Le suspect %s %s a ete harcele par Lena avec %d appels de la part de Lena", coupable->suspect.prenom, coupable->suspect.nom, (coupable->compteur - coupable->appelEntrant));
    }

    //Correction bug d'affichage
    color(0, 0);
    printf("_");

    gotoligcol(65,0);
    color(15, 0);


}
////////////////////////////////////////////////////////////////


///Code emprunt� sur moodle
///////////////////////////////////////
// Nom du sous-programme : COLOR
// R�le : change la couleur du texte dans la console, ainsi que la couleur du fond pour la ligne
// Compatibilit� : windows XP
////////////////////////////////////////////////////////////////

///COLOR////////////////////////////////////////////////////////
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

 /*
    0 : Noir
    1 : Bleu fonc�
    2 : Vert fonc�
    3 : Turquoise
    4 : Rouge fonc�
    5 : Violet
    6 : Vert caca d'oie
    7 : Gris clair
    8 : Gris fonc�
    9 : Bleu fluo
    10 : Vert fluo
    11 : Turquoise
    12 : Rouge fluo
    13 : Violet 2
    14 : Jaune
    15 : Blanc
    */

////////////////////////////////////////////////////////////////

///GO TO LIG COL////////////////////////////////////////////////
void gotoligcol( int lig, int col )
{
// ressources : MOODLE

//HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
COORD mycoord;

mycoord.X = col;
mycoord.Y = lig;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
////////////////////////////////////////////////////////////////


///Allocation d'un nouveau maillon//////////////////////////////
t_maillonID * allocation()   //Cr�er et alloue dynamiquement un maillon
{
    t_maillonID * nouveau;

    nouveau = (t_maillonID*)malloc(sizeof(t_maillonID));

    nouveau->suivant = NULL;   //Initialisation du pointeur sur suivant
    nouveau->compteur = 0;     //Initialisation des compteurs
    nouveau->appelEntrant = 0;

    return nouveau;
}
////////////////////////////////////////////////////////////////


///Cr�ation de la liste chain�e de profils//////////////////////
//Cr�ation d'un maillon dans la liste pour chaque nouveau contact
t_maillonID * creationListe()
{
     ///D�claration des structures
    t_maillonID * ancre;
    t_maillonID * courant;

     ///D�claration des variables utiles au SP
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

    ///Lecture des 1000 appels
    else
    {
        for(i=0; i<1000; i++)
        {
            courant = allocation();

            if(i != 0)
            {
                //lecture de l'espace
                fflush(stdin);
                fscanf(dossier, "%c", &inutile);
            }


            //lecture de l'esapce
            fflush(stdin);
            fscanf(dossier, "%c", &inutile);

            //lecture du plus
            fflush(stdin);
            fscanf(dossier, "%c", &inutile);

            //lecture du num
            fflush(stdin);
            fscanf(dossier, "%s", courant->suspect.numero);

            //lecture du nom
            fflush(stdin);
            fscanf(dossier, "%s", courant->suspect.prenom);


            fflush(stdin);
            fscanf(dossier, "%c", &inutile);

            //lecture du prenom
            fflush(stdin);
            fscanf(dossier, "%s", courant->suspect.nom);

            fflush(stdin);
            fscanf(dossier, "%c", &inutile);

            //lecture num
            fflush(stdin);
            fscanf(dossier, "%s", courant->suspect.appel);

            if(i==0) //Test de si c'est le premier maillon ou non
            {
                ancre = courant; //Si oui, il devient l'ancre
            }
            else
            {
                ancre = ajout(ancre, courant);   //Sinon, on appelle de SP d'ajout
            }

        }

        //fermeture
        fclose(dossier);
    }
    return ancre;
}
////////////////////////////////////////////////////////////////


///Ajout en queue///////////////////////////////////////////////
t_maillonID * ajout(t_maillonID * ancre, t_maillonID * nouveau)
{
    int occurence = 0;
    t_maillonID * parcours;

    parcours = ancre;

    ///Parcours de la liste cha�n�e � la recherche d'une occurence
    while((parcours->suivant != NULL) && (occurence ==0) )   //On parcourt la liste cha�n�e tant qu'on a pas trouv� d'occurences
    {
        if(strcmp(nouveau->suspect.numero,parcours->suspect.numero)==0)       //si il y a une occurence
        {
            occurence ++;                                                     //On incr�mente cette variable pour sortir de la boucle
            parcours->compteur ++;                                            //on incr�mente le compteur de maillon de la liste chain�e correspondant

             if(strcmp("Entrant", nouveau->suspect.appel)== 0)                //test de si l'appel est un appel entrant
            {
                parcours->appelEntrant ++;                                    // Si oui, on incr�mente
            }
        }
        parcours = parcours ->suivant;                                        //incr�mentation de la boucle while
    }
     ///Une derni�re fois pour le dernier maillon
    if(strcmp(nouveau->suspect.numero,parcours->suspect.numero)==0)
    {

        occurence ++;
        parcours->compteur ++;

        if(strcmp("Entrant", nouveau->suspect.appel)== 0)
        {
            parcours->appelEntrant ++;
        }
    }


    ///Ajout en queue si pas d'occurences
    if(occurence == 0)
    {
        parcours->suivant = nouveau;
        nouveau->compteur = 1;                                              //Initialisation du compteur � 1
        if(strcmp("Entrant", nouveau->suspect.appel)== 0)
        {
            parcours->appelEntrant =1;                                      //test si appel entrant
        }
    }

    return ancre;  //On a besoin de rendre l'ancre car � ubn moment le pointeur sur suivant e l'ancre va �tre modifi�
}
////////////////////////////////////////////////////////////////
