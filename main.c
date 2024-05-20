#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"


int main()
{
    COLUMN *mycol = create_column("My column"), *colo = create_column("Second col");
    char* titre;
    printf("Menu:\n");
    printf("Pour creer un CDataframe, taper 1\n Pour quitter, taper 2\n");
    int choix, lig, col, val;
    scanf("%d", &choix);

    //acceder au menu
    if (choix == 1){

        //création et remplissage du CDataframe
        CDF* cdf = create_cdf();
        insert_cdf_col(cdf, mycol);
        //print_cdf(cdf);
        insert_cdf_col(cdf, colo);




        int acces = 0;
        do {//option du menu
            printf("Pour acceder a l'affichage, taper 1\n");
            printf("Pour acceder aux operation usuelles, tapez 2\n");
            printf("Pour acceder aux analyse et statistique, tapez 3\n");
            printf("Pour quittez, tapez 4\n");
            printf("choisir un acces :");
            scanf("%d", &acces);

            if (acces == 1) {

                printf("Pour afficher tout le CDataframe, tapez 1\n");
                printf("Pour afficher une partie des lignes, tapez 2\n");
                printf("Pour afficher une partie des colonnes, tapez 3\n");
                printf("Pour quitter l'affichage, tapez 4\n");
                int affichage = 0;

                do {
                    printf("selectionnner votre choix:");
                    scanf("%d", &affichage);

                    if (affichage == 1) {
                        print_cdf(cdf);
                    }
                    if (affichage == 2) {
                        printf("Entrez la limite de ligne minimum et maximum a afficher tel quel (ligne_min/ligne_max):\n");
                        int lig1, lig2 = 0;
                        scanf("%d/%d", &lig1, &lig2);
                        print_cdf_lig(cdf, lig1, lig2);
                    }
                    if (affichage == 3) {
                        printf("Entrez la limite de colonnes minimum et maximum a afficher tel quel (colonne_min/colonne_max):\n");
                        int col1, col2 = 0;
                        scanf("%d/%d", &col1, &col2);
                        print_cdf_col(cdf, col1, col2);
                    }


                } while (affichage != 4);
            }

            if (acces == 2){
                int operation =0;
                do{
                    printf("pour ajouter une ligne tapez 1\n");
                    printf("pour supprimer une ligne tapez 2\n");
                    printf("pour ajouter une colonne tapez 3\n");
                    printf("pour supprimer une colonne tapez 4\n");
                    printf("pour renommer une colonne tapez 5\n");
                    printf("pour rechercher une valeur tapez 6\n");
                    printf("pour remplacer une valeur, tapez 7\n");
                    printf("pour afficher le nom des colonnes, tapez 8\n");
                    printf("pour quitter, tapez 9\n");

                    printf("choisir l'operation :");
                    scanf("%d", &operation);

                    if(operation == 1){
                        add_cdf_lig(cdf);
                    }
                    if(operation == 2){
                        printf("entrer la ligne à supprimer:\n");
                        scanf("%d", &lig);
                        del_cdf_lig(cdf, lig);
                    }
                    if(operation ==3){
                        printf("entrer le titre de la colonne:\n");
                        scanf("%s", &titre);
                        add_cdf_col(cdf, titre);
                    }
                    if (operation == 4){
                        printf("entrer la colonne à supprimer:\n");
                        scanf("%d", &col);
                        del_cdf_col(cdf, col);
                    }
                    if(operation ==5){
                        printf("entrer le titre de la colonne:\n");
                        scanf("%s", titre);
                        rename_col(cdf, 2, titre);
                    }
                    if(operation == 6){
                        if (val_existe(cdf, 52))
                            printf("%d existe dans le CDataFrame\n", 52);
                        else
                            printf("%d n'existe pas dans le CDataFrame\n", 52);
                    }
                    if(operation == 7){
                        cellule(cdf, 2, 3, 10);
                    }
                    if(operation ==8){
                        print_noms_col(cdf);
                    }

                }while (operation != 9);
            }


            if (acces == 3){
                int analyse = 0;

                do{
                    printf("pour afficher le nombre de ligne, tapez 1\n");
                    printf("pour afficher le nombre de colonne, tapez 2\n");
                    printf("pour afficher le nombre de valeur egal a X, tapez 3\n");
                    printf("pour afficher le nombre de valeur superieur a X, tapez 4\n");
                    printf("pour afficher le nombre de valeur inferieur a X, tapez 5\n");
                    printf("pour quittez, tapez 6\n");
                    printf("entrez votre choix d'affichage :\n");
                    scanf("%d", &analyse);

                    if(analyse == 1){
                        printf("\nil y a %d ligne\n", nb_lig_cdf(cdf));
                    }
                    if(analyse == 2){
                        printf("il y a %d colonne\n", nb_col_cdf(cdf));
                    }
                    if(analyse == 3){
                        scanf("%d", &val);
                        printf("il y a %d fois une valeur egal a %d\n", cel_val_egal(cdf, val), val);
                    }
                    if(analyse == 4){
                        scanf("%d", &val);
                        printf("il y a %d fois une valeur inferieur a %d\n", cel_val_inf(cdf, val), val);
                    }
                    if(analyse == 5){
                        scanf("%d", &val);
                        printf("il y a %d fois une valeur superieur a %d\n", cel_val_sup(cdf, val), val);
                    }

                }while(analyse != 6);
            }
        }while(acces != 4);


    }
    if (choix == 2){
        return 0;
    }
    return 0;
}