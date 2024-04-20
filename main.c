#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main() {
    COLUMN *mycol = create_column("My column");
    printf("titre=%s, t_phy=%d, t_log=%d", mycol->titre, mycol->t_phy, mycol->t_log);
    int val = 5;
    if (insert_value(mycol, val))
        printf("\nValue added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    printf("%d", mycol->tab[0]);


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


    return 0;
}