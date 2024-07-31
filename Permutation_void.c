#include <stdio.h>

void changer(int *a , int *b){
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}
int main(){
    int a,b;

    printf("Donner la valeur a: ");
    scanf("%d",&a);
    printf("Donner la valeur b: ");
    scanf("%d",&b);

    changer(&a,&b);
    printf("la valeur de a est : %d \n", a);
    printf("la valeur de b est : %d \n", b);
    return 0;
}
