#include "Vandermonde.h"

double ** Vander_monde (int dim,int pow_max,double moy)  // tested OK 2.0
{
    double ** van_m = creer_mat (dim,pow_max);
    int i, j;
    for (i=0; i<dim; i++)
    {
        for (j=0; j<pow_max; j++)
        {
            van_m[i][j] = pow(i-moy,j);
        }
    }
    return van_m;
}
