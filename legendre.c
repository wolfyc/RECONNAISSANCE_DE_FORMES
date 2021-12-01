#include "legendre.h"
double coeff (int x, int i)  // Tested OK 2.0
{
    if (x==0 && i==0)
    {
        return 1;
    }
    else
    {
        if (x==1 && i==0)
        {
            return 0 ;
        }
        else
        {
            if (x!=1 && i==0)
            {
                return ((-((double)x-1)/(double)x)*coeff(x-2,0));
            }
            else
            {
                if (i>= x-1)
                {
                    return (((2*((double)x-1)+1)/(double)x)* coeff(x-1,i-1));
                }
                else
                {
                    return (((2*((double)x-1)+1)/x)* coeff(x-1,i-1)+(-((double)x-1)/(double)x)*coeff(x-2,i));
                }
            }
        }
    }
}


double ** coeff_legendre (int n )  // Tested OK 2.0
{
    double ** a= creer_mat_diago(n+1);
    int x,i;
    for (x=0; x<=n; x++ )
    {
        for (i=0; i<=x; i++)
        {
            a[x][i]=coeff(x,i);
            printf("%f \t", a[x][i]);
        }
        printf("\n");
    }
    return a;
}

double P(double x,int n )  // OK OK 2.0
{
    int i ;
    double poly =0.00;
    double ** a= coeff_legendre ( n );
    printf("ok all ");
    for (i=0; i<=n; i++)
    {
        poly+= a[n][i]*pow(x,i);
        printf("%f \n", poly);
    }
    return poly;
}
double Norm_Const(int p, int q)
{
    double C;
    C=(2*p + 1)*(2*q + 1)/(4.);

    return C;
}
