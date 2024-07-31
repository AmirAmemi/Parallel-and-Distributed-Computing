#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <math.h>
#include <time.h>

int main()
{
    long int S;
    long int i,n,m;
    double t1,t2;
    printf("n=");
    scanf("%ld",&n);
    printf("m=");
    scanf("%ld",&m);
    S=0;
    for(i=1;i<=n;i++)
        S=S+pow(i,2)-100*i;

    printf("Sequentiellement S=%ld\n",S);
omp_set_num_threads(m);
t1=omp_get_wtime();
    S=0;
    #pragma omp parallel for reduction ( +: S)
    for(i=1;i<=n;i++)
        S=S+pow(i,2)-100*i;
t2=omp_get_wtime();
    printf("temps para=%g\n",t2-t1);
     printf("calcul paralléle S=%ld\n",S);
    return 0;
}
