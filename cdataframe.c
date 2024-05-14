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
    char* titre;
    int val, nb;
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
    cdf->tab[cdf->t_log] = *col;
    cdf->t_log++;
    return 1;
}

void print_cdf(CDF* cdf)
{
    for (int i=0; i<cdf->t_log; i++)
        print_col(&cdf->tab[i]);
}