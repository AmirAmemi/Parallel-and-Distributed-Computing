#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{
    int i,p,n,j;
    printf("donner p et n\n");
    scanf("%d %d", &p,&n);
    omp_set_num_threads (2);
    #pragma omp parallel private (i,j)
    {
      int tid =omp_get_thread_num();
      int Nt=omp_get_num_threads();
      for(i=p*tid;i<n;i=i+p*Nt)
            for(j=i;j<i+p;j++)
            if(j<n) printf("i=%d, tid=%d\n",j, omp_get_thread_num());
    }
    // autre m�thode
    printf("question 2 autre m�thode\n");

#pragma omp parallel for schedule(static, p) private (i)
                for(i=0;i<n;i++)
            printf("i=%d, tid=%d\n",i, omp_get_thread_num());

    return 0;
}
