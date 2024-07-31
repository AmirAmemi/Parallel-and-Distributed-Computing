#include <stdio.h>

int main() {
    int a, b, c;

    printf("Entrez la valeur de A : ");
    scanf("%d", &a);

    printf("Entrez la valeur de B : ");
    scanf("%d", &b);

    c = a;
    a = b;
    b = c;

    printf("la valeur de A est : %d\n", a);
    printf("la valeur de B est : %d\n", b);

}


