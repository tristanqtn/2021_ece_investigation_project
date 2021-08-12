#include "header.h"

///Main
int main()
{
    ///Déclaration
    int choixMenu;                  //choix de l'utilisateur

    double duree;                   //var de calcul de la duree du tri
    clock_t debut, fin;             //var chrono

    //chap1
    t_identite liste [TAILLE];      //tab de strctures

    //chap2
    t_maillonID * ancre;            //ancre de la liste chaine de suspects


    //chap3
    int tabHistoI [25][2];          //tableau pour histo ancienne méthode
    int tabHistoII[25];             //tableau pour histo nouvelle méthode
    int tabGene [1000];             //tableau de génération des 1000 entiers aléatoires

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
        choixMenu = menu();                                             //récuperation du choix de l'utilisateur via la fct menu

        if(choixMenu == 1)
        {
            //choix : charger la liste dans un tab de 1000 structs et tri a bulle
            creation(liste);                                            //création du tab de num

            debut = clock();                                            //début du décompte des ticks du processeur
            triBulle(liste);                                            //tri a bulle
            fin = clock();

            afficherTableau(liste);                                     //affichage numéro triés

            ///AFFICHAGE temps d'execution

            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);                                      //fin du décompte des ticks
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;               //calcul de la durée du tri (soustraction des 2 temps) puis conversion avec la fct CLOCKS_PER_SEC
            printf("\n\nDuree du tri a bulles : %f2 s", duree);

        }

        else if(choixMenu == 2)
        {
            //choix : charger la liste dans un tab de 1000 structs et tri par insertion
            creation(liste);                                            //création du tab de num

            debut = clock();                                            //début du décompte des ticks du processeur
            triInsertion(liste);                                        //tri par insertion
            fin = clock();                                              //fin du décompte des ticks

            afficherTableau(liste);                                     //affichage numéro triés

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;              //calcul de la durée du tri (soustraction des 2 temps) puis conversion avec la fct CLOCKS_PER_SEC
            printf("\n\nDuree du tri par insertion : %f2 s", duree);                     //affichage durée du tri
        }

        else if(choixMenu == 3)
        {
            //choix 3 : charger la liste, en faire une liste chainée de chaque contact et afficher l'histogramme

            debut = clock();
            ancre = creationListe();                                    //creation de l'histogramme sous forme de liste chainée
            fin = clock();

            resultat(ancre);                                            //affichage de l'histogramme et du coupable

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nDuree pour former l'histogramme : %f2 s", duree);
        }

        else if(choixMenu == 4)
        {
            //choix 4 : afficher un histogramme d'entiers aléatoires en utilisant la même méthode que l'histo des suspects
            remplir(tabGene);

            debut = clock();
            histogrammeI(tabGene, tabHistoI);                           //création de l'histogramme d'entiers aléatoires avec l'ancienne méthode
            fin = clock();

            affichageHistoI(tabHistoI);                                 //affichage de l'histogramme

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nDuree pour former l'histogramme : %f2 s", duree);
        }


        else if(choixMenu == 5)
        {
            //choix 5 : afficher un histogramme d'entiers aléatoires en utilisant une méthode plus optimisée
            initialisation(tabHistoII);                             //initialisation du tableau des occurences
            remplir(tabGene);                                       //remplissage du tableau de 1000 entiers aléatoires

            debut = clock();
            histogrammeII(tabGene, tabHistoII);                     //création d'un histogramme d'entiers aléatoires de façon optimisée
            fin = clock();

            affichageHistoII(tabHistoII);                           //affichage de l'histogramme

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nDuree pour former l'histogramme : %f2 s", duree);
        }



        else if(choixMenu == 6)
        {
            //choix 6 : charger et afficher la liste des appels après un tri par fusion
            creation(liste);                                        //lecture du fichier et sauvegarde dans un tableau fixe de structures de 1000 places
            tabDynaStruct = creationTabDyna(liste);                 //création du tableau dynamique de 1000 structures d'appels pour pouvoir le trier ensuite

            debut = clock();
            triFusion(tabDynaStruct, TAILLE);                       //tri par fusion
            fin = clock();

            afficherTableauDyn(tabDynaStruct);                      //affichage de la liste d'appels triée

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nTemps de tri par fusion : %f2 s", duree);

            free(tabDynaStruct);
        }
        else if(choixMenu == 7)
        {
            //choix 7 : charger et afficher la liste des appels après un tri par sélection
            creation(liste);                                        //lecture du fichier et sauvegarde dans un tableau fixe de structures de 1000 places fixes

            debut=clock();                                          //debut du compteur de tick
            triSelection(liste);                                    //tri par sélection
            fin = clock();                                          //fin du compteur de tick

            afficherTableau(liste);                                 //affichage de la liste d'appels

            ///AFFICHAGE temps d'execution
            printf("\n\nTemps processeur debut : %ld\nTemps processeur fin : %ld\n", debut, fin);
            duree = (double)(fin - debut) / CLOCKS_PER_SEC;
            printf("\n\nTemps de tri par fusion : %f2 s", duree);
        }


        printf("\n\n");
        system("pause");            //mise en pause du programme
        system("CLS");              //nettoyage de l'écran

    }//choix 7 : quitter le programme
    while(choixMenu != 8);


    return 0;
}
///
