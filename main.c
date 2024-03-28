#include "fonctions.h"

int main() {
    COLUMN *mycol = create_column("My column");
    printf("titre=%s, t_phy=%d, t_log=%d", mycol->titre, mycol->t_phy, mycol->t_log);
    int val = 5;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
        printf("%d", mycol->tab[0]);
    return 0;
}
