#include <stdio.h>
#define N 8
void changer(int *a , int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
    }
int main() {
    int tab[N];
    int a, i;

    printf("Entrez la taille du tableau entre 1 et %d : ",N);
    scanf("%d", &a);
    printf("Entrez les elements du tableau : \n");
    for (i = 0; i < a; i++) {
        printf("Entrez lelement %d : ",i+1);
        scanf("%d", &tab[i]);
    }

    printf("Le tableau entree est : ");
    for (i = 0; i < a; i++) {
        printf("%d ", tab[i]);
    }
    for (i=0;i<=(a/2);i++){
            changer(&tab[i],&tab[a-i-1]);
    }
    printf("\nLe tableau permutee est : ");
    for (i = 0; i <a; i++) {
        printf("%d ", tab[i]);
    }
    return 0;
}
