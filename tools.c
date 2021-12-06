#include "tools.h"
#include "myBmpGris.h"
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

double** mat_img_rec (char * filename,int dim_x,int dim_y ){
int p,q,i,j,n;
double** mat_rec;
double** mom_leg;
mom_leg=lire_moments_legendre(filename,&n);
mat_rec= creer_mat(dim_x,dim_y);

for ( i = 0; i < dim_x; i++)
    {
    for ( j = 0; j < dim_y; j++)
        {
        for (p=0 ; p<n ; p++ )
            {
                for (q=0 ; q<p;q++)
                    {
                        mat_rec[i][j]= mom_leg[i][j]*P(i,p-q)*P(j,q); 
                    }
            }
        }
    }
    return mat_rec ;
}