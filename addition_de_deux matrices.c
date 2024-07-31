#include<stdio.h>
#define N 10
int main(){
int tab[N][N];
int tab1[N][N];
int tab2[N][N];
int a , b,i,j ;
    printf("Entrez la numbre de ligne du tab et tab1 entre 1 et %d : ",N);
    scanf("%d", &a);
    printf("Entrez la numbre du colune du tab et tab1 entre 1 et %d : ",N);
    scanf("%d", &b);

    printf("Entrez les elements du tableau tab : \n");
    for (i = 0; i < a; i++) {
            for(j=0;j<b;j++){
        scanf("%d", &tab[i][j]);
            }}
    printf("Entrez les elements du tableau tab1 : \n");
    for (i = 0; i < a; i++) {
            for(j=0;j<b;j++){
        printf("Entrez lelement %d : ",j+i+2);
        scanf("%d", &tab1[i][j]);
            }}
    printf("L'affichage de tab est  : \n");
    for (i = 0; i < a; i++) {
            for(j=0;j<b;j++){
        printf("%d",tab[i][j]);
            }}
            printf("L'affichage de tab1 est  : \n");
    for (i = 0; i < a; i++) {
            for(j=0;j<b;j++){
        printf("%d",tab1[i][j]);
            }}

    for (i = 0; i < a; i++) {
            for(j=0;j<b;j++){
        tab2[i][j]=tab[i][j]+tab1[i][j];
            }}

     printf("La matrice resultante est :\n");
    for (i = 0; i < a; i++) {
        for (j = 0; j < b; j++) {
            printf("%d ", tab2[i][j]);
}}}
