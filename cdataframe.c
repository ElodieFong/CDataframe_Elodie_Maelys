//
// Created by maely on 22/04/2024.
//
#include "cdataframe.h"

CDF *create_cdf()
{
    CDF *cdf = (CDF*)malloc(sizeof(COLUMN));
    cdf->t_phy = 0;
    cdf->t_log = 0;
    cdf->tab = NULL;
    return cdf;
}

int insert_cdf_col(CDF* cdf, COLUMN* col)
{
    int* tmp;
    if (cdf->t_phy==0)
    {
        cdf->tab = malloc(REALOC_SIZE*sizeof(COLUMN));
        cdf->t_phy += REALOC_SIZE;
    }
    if (cdf->t_phy==cdf->t_log) {
        tmp = realloc(cdf->tab, REALOC_SIZE * sizeof(COLUMN));
        if (tmp == NULL)
            return 0;
        cdf->tab = tmp;
        cdf->t_phy += REALOC_SIZE;
    }
    cdf->tab[cdf->t_log++] = *col;
    return 1;
}

void print_cdf(CDF* cdf)
{
    for (int i=0; i<cdf->t_log; i++)
        print_col(&cdf->tab[i]);
}

void print_cdf_lig(CDF* cdf, int lig1, int lig2)
{
    for (int i=0; i<cdf->t_log; i++)
    {

        printf("ligne %d: ", lig1+i);
        for (int j=lig1-1; j<lig2; j++)
        {
            COLUMN *col = &cdf->tab[j];
            printf("%d ", col->tab[i]);
        }
        printf("\n");
    }
}

void print_cdf_col(CDF* cdf, int col1, int col2)
{
    for (int i=col1-1; i<col2; i++)
    {
        printf("colonne %d: ", col1+i);
        COLUMN *col = &cdf->tab[i];
        for (int j=0; j<cdf->t_log; j++)
        {
            printf("%d ", col->tab[j]);
        }
        printf("\n");
    }
}

int add_cdf_lig(CDF* cdf, int lig)
{
    int val;
    for (int i=0; i<cdf->t_log; i++)
    {
        printf("entrer val:\n");
        scanf("%d",&val);
        COLUMN *col = &cdf->tab[i];
        col->tab[col->t_log++]=val;
    }
    return 1;
}

int del_cdf_lig(CDF* cdf, int lig)
{
    COLUMN *col = &cdf->tab[0];
    if (lig > col->t_log)
        return 0;
    if (lig==col->t_log)
    {
        for (int i=0; i<cdf->t_log; i++)
        {
            col = &cdf->tab[i];
            col->t_log--;
        }
    }
    else
    {

    }
    return 1;
}

int add_cdf_col(CDF* cdf, char* titre)
{
    int val;
    COLUMN *col = create_column(titre), *row;
    row = &cdf->tab[0];
    for (int i=0; i<row->t_log; i++)
    {
        printf("entrer val:\n");
        scanf("%d", &val);
        insert_value(col, val);
    }
    cdf->tab[cdf->t_log++] = *col;
    return 1;
}

int del_cdf_col(CDF* cdf, int col)
{
    if (col > cdf->t_log)
        return 0;
    if (col==cdf->t_log)
        cdf->t_log--;
    else
    {

    }
    return 1;
}

int rename_col(CDF* cdf, int col, char* titre)
{
    if (cdf==NULL)
        return 0;
    COLUMN *colo = &cdf->tab[col-1];
    colo->titre = titre;
    return 1;
}

int val_existe(CDF* cdf, int val)
{
    COLUMN *col;
    for (int i=0; i<cdf->t_log; i++)
    {
        col = &cdf->tab[i];
        if (nbr_occurence_x(val, col))
            return 1;
    }
    return 0;
}

int cellule(CDF* cdf, int lig, int col, int new_val)
{
    COLUMN *colonne = &cdf->tab[col-1];
    if (col>cdf->t_log || lig>colonne->t_log)
        return 0;
    colonne->tab[lig-1] = new_val;
    return 1;
}

int print_noms_col(CDF* cdf)
{
    if (cdf==NULL)
        return 0;
    COLUMN *col;
    printf("titres: ");
    for (int i=0; i<cdf->t_log; i++)
    {
        col = &cdf->tab[i];
        printf("%s ", col->titre);
    }
    return 1;
}

int nb_lig_cdf(CDF* cdf){
    if (cdf == NULL || cdf->t_log == 0) {
        return 0;
    }

    int max_rows = 0;
    for (int i = 0; i < cdf->t_log; i++) {
        COLUMN *col = &cdf->tab[i];
        if (col->t_log > max_rows) {
            max_rows = col->t_log;
        }
    }
    return max_rows;
}


int nb_col_cdf(CDF* cdf){
    if (cdf == NULL) {// Return 0 if the CDF is NULL
    }
    return cdf->t_log;
}

int cel_val_egal(CDF* cdf, int val){

}


int cel_val_sup(CDF* cdf, int val){

}


int cel_val_inf(CDF* cdf, int val){

}