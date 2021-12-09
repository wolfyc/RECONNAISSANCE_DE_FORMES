#include "tools.h"
//creation de matrice rectangulaire.

double ** creer_mat (int dim_x, int dim_y)  //tested OK 2.0
{
    double **mat = malloc(dim_x*sizeof(double*));
    int i;
    for (i=0; i<dim_x; i++)
    {
        mat[i]=calloc(dim_y,sizeof(double));
    }
    return mat;
}
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
//creation matrice anti diago pour moment centr�es norm�
double ** creer_mat_anti_diag (int dim) // tested OK 2.0
{
    double **mat = malloc(dim*sizeof(double*));
    int i;
    for (i=0; i<dim; i++)
    {
        mat[i]=calloc(dim-i,sizeof(double));
    }
    return mat;
}

double ** creer_mat_diago (int dim) // tested OK 2.0
{
    double **mat = malloc(dim*sizeof(double*));
    int i;
    for ( i=0; i<dim; i++)
    {
        mat[i]=calloc(i+1,sizeof(double));
    }
    return mat;

}


void freeMatrice(double ***mat, int dim_x)   //Corrected 2.0
{
    int i;
    for ( i = 0; i< dim_x; i++)
    {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
    if ((*mat)==NULL) printf( "Functions succesfully Freed \n");
}





Moments creer_moments(int n ){
    Moments mom ;
    mom.n = n ;
    mom.centres_norm= creer_mat_anti_diag(n) ;
    mom.leg= creer_mat_anti_diag(n) ;
    return mom ;
}
void Free_moments (Moments *mom ){

    freeMatrice (&(mom->centres_norm),mom->n);
    freeMatrice(&(mom->leg),mom->n);
    mom->n=0 ;
}

Moments get_mom(BmpImg img,int n)
{
    Moments mom = creer_moments(n) ;
    mom.centres_norm=mat_moments_centre_norme(img,n);
    mom.leg = Moments_Legendre(img,n);

    return mom;
}

double Dist_Euc (double ** mat1 , double **mat2 , int n ) {  // tested with moments calculated from same image
                                                             //except that one of them is saved and red (in/from) a file
int p,q;                                                     // Result was 0.000004 Due to the use of the tmp variable
double res = 0.00 ;                                          // in the function <lire_moments>
    for (p=0 ; p<n ; p++ ){
        for (q=0 ; q<n-p;q++){
            res+= pow(mat1[p][q]-mat2[p][q],2);
        }
    }
res = sqrt (res);

return res;
}

