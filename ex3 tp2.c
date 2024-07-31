#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
int main()
{
   float *x, min=10000;
int i,n;
double t1,t2;
scanf("%d",&n);
x=(float *)malloc(n*sizeof(float *));
for (i=0;i<n;i++)
    {x[i]=rand(); //printf("x[%d]=%f\n",i,x[i]);
    }
   t1=omp_get_wtime();

    for(i=1;i<n;i++)
        if (min>x[i]) min=x[i];
        t2=omp_get_wtime();
        printf("min=%f \n",min);
        printf("t_seq=%f \n",t2-t1,t1, t2);
 return 0;
}
