#include <stdio.h>

int main(){
    int a,b;

    printf("Donner la valeur a: ");
    scanf("%d",&a);

    printf("Donner la valeur b: ");
    scanf("%d",&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("la valeur de a est : %d \n", a);
    printf("la valeur de b est : %d \n", b);
    return 0;
}

