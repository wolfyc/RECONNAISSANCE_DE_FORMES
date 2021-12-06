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

double pixel_rec (Moments mom ,double x_norm , double y_norm  ){
int p ,q;
double res=0.00;
 for (p=0 ; p< mom.n ; p++ )
{
    for (q=0 ; q<mom.n-p ;q++)
{
        res += mom.leg[p][q]*P(x_norm,p)*P(y_norm,q);


}


}
return res ;
}

double** img_rec (char * filename,int dim_x,int dim_y ){ //
int x,y;
double** mat;
Moments mom=lire_moments(filename);
afficher_moments(mom);
mat= creer_mat(dim_x,dim_y);

for ( x = 0; x < dim_x; x++)
    {
    for ( y = 0; y < dim_y; y++){

        mat[x][y]= pixel_rec (mom,((double)x/dim_x), ((double)y/dim_y));

       
    }
       
    }
    return mat ;
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
    mom.leg=Moments_Legendre(img,n);

    return mom;
}

