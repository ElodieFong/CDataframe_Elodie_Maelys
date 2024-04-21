//
// Created by elodi on 21/04/2024.
//

#ifndef CDATAFRAME_CDFRAME_H
#define CDATAFRAME_CDFRAME_H

#include "column.h"

int *create_cdf();
int insert_cdf_col(int nb_col);
void print_cdf(int* cdf);
void print_cdf_lig(int* cdf);
void print_cdf_col(int* cdf);
int add_cdf_lig(int* cdf);
int del_cdf_lig(int* cdf);
int add_cdf_col(int* cdf);
int del_cdf_col(int* cdf);
int rename_col(int* cdf);
int val_existe(int* cdf);
int cellule(int* cdf);
int print_nom_col(int* cdf);

#endif //CDATAFRAME_CDFRAME_H
