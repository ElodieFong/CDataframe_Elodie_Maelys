#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"

int main()
{
    COLUMN *mycol = create_column("My column"), *colo = create_column("afubglobg");
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

    insert_value(mycol, 52);
    insert_value(mycol, 59);
    insert_value(colo, 98);
    insert_value(colo, 24);

    CDF* cdf = create_cdf();
    insert_cdf_col(cdf, mycol);
    //print_cdf(cdf);
    insert_cdf_col(cdf, colo);
    print_cdf(cdf);
    print_cdf_lig(cdf, 1, 2);
    print_cdf_col(cdf, 1, 2);
    //add_cdf_lig(cdf);
    //insert_cdf_col(cdf, colo);
    del_cdf_lig(cdf, 2);
    add_cdf_lig(cdf);
    del_cdf_col(cdf, 2);
    print_cdf(cdf);

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
    if (val_existe(cdf, val))
        printf("%d existe dans le CDataFrame\n", val);
    else
        printf("%d n'existe pas dans le CDataFrame\n", val);
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