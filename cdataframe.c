#include "cdataframe.h"

int *create_cdf()
{
    CDF *cdf = malloc(sizeof(int*));
    cdf->t_phy = 0;
    cdf->t_log = 0;
    cdf->tab = NULL;
    return cdf;
}

int insert_cdf_col(CDF* cdf)
{
    char* titre;
    int val, nb;
    int* tmp;
    if (cdf->t_phy==0)
    {
        cdf->tab = malloc(REALOC_SIZE*sizeof(int));
        cdf->t_phy += REALOC_SIZE;
    }
    if (cdf->t_phy==cdf->t_log) {
        tmp = realloc(cdf->tab, REALOC_SIZE * sizeof(int));
        if (tmp == NULL)
            return 0;
        cdf->tab = tmp;
        cdf->t_phy += REALOC_SIZE;
    }
    printf("entrer le nom de la colonne\n");
    scanf("%s", titre);
    COLUMN *mycol = create_column(titre);
    printf("entrer le nombre de valeurs\n");
    scanf("%d", &val);
    printf("%d", val);
    /*for (int i=0; i<val; i++)
    {*/
        printf("entrer une valeur\n");
        scanf("%d", &nb);
        insert_value(mycol, nb);
    //}
    cdf->tab[cdf->t_log] = *mycol->tab;
    cdf->t_log++;
    return 1;
}