#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
 

int main()
{

float **A;
float *X, *Y;
int i,j,n,tid;
float t1,t2;
printf("entrer n\n");
scanf("%d",&n);
A=(float **) malloc ((n+1)*sizeof (float *));
X=(float *) malloc ((n+1)*sizeof (float));
Y=(float *) malloc ((n+1)*sizeof (float));
for (i=0;i<n;i++)
	A[i]=(float *) malloc ((n+1)*sizeof (float));
for (i=0;i<n;i++)
{
	//X[i]=rand();
	printf("entrer X[%d]\n",i);
	scanf("%f",&X[i]);
	Y[i]=0;
}
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	{
	A[i][j]=rand();
	printf("entrer A[%d][%d]\n",i,j);
	scanf("%f",&A[i][j]);
	}
}

//affichage

for (i=0;i<n;i++)
	printf("X[%d]=%f\n",i,X[i]);
for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	   printf("A[%d][%d]=%f\n",i,j,A[i][j]);
//calcul produit
omp_set_num_threads(2);
t1=omp_get_wtime();
#pragma omp parallel //private(i,j) 
{
tid=omp_get_thread_num();

	for (i=tid;i<n;i=i+2)
	{
		for (j=0;j<n;j++)
          	  Y[i]=Y[i]+A[i][j]*X[j];
		printf("thread %d exécute Y[%d]=%f\n", tid, i,Y[i]);		
	}

}
t2=omp_get_wtime();
//affichage résultat
printf("temps parallel=%f\n", t2-t1);
/*for (i=0;i<n;i++)
	printf("Y[%d]=%f\n",i,Y[i]);*/


return (0);

}
