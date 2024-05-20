#include "column.h"

// crée et retourne une colonne col vide
COLUMN *create_column(char* title)
{
    COLUMN *col = (COLUMN*)malloc(sizeof(COLUMN));
    col->titre = title;
    col->t_phy = 0;
    col->t_log = 0;
    col->tab = NULL;
    return col;
}

// insert une valeur value dans la colonne col, , si l’insertion s’est bien effectuée, la fonction retourne 1, 0 sinon
int insert_value(COLUMN* col, int value)
{
    int* tmp;
    if (col->t_phy==0)
    {
        col->tab = malloc(REALOC_SIZE*sizeof(int));
        col->t_phy += REALOC_SIZE;
    }
    if (col->t_phy==col->t_log)
    {
        tmp = realloc(col->tab, REALOC_SIZE*sizeof(int));
        if (tmp==NULL) // retourne 0 s'il n'y a pas assez de place
            return 0;
        col->tab = tmp;
        col->t_phy += REALOC_SIZE;

    }
    col->tab[col->t_log] = value;
    col->t_log++;
    return 1;
}

// suppression de la colonne col
void delete_column(COLUMN **col) {
    if (col == NULL || *col == NULL) {
        return;
    }
    free((*col)->tab);
    free((*col)->titre);
    free(*col);
    *col = NULL;

}

// affiche le titre et les valeurs contenues dans la colonne col
void print_col(COLUMN *col) {
    if (col == NULL) {
        printf("La colonne est vide\n");
        return;
    }

    printf("Titre: %s\n", col->titre);

    for (int i = 0; i < col->t_log; i++) {
        printf("[%d] %d\n", i, col->tab[i]);
    }
}

// renvoie le nombre d'occurrence nbr_occur d'une valeur x dans la colonne col
int nbr_occurence_x(int x, COLUMN *col){
    int nbr_occur = 0;

    for (int i = 0; i < col->t_log; i++){
        if (col->tab[i] == x){
            nbr_occur++;
        }
    }
    return nbr_occur;
}

// retourne la valeur présente à la position x dans la colonne col
int val_pos_x(COLUMN *col, int x){
    int val, i;
    for(i;i < col->t_log; i++){

        if (i == (x)){
            return col->tab[i];
        }
        if (x > col->t_log){
            return 0;
        }
    }
}

// renvoie le nombre de valeur supérieure à la valeur x dans la colonne col
int nbr_val_sup(COLUMN *col, int x){
    int nbr_val=0;
    for(int i; i < col->t_log; i++){
        if (col->tab[i] > x ){
            nbr_val++;
        }
    }
    return nbr_val;
}

// renvoie le nombre de valeur inférieure à la valeur x dans la colonne col
int nbr_val_inf(COLUMN *col, int x){
    int nbr_val=0;
    for(int i; i < col->t_log; i++){
        if (col->tab[i] < x ){
            nbr_val++;
        }
    }
    return nbr_val;
}

// renvoie le nombre de valeur égale à la valeur x dans la colonne col
int nbr_val_equ(COLUMN *col, int x){
    int nbr_val=0;
    for(int i; i < col->t_log; i++){
        if (col->tab[i] == x ){
            nbr_val++;
        }
    }
    return nbr_val;
}