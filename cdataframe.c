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

int add_cdf_lig(CDF* cdf)
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

int del_cdf_col(CDF* cdf, int col)
{
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

int print_noms_col(CDF* cdf)
{
    if (cdf==NULL)
        return 0;
    COLUMN *col;
    for (int i=0; i<cdf->t_log; i++)
    {
        col = &cdf->tab[i];
        printf("%s ", col->titre);
    }
    return 1;
}