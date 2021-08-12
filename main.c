#include "header.h"

///Main
int main()
{
    ///D�claration
    int choixMenu;                  //choix de l'utilisateur

    double duree;                   //var de calcul de la duree du tri
    clock_t debut, fin;             //var chrono

    //chap1
    t_identite liste [TAILLE];      //tab de strctures

    //chap2
    t_maillonID * ancre;            //ancre de la liste chaine de suspects


    //chap3
    int tabHistoI [25][2];          //tableau pour histo ancienne m�thode
    int tabHistoII[25];             //tableau pour histo nouvelle m�thode
    int tabGene [1000];             //tableau de g�n�ration des 1000 entiers al�atoires

    //bonus : fusion
    t_identite * tabDynaStruct;

    srand(time(NULL));

    color(0,15);
    printf("Pour un meilleur affichage, nous vous recommandons de mettre la console en mode plein ecran ");

    printf(" :)");
    color(0,0);
    printf("_\n\n");
    color(15,0);

    do
    {
        choixMenu = menu();                                             //r�cuperation du choix de l'utilisateur via la fct menu

        if(choixMenu == 1)
        {
            //choix : charger la liste dans un tab de 1000 structs et tri a bulle
            creation(liste);                                            //cr�ation du tab de num

            debut = clock();                                            //d�but du d�compte des ticks du processeur
            triBulle(liste);                                            //tri a bulle
            fin = clock();

            afficherTableau(liste);                                     //affichage num�ro tri�s

            ///AFFICHAGE temps d'execution

            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);                                      //fin du d�compte des ticks
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;               //calcul de la dur�e du tri (soustraction des 2 temps) puis conversion avec la fct CLOCKS_PER_SEC
            printf("\n\nDuree du tri a bulles : %f2 s", duree);

        }

        else if(choixMenu == 2)
        {
            //choix : charger la liste dans un tab de 1000 structs et tri par insertion
            creation(liste);                                            //cr�ation du tab de num

            debut = clock();                                            //d�but du d�compte des ticks du processeur
            triInsertion(liste);                                        //tri par insertion
            fin = clock();                                              //fin du d�compte des ticks

            afficherTableau(liste);                                     //affichage num�ro tri�s

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;              //calcul de la dur�e du tri (soustraction des 2 temps) puis conversion avec la fct CLOCKS_PER_SEC
            printf("\n\nDuree du tri par insertion : %f2 s", duree);                     //affichage dur�e du tri
        }

        else if(choixMenu == 3)
        {
            //choix 3 : charger la liste, en faire une liste chain�e de chaque contact et afficher l'histogramme

            debut = clock();
            ancre = creationListe();                                    //creation de l'histogramme sous forme de liste chain�e
            fin = clock();

            resultat(ancre);                                            //affichage de l'histogramme et du coupable

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nDuree pour former l'histogramme : %f2 s", duree);
        }

        else if(choixMenu == 4)
        {
            //choix 4 : afficher un histogramme d'entiers al�atoires en utilisant la m�me m�thode que l'histo des suspects
            remplir(tabGene);

            debut = clock();
            histogrammeI(tabGene, tabHistoI);                           //cr�ation de l'histogramme d'entiers al�atoires avec l'ancienne m�thode
            fin = clock();

            affichageHistoI(tabHistoI);                                 //affichage de l'histogramme

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nDuree pour former l'histogramme : %f2 s", duree);
        }


        else if(choixMenu == 5)
        {
            //choix 5 : afficher un histogramme d'entiers al�atoires en utilisant une m�thode plus optimis�e
            initialisation(tabHistoII);                             //initialisation du tableau des occurences
            remplir(tabGene);                                       //remplissage du tableau de 1000 entiers al�atoires

            debut = clock();
            histogrammeII(tabGene, tabHistoII);                     //cr�ation d'un histogramme d'entiers al�atoires de fa�on optimis�e
            fin = clock();

            affichageHistoII(tabHistoII);                           //affichage de l'histogramme

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nDuree pour former l'histogramme : %f2 s", duree);
        }



        else if(choixMenu == 6)
        {
            //choix 6 : charger et afficher la liste des appels apr�s un tri par fusion
            creation(liste);                                        //lecture du fichier et sauvegarde dans un tableau fixe de structures de 1000 places
            tabDynaStruct = creationTabDyna(liste);                 //cr�ation du tableau dynamique de 1000 structures d'appels pour pouvoir le trier ensuite

            debut = clock();
            triFusion(tabDynaStruct, TAILLE);                       //tri par fusion
            fin = clock();

            afficherTableauDyn(tabDynaStruct);                      //affichage de la liste d'appels tri�e

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nTemps de tri par fusion : %f2 s", duree);

            free(tabDynaStruct);
        }
        else if(choixMenu == 7)
        {
            //choix 7 : charger et afficher la liste des appels apr�s un tri par s�lection
            creation(liste);                                        //lecture du fichier et sauvegarde dans un tableau fixe de structures de 1000 places fixes

            debut=clock();                                          //debut du compteur de tick
            triSelection(liste);                                    //tri par s�lection
            fin = clock();                                          //fin du compteur de tick

            afficherTableau(liste);                                 //affichage de la liste d'appels

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nTemps de tri par fusion : %f2 s", duree);
        }


        printf("\n\n");
        system("pause");            //mise en pause du programme
        system("CLS");              //nettoyage de l'�cran

    }//choix 7 : quitter le programme
    while(choixMenu != 8);


    return 0;
}
///
