#ifndef CDATAFRAME_CDFRAME_H
#define CDATAFRAME_CDFRAME_H

#include "column.h"

typedef struct {
    int t_phy;
    int t_log;
    COLUMN *tab;
}CDF;

CDF *create_cdf();
int insert_cdf_col(CDF* cdf, COLUMN* col);

void print_cdf(CDF* cdf);
void print_cdf_lig(CDF* cdf, int lig1, int lig2);
void print_cdf_col(CDF* cdf, int col1, int col2);

int add_cdf_lig(CDF* cdf);
int del_cdf_lig(CDF* cdf, int lig);
int del_cdf_col(CDF* cdf, int col);
int rename_col(CDF* cdf, int col, char* titre);
int val_existe(CDF* cdf, int val);
int cellule(CDF* cdf, int lig, int col);
int print_noms_col(CDF* cdf);

int nb_lig_cdf(CDF* cdf);
int nb_col_cdf(CDF* cdf);
int cel_val_egal(CDF* cdf, int val);
int cel_val_sup(CDF* cdf, int val);
int cel_val_inf(CDF* cdf, int val);

#endif //CDATAFRAME_CDFRAME_H
