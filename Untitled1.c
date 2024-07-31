#include <stdio.h>

int main() {
    int a, b, c;

    printf("Donner la valeur a: ");
    scanf("%d", &a);

    printf("Donner la valeur b: ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("la valeur de a est : %d\n", a);
    printf("la valeur de b est : %d\n", b);

}
