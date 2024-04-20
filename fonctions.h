//
// Created by maely on 19/04/2024.
//

#ifndef PROJETC_FONCTIONS_H
#define PROJETC_FONCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#define REALOC_SIZE 256

typedef struct {
    char* titre;
    int t_phy;
    int t_log;
    int* tab;
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);

void print_col(COLUMN *col);

int nbr_occurence_x(int x, COLUMN *col);
int val_pos_x(COLUMN *col, int x);
int nbr_val_sup(COLUMN *col, int x);


#endif //PROJETC_FONCTIONS_H
