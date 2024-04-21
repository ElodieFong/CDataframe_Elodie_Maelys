#include <stdio.h>
#include <stdlib.h>
#include "column.h"

int main() {
    COLUMN *mycol = create_column("My column\n");
    printf("titre=%s, t_phy=%d, t_log=%d", mycol->titre, mycol->t_phy, mycol->t_log);
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");


    insert_value(mycol, 52);
    insert_value(mycol, 44);
    insert_value(mycol, 15);

    print_col(mycol);

    int num = 44;
    int nbr_occ;
    nbr_occ = nbr_occurence_x(num, mycol);
    printf(" le nombre d'occurence de la valeur 44 est %d\n", nbr_occ);

    int pos = 2;
    printf("la valeur presente a la postition %d est la valeur %d\n", pos, val_pos_x(mycol, pos));

    printf("il y a %d valeurs superieur a %d\n", nbr_val_sup(mycol, num), num);


    delete_column(&mycol);

    int *cdf = create_cdf();
    int nb_col = 5;
    insert_cdf_col(nb_col);

    print_cdf(cdf);

    int lig1=0, lig2=2, col1=0, col2=2;
    print_cdf_lig(cdf, lig1, lig2);
    print_cdf_col(cdf, col1, col2);

    add_cdf_lig(cdf, nb_lig);
    del_cdf_lig(cdf, nb_lig);
    add_cdf_col(cdf, nb_col);
    del_cdf_col(cdf, nb_col);
    rename_col(cdf, nb_col);
    if (val_existe(cdf, val))
        printf("%d existe dans le CDataFrame\n", &val);
    else
        printf("%d n'existe pas dans le CDataFrame\n", &val);
    cellule(cdf, lig, col);
    print_nom_col(cdf);
    return 0;
}