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
//creation matrice anti diago pour moment centrées normé
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
