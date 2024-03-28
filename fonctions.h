//
// Created by elodi on 28/03/2024.
//

#ifndef CDATAFRAME_FONCTIONS_H
#define CDATAFRAME_FONCTIONS_H

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

#endif //CDATAFRAME_FONCTIONS_H
