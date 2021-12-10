#include "tools.h"
//creation de matrice rectangulaire.

double ** creer_mat (unsigned int dim_x, unsigned int dim_y)  //tested OK 2.0
{
    double **mat = malloc(dim_x*sizeof(double*));
    unsigned int i;
    for (i=0; i<dim_x; i++)
    {
        mat[i]=calloc(dim_y,sizeof(double));
    }
    return mat;
}
double ** Vander_monde (unsigned int dim,unsigned int pow_max,double moy)  // tested OK 2.0
{
    double ** van_m = creer_mat (dim,pow_max);
    unsigned int i, j;
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
double ** creer_mat_anti_diag (unsigned int dim) // tested OK 2.0
{
    double **mat = malloc(dim*sizeof(double*));
    unsigned int i;
    for (i=0; i<dim; i++)
    {
        mat[i]=calloc(dim-i,sizeof(double));
    }
    return mat;
}

double ** creer_mat_diago (unsigned int dim) // tested OK 2.0
{
    double **mat = malloc(dim*sizeof(double*));
    unsigned int i;
    for ( i=0; i<dim; i++)
    {
        mat[i]=calloc(i+1,sizeof(double));
    }
    return mat;

}


void freeMatrice(double ***mat,unsigned int dim_x)   //Corrected 2.0
{
    unsigned int i;
    for ( i = 0; i< dim_x; i++)
    {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
    if ((*mat)==NULL) printf( "Functions succesfully Freed \n");
}





Moments creer_moments(unsigned int n ){
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

Moments get_mom(BmpImg img,unsigned int  n)
{
    Moments mom = creer_moments(n) ;
    printf("debut \n");
    mom.centres_norm=mat_moments_centre_norme(img,n);
    printf("fin centre norme \n");
    mom.leg = Moments_Legendre(img,n,mom.centres_norm);
     printf("fin legendre \n");
    return mom;
}

double Dist_Euc (double ** mat1 , double **mat2 , unsigned int  n ) {  // tested with moments calculated from same image
                                                             //except that one of them is saved and red (in/from) a file
unsigned int  p,q;                                                     // Result was 0.000004 Due to the use of the tmp variable
double res = 0.00 ;                                          // in the function <lire_moments>
    for (p=0 ; p<n ; p++ ){
        for (q=0 ; q<n-p;q++){
            res+= pow(mat1[p][q]-mat2[p][q],2);
        }
    }
res = sqrt (res);

return res;
}

