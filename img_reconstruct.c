#include "img_reconstruct.h"

double pixel_rec (Moments mom ,double x_norm , double y_norm  ){
int p ,q;
double res=0.00;
 for (p=0 ; p< mom.n ; p++ ){
    for (q=0 ; q<mom.n-p ;q++){
        res += mom.leg[p][q]*P(x_norm,p)*P(y_norm,q);
    }
}
return res ;
}

double** img_rec (char * filename,int dim_x,int dim_y ){ //
int x,y;
double** mat;
Moments mom;
mom=lire_moments(filename);
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

