//
// Created by maely on 22/04/2024.
//
#include "cdataframe.h"

// crée et retourne un cdataframe vide
CDF *create_cdf()
{
    CDF *cdf = (CDF*)malloc(sizeof(COLUMN));
    cdf->t_phy = 0;
    cdf->t_log = 0;
    cdf->tab = NULL;
    return cdf;
}

// insert une colonne col dans un cdataframe cdf, si l’insertion s’est bien effectuée, la fonction retourne 1, 0 sinon
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
        if (tmp == NULL) // retourne 0 s'il n'y a pas assez de place
            return 0;
        cdf->tab = tmp;
        cdf->t_phy += REALOC_SIZE;
    }
    cdf->tab[cdf->t_log++] = *col; // ajoute la colonne et augmente la taille logique
    return 1;
}

// affiche le cdataframe cdf en entier sans return grâce aux print les valeurs de chaque colonne
void print_cdf(CDF* cdf)
{
    for (int i=0; i<cdf->t_log; i++)
        print_col(&cdf->tab[i]);
}

// affiche le cdataframe cdf de la ligne lig1 à la ligne lig2
void print_cdf_lig(CDF* cdf, int lig1, int lig2)
{
    COLUMN *col = &cdf->tab[0];
    if (lig2>col->t_log)
    {
        printf("il n'est pas possible d'afficher ces lignes\n");
        return;
    }
    if (lig1==lig2)
    {
        COLUMN *col = &cdf->tab[lig1-1];
        printf("ligne %d: ", lig1);
        for (int i=0; i<cdf->t_log; i++)
            printf("%d ", col->tab[i]);
    }
    else
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
}

// affiche le cdataframe cdf de la colonne col1 à la colonne col2
void print_cdf_col(CDF* cdf, int col1, int col2)
{
    if (col2>cdf->t_log)
    {
        printf("il n'est pas possible d'afficher ces colonnes\n");
        return;
    }

    for (int i=col1-1; i<col2; i++)
    {
        COLUMN *col = &cdf->tab[i];
        print_col(col);
    }
}

// ajoute une ligne au cdataframe cdf
int add_cdf_lig(CDF* cdf)
{
    int val;
    for (int i=0; i<cdf->t_log; i++)
    {
        printf("entrer val:\n");
        scanf("%d",&val);
        insert_value(&cdf->tab[i], val);
    }
    return 1;
}

// supprime la ligne lig du cdataframe cdf, renvoie 1 si c'est possible, 0 sinon
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
        for (int i=0; i<cdf->t_log; i++)
        {
            col = &cdf->tab[i];
            for (int j=lig; j<col->t_log; j++)
                col->tab[j-1]=col->tab[j]; // décalage des valeurs pour ne pas avoir de trou dans la colonne
            col->t_log--;
        }
    }
    return 1;
}

// ajoute une colonne au cdataframe cdf
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
    insert_cdf_col(cdf, col);
    return 1;
}

// supprime la colonne col du cdataframe cdf, renvoie 1 si c'est possible, 0 sinon
int del_cdf_col(CDF* cdf, int col)
{
    if (col > cdf->t_log)
        return 0;
    if (col==cdf->t_log)
        cdf->t_log--;
    else
    {
        for (int i=col; i<cdf->t_log; i++)
            cdf->tab[i-1]=cdf->tab[i]; // décalage des valeurs pour ne pas avoir un trou dans le cdf
        cdf->t_log--;
    }
    return 1;
}

// remplace le titre de la colonne col, renvoie 1 si c'est possible, 0 sinon
int rename_col(CDF* cdf, int col, char* titre)
{
    if (cdf==NULL)
        return 0;
    COLUMN *colo = &cdf->tab[col-1];
    colo->titre = titre;
    return 1;
}

// cherche si la valeur val existe dans le cdataframe cdf, renvoie 1 si elle existe, 0 sinon
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

// remplace la valeur de la cellule du cdataframe cdf à la ligne lig et colonne col par une nouvelle valeur new_val, renvoie 1 si c'est possible, 0 sinon
int cellule(CDF* cdf, int lig, int col, int new_val)
{
    COLUMN *colonne = &cdf->tab[col-1];
    if (col>cdf->t_log || lig>colonne->t_log)
        return 0;
    colonne->tab[lig-1] = new_val;
    return 1;
}

// affiche les titres des colonnes du cdataframe cdf, renvoie 1 si c'est possible, 0 sinon
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

// donne le nombre de lignes max_rows dans un cdataframe cdf
int nb_lig_cdf(CDF* cdf){
    if (cdf == NULL || cdf->t_log == 0) {
        return 0;
    }
    COLUMN *col = &cdf->tab[0];
    int max_rows = col->t_log;
    return max_rows;
}


// renvoie le nombre de colonnes dans un cdataframe cdf
int nb_col_cdf(CDF* cdf){
    if (cdf == NULL) {// returne 0 si le cdf est NULL
    }
    return cdf->t_log;
}

// retourne le nombre de cellule possédant la valeur val
int cel_val_egal(CDF* cdf, int val){
    int egal = 0;
    for (int i = 0; i < cdf->t_log; i++) {
        printf(""); // ne marche pas sans le print
        egal += nbr_val_equ(&cdf->tab[i], val);
    }
    return egal;

}

// retourne le nombre de cellule possédant une valeur suppérieur à la valeur val
int cel_val_sup(CDF* cdf, int val){
    int supp = 0;
    for(int i=0; i<cdf->t_log; i++){
        printf(""); // ne marche pas sans le print
        supp += nbr_val_sup(&cdf->tab[i], val);
    }
    return supp;
}

// retourne le nombre de cellule possédant une valeur inférieur à la valeur val
int cel_val_inf(CDF* cdf, int val){
    int inf = 0;
    for(int i=0; i<cdf->t_log; i++){
        printf(""); // ne marche pas sans le print
        inf += nbr_val_inf(&cdf->tab[i], val);
    }
    return inf;
}
