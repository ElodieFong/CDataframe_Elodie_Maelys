#ifndef CDATAFRAME_CDFRAME_H
#define CDATAFRAME_CDFRAME_H

#include "column.h"

int *create_cdf();
int insert_cdf_col(int nb_col);

void print_cdf(int* cdf);
void print_cdf_lig(int* cdf, int lig1, int lig2);
void print_cdf_col(int* cdf, int col1, int col2);

int add_cdf_lig(int* cdf, int lig);
int del_cdf_lig(int* cdf, int lig);
int add_cdf_col(int* cdf, int col);
int del_cdf_col(int* cdf, int col);
int rename_col(int* cdf, int col);
int val_existe(int* cdf, int val);
int cellule(int* cdf, int lig, int col);
int print_nom_col(int* cdf);

int nb_lig_cdf(int* cdf);
int nb_col_cdf(int* cdf);
int cel_val_egal(int* cdf, int val);
int cel_val_sup(int* cdf, int val);
int cel_val_inf(int* cdf, int val);

#endif //CDATAFRAME_CDFRAME_H
