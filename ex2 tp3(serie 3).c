#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int n,i,m;
    printf("n=");
    scanf ("%d",&n);
    printf("m=");
    scanf("%d",&m);
    omp_set_num_threads(m);
    #pragma omp parallel
    {
        int tid=omp_get_thread_num();
        int Nt=omp_get_num_threads();
        int is=(Nt-tid-1)*n/Nt;
        int ie=(Nt-tid)*n/Nt;
        printf("je suis %d ie=%d is=%d n-ie=%d n-is=%d\n", tid, ie,is, n-ie,n-is);
        for(i=n-ie;i<n-is;i++)
            printf("valeur de i=%d , son rang est :%d\n", i,tid);

    }

    return 0;
}
