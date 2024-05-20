#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"


int main()
{
    COLUMN *mycol = create_column("My column"), *colo = create_column("afubglobg");
    printf("Menu:\n");
    printf("Pour creer un CDataframe, taper 1\n Pour quitter, taper 2\n");
    int choix;
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
                        printf("truc");
                    }
                    if (affichage == 3) {
                        printf("Entrez la limite de colonnes minimum et maximum a afficher tel quel (ligne_min/ligne_max):\n");
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
                        add_cdf_lig(cdf, 1);
                    }
                    if(operation == 2){
                        del_cdf_lig(cdf, 1);
                    }
                    if(operation ==3){
                        add_cdf_col(cdf, "newCol");
                    }
                    if (operation == 4){
                        del_cdf_col(cdf, 3);
                    }
                    if(operation ==5){
                        rename_col(cdf, 2, "titre");
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

                    printf("entrez votre choix d'affichage :");
                    scanf("%d", &analyse);

                    if(analyse == 1){
                        printf("\nil y a %d ligne\n", nb_lig_cdf(cdf));
                    }
                    if(analyse == 2){
                        printf("il y a %d colonne\n", nb_col_cdf(cdf));
                    }
                    if(analyse == 3){
                        int val = 4;
                        printf("il y a %d fois une valeur egal a 4\n", cel_val_egal(cdf, val));
                    }
                    if(analyse == 4){
                        int val = 4;
                        printf("il y a %d fois une valeur inferieur a 4\n", cel_val_inf(cdf, val));
                    }
                    if(analyse == 5){
                        int val = 4;
                        printf("il y a %d fois une valeur superieur a 4\n", cel_val_sup(cdf, val));
                    }

                }while(analyse != 6);
            }
        }while(acces != 4);


    }
    if (choix == 2){
        return 0;
    }



    /*printf("titre=%s, t_phy=%d, t_log=%d", mycol->titre, mycol->t_phy, mycol->t_log);
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");


    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);
    insert_value(mycol, 75);
    insert_value(mycol, 3);

    print_col(mycol);

    int num = 44;
    int nbr_occ;
    nbr_occ = nbr_occurence_x(num, mycol);
    printf(" le nombre d'occurence de la valeur 44 est %d\n", nbr_occ);

    int pos = 2;
    printf("la valeur presente a la postition %d est la valeur %d\n", pos, val_pos_x(mycol, pos));

    printf("il y a %d valeurs superieures a %d\n", nbr_val_sup(mycol, num), num);
    printf("il y a %d valeurs inferieur a %d\n", nbr_val_inf(mycol, num), num);
    printf("il y a %d valeurs egal a %d\n", nbr_val_equ(mycol, num), num);



    delete_column(&mycol);*/
/*
    insert_value(mycol, 52);
    insert_value(mycol, 59);
    insert_value(colo, 98);
    insert_value(colo, 24);*/
// donner pres enregistrer
/*
    CDF* cdf = create_cdf();
    insert_cdf_col(cdf, mycol);
    //print_cdf(cdf);
    insert_cdf_col(cdf, colo);
    print_cdf(cdf);*/
    //print_cdf_lig(cdf, 1, 2);
    //print_cdf_col(cdf, 1, 1);
    //add_cdf_lig(cdf);
    //add_cdf_col(cdf, "newCol");
    //add_cdf_col(cdf, "test");
    //del_cdf_lig(cdf, 1);
    //add_cdf_lig(cdf);
    //del_cdf_col(cdf, 3);
    //rename_col(cdf, 2, "titre");
    //cellule(cdf, 2, 3, 10);
    //print_cdf(cdf);
    /*if (val_existe(cdf, 52))
        printf("%d existe dans le CDataFrame\n", 52);
    else
        printf("%d n'existe pas dans le CDataFrame\n", 52);
    print_noms_col(cdf);

    printf("\nil y a %d ligne\n", nb_lig_cdf(cdf));
    printf("il y a %d colonne\n", nb_col_cdf(cdf));


    int val = 4;
    printf("il y a %d fois une valeur egal a 4\n", cel_val_egal(cdf, val));
    printf("il y a %d fois une valeur inferieur a 4\n", cel_val_inf(cdf, val));
    printf("il y a %d fois une valeur superieur a 4\n", cel_val_sup(cdf, val));
*/

/*
    int lig1=0, lig2=2, col1=0, col2=2;
    print_cdf_lig(cdf, lig1, lig2);
    print_cdf_col(cdf, col1, col2);

    int lig = 5, col = 5;
    add_cdf_lig(cdf, lig);
    del_cdf_lig(cdf, lig);
    add_cdf_col(cdf, col);
    del_cdf_col(cdf, col);
    rename_col(cdf, col);

    cellule(cdf, lig, col);
    print_nom_col(cdf);

    nb_lig_cdf(cdf);
    nb_col_cdf(cdf);

    int nb_cel = cel_val_egal(cdf, val);
    printf("il y a %d cellules égales à %d\n", nb_cel,val);

    nb_cel = cel_val_sup(cdf, val);
    printf("il y a %d cellules supérieures à %d\n", nb_cel,val);

    nb_cel = cel_val_inf(cdf, val);
    printf("il y a %d cellules inférieures à %d\n", nb_cel,val);*/
    return 0;
}