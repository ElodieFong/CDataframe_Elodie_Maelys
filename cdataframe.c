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
    cdf->tab[cdf->t_log] = *col;
    cdf->t_log++;
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

int add_cdf_col(CDF* cdf)
{

}