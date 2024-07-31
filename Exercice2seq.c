#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include <time.h>
 

int main()
{

float **A;
float *X, *Y;
int i,j,n;
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
	X[i]=rand();
	/*printf("entrer X[%d]\n",i);
	scanf("%f",&X[i]);*/
	Y[i]=0;
}
for (i=0;i<n;i++)
{
	for (j=0;j<n;j++)
	{
		A[i][j]=rand();
	/*printf("entrer A[%d][%d]\n",i,j);
	scanf("%f",&A[i][j]);*/
	}
}

//affichage

/*for (i=0;i<n;i++)
	printf("X[%d]=%f\n",i,X[i]);
for (i=0;i<n;i++)
	for (j=0;j<n;j++)
	   printf("A[%d][%d]=%f\n",i,j,A[i][j]);*/
//calcul produit
t1=omp_get_wtime();
for (i=0;i<n;i++)
	for (j=0;j<n;j++)
          Y[i]=Y[i]+A[i][j]*X[j];
t2=omp_get_wtime();
//affichage résultat
printf("temps seueltiel=%f\n", t2-t1);
/*for (i=0;i<n;i++)
	printf("Y[%d]=%f\n",i,Y[i]);*/


return (0);

}
