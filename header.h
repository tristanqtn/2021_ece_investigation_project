/**
 * CODE REDIGE PAR APOLLINE PETIT ET TRISTAN QUERTON
 * COURS : ETUDE DE CAS
 * PROFESSEUR : M SEGADO
 * DATE : 18/04/2021
 */


/** HYPOTHESES et démarche informatique pour aborder le sujet
 *
 * Pour le chapitre I nous utilisons un tableau de 1000 structures d'appels car nous connaissons le nombre d'appels à stocker
 *              -> nous utilisons une structure pour stocker indépendamment tout les éléments d'un appel (contact, numéro, type d'appel, ...)
 *              -> cette structure sera ensuite réutilisée dans une autre sutructure dans le CHAP II pour former une liste chainée
 *
 * Pour le chapitre II nous créons une liste chainée, elle nous permet de parcourir qu'une seule fois le releve d'appels et de créer un maillon pour chaque contact
 *              -> la création de cette liste est à partir d'une liste d'appels non triée et directement lue dans le fichier "releve.txt"
 *
 * Pour le capitre III nous utilisons une génération aléatoire d'entiers entre 0 et 24 bornes comprises (donc 25 valeurs possibles, autant que de suspects)
 *              -> D'abord, nous appliquons la même méthode que pour lh'histogramme des appels
 *              -> Ensuite, nous essayons d'optimiser les traitements d'histogramme en utilisant une unique boucle for().
 *                  -> en conclusion nous ne pouvons pas appliquer cette optimisation à nos traitements de structures
 *
 *
 * ATTENTION  : les tris proposés sont rapides car le nombre de données à traiter est petit.
 *              -> il est donc possible que le temps de tri affiché soit 0.0000s ou 0.0000002s ou encore des valeurs négatives lié à une erreur de calcul de la période
 *                  -> pour palier cela il suffit de relancer le programme de tri une nouvelle fois
 *                      -> ce sont des erreurs liées à de multiples compilations et éxécution en série du programme sur le même processeur
 *
*/



/** Sources 
 * https://github.com/
 * https://www.cplusplus.com/
 * https://www.101computing.net/bubble-sort-vs-insertion-sort/
 * https://waytolearnx.com/2019/08/tri-a-bulle-en-c.html
 * https://waytolearnx.com/2019/08/tri-par-insertion-en-c.html
 * https://waytolearnx.com/2019/08/tri-par-selection-en-c.html
 * https://openclassrooms.com/fr/courses/19980-apprenez-a-programmer-en-c
 * https://c.developpez.com/faq/?page=Gestion-des-dates-et-heures#Comment-chronometrer-des-temps-d-execution
 * 
 * Tout les algorythmes sont issues d'algorythmes libres de droits disponibles sur les sites ci-joint.
 * 
*/





//PREPROCESSOR//////////////////////////////////////////////////
#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
////////////////////////////////////////////////////////////////

//LIBRARIES/////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
////////////////////////////////////////////////////////////////

//DEFINE////////////////////////////////////////////////////////
#define TAILLE 1000
////////////////////////////////////////////////////////////////

//STRUCTURES////////////////////////////////////////////////////
typedef struct identite
{
    char nom[20];
    char prenom[20];
    char numero[12];
    char appel[10];

}t_identite;

////////////////////////////////////////////////////////////////

typedef struct maillonID        //Pour la liste chainée du chap 2
{
    t_identite suspect;         //Appelle la structure précédente
    int compteur;               //compte le nombre d'appels
    int appelEntrant;

    struct maillonID *suivant;  //pointeur sur le maillon suivant;

}t_maillonID;
////////////////////////////////////////////////////////////////


//PROTOTYPES////////////////////////////////////////////////////
int menu ();

///CHAP1
void creation(t_identite liste[TAILLE]);
void afficherTableau(t_identite tableau[TAILLE]);

//Tris
void  triBulle (t_identite liste [TAILLE]);
void triInsertion(t_identite liste[TAILLE]);


///CHAP2
t_maillonID * allocation();
t_maillonID * creationListe();
t_maillonID * ajout(t_maillonID * ancre, t_maillonID * nouveau);

void resultat(t_maillonID * ancre);

//Affichage histogramme
void baton();
void graphe();
void gotoligcol( int lig, int col );
void color(int couleurDuTexte,int couleurDeFond);

///CHAP3
//Méthode I
void affichageHistoI (int tablo [25][2]);
void histogrammeI (int tabAlea [1000], int tableau [25][2]);


//Méthode II
void remplir (int tab [1000]);
void initialisation (int tableau [25]);
void affichageHistoII (int tablo [25]);
void histogrammeII (int tabAlea [1000], int tableau [25]);


///BONUS tri par fusion
void afficherTableauDyn(t_identite * tableau);
void triFusion (t_identite * tableau, int place);
void fusion(t_identite * tableau, t_identite * tab1, t_identite * tab2, int place);

t_identite * creationTabDyna (t_identite tabFix[TAILLE]);

///BONUS tri par sélection
void triSelection(t_identite liste[25]);
////////////////////////////////////////////////////////////////


#endif // HEADER_H_INCLUDED



