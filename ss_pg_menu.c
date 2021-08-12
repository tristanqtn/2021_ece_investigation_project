#include "header.h"

///Menu/////////////////////////////////////////////////////////
int menu ()
{
    ///Déclarations
    int choixUtil;

    printf("Veuillez saisir le numero de l'action a realiser :\n\n");
    printf("\t1. Charger la liste et la trier (tri a bulle)\t\t\t\tCHAP I\n");
    printf("\t2. Charger la liste et la trier (tri par insertion)\t\t\tCHAP I\n");
    printf("\t3. Afficher un histogramme des appels\t\t\t\t\tCHAP II\n");
    printf("\t4. Creer un histogramme d'occurence de nombres aleatoires\t\tCHAP III (methode I non optimisee)\n");
    printf("\t5. Creer un histogramme d'occurence de nombres aleatoires\t\tCHAP III (methode II optimisee)\n");
    printf("\n\t6. Charger la liste et la trier (tri par fusion)\t\t\tCHAP I (bonus)\n");
    printf("\t7. Charger la liste et la trier (tri par selection)\t\t\tCHAP I (bonus)\n");
    printf("\n\t8. Quitter le programme\n");
    printf("\nChoix : ");

    //saisie blindée
    do
    {
        scanf("%d", &choixUtil);
    }while(choixUtil<1 || choixUtil>8);

    printf("\n\n\n");

    return (choixUtil);         //rendu du choix utilisateur
}
////////////////////////////////////////////////////////////////
