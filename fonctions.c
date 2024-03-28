//
// Created by elodi on 28/03/2024.
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
    if (col->t_phy==0)
    {
        col->tab = malloc(REALOC_SIZE*sizeof(int));
        col->t_phy += REALOC_SIZE;
    }
    if (col->t_phy==col->t_log)
    {
        col->tab = realloc(col->tab, REALOC_SIZE*sizeof(int));
        col->t_phy += REALOC_SIZE;
        return 0;
    }
    col->tab[col->t_log] = value;
    col->t_log++;
    return 1;
}