#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int matrice1[MAX_SIZE][MAX_SIZE], matrice2[MAX_SIZE][MAX_SIZE], resultat[MAX_SIZE][MAX_SIZE];
    int lignes, colonnes, i, j;

    // Demander à l'utilisateur d'entrer la taille de la matrice
    printf("Entrez le nombre de lignes de la matrice : ");
    scanf("%d", &lignes);
    printf("Entrez le nombre de colonnes de la matrice : ");
    scanf("%d", &colonnes);

    // Demander à l'utilisateur d'entrer les éléments de la première matrice
    printf("Entrez les elements de la premiere matrice : ");
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            scanf("%d", &matrice1[i][j]);
        }
    }

    // Demander à l'utilisateur d'entrer les éléments de la deuxième matrice
    printf("Entrez les elements de la deuxieme matrice : ");
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            scanf("%d", &matrice2[i][j]);
        }
    }

    // Additionner les deux matrices
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            resultat[i][j] = matrice1[i][j] + matrice2[i][j];
        }
    }

    // Afficher la matrice résultante
    printf("La matrice resultante est :\n");
    for (i = 0; i < lignes; i++) {
        for (j = 0; j < colonnes; j++) {
            printf("%d ", resultat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
