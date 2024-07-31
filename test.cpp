#include <iostream>
#include <omp.h>
#include <ctime>
 
 
using namespace std;
 
void simple(int n, double *a, double *b)
{
    int i;
    #pragma omp parallel for
    for(int j = 0; j < 3300; j++) {
        for (i=1; i<n; i++)
            b[i] = (a[i] - a[i-1]) / 2.0;
    }
}
 
int main()
{
    cout << "Hello world!" << endl;
    int n = 1000000;
    double *a, *b;
    time_t tbegin,tend, texec;
 
    tbegin=time(NULL);
    a = new double[n];
    b = new double[n];
 
    #pragma omp parallel for
    for (int i=0; i<n; i++) {
        a[i] = i * 10.0;
        b[i] = 0.0;
    }
 
    for (int i=n-10; i<n; i++)
        cout << b[i] << endl;
    cout << endl;
 
    simple(n, a, b);
 
    for (int i=n-10; i<n; i++)
    cout << b[i] << endl;
    cout << endl;
    tend=time(NULL);
    texec=difftime(tend,tbegin);
 
    std::cout << "Execution time : " << texec ;
    cout << " The end "<< endl;
    return 0;
}
