//
// Created by maely on 19/04/2024.
//

#include "fonctions.h"

COLUMN *create_column(char* title)
{
    COLUMN *col = malloc(sizeof(COLUMN));
    col->titre = title;
    col->t_phy = 0;
    col->t_log = 0;
    col->tab = NULL;
    return col;
}

int insert_value(COLUMN* col, int value)
{
    int* tmp;
    if (col->t_phy==0)
    {
        col->tab = malloc(REALOC_SIZE*sizeof(int));
        col->t_phy += REALOC_SIZE;
    }
    if (col->t_phy==col->t_log)
    {
        tmp = realloc(col->tab, REALOC_SIZE*sizeof(int));
        if (tmp==NULL)
            return 0;
        col->tab = tmp;
        col->t_phy += REALOC_SIZE;

    }
    col->tab[col->t_log] = value;
    col->t_log++;
    return 1;
}


void delete_column(COLUMN **col) {
    if (col == NULL || *col == NULL) {
        return;
    }
    free((*col)->tab);
    free((*col)->titre);
    free(*col);
    *col = NULL;

}

void print_col(COLUMN *col) {
    if (col == NULL) {
        printf("The column is empty or uninitialized.\n");
        return;
    }

    printf("Column title: %s\n", col->titre);

    for (int i = 0; i < col->t_log; ++i) {
        printf("[%d] %d\n", i, col->tab[i]);
    }
}

int nbr_occurence_x(int x, COLUMN *col){
    int nbr_occur = 0;

    for (int i = 0; i < col->t_log; ++i){
        if (col->tab[i] == x){
            nbr_occur++;
        }

    }

    return nbr_occur;
}


int val_pos_x(COLUMN *col, int x){
    int val, i;
    for(i;i < col->t_log; i++){

        if (i == (x)){
            return col->tab[i];
        }
        if (x > col->t_log){
            return 0;
        }
    }
}

int nbr_val_sup(COLUMN *col, int x){
    int nbr_val;
    for(int i; i < col->t_log; i++){
        if (col->tab > x ){
            nbr_val++;
        }
    }
    return nbr_val;
}
