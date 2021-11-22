#include "processing.h"

double ** creer_mat (dim_x,dim_y){
double **mat = malloc(dim_x*sizeof(double*));
int i,j;
for (i=0;i<dim;i++){
    mat[i]=calloc(dim_y,sizeof(double));
}
}




double ** Vander_monde (int dim,int pow_max,double moy){

}
for (i=0;i<dim;i++){
    for (j=0;j<pow_max;j++){
        van_m[i][j]=pow(i-moy,j);
    }
}
return van_m;
}

double mom_geo (BmpImg img , int p , int q){
int x,y;
double res=0;
double ** vanx=Vander_monde(img.dimX,N,0);
double ** vany=Vander_monde(img.dimY,N,0);
for (x=0;x<img.dimX;x++){
        for (y=0;y<img.dimY;y++){
            if (getPixel( img, int x, int y )!=0){
                res+=vanx[x][p]*vany[y][q] ;
            }
        }

}
return res;

}
double mom_geo_centre (BmpImg img,int p, int q){
double omega = mom_geo(img,0,0);
double x_bar = mom_geo(img,1,0)/omega;
double y_bar = mom_geo(img,0,1)/omega;
int x,y;
double ** vanx_centre=Vander_monde(img.dimX,N,x_bar);
double ** vany_centre=Vander_monde(img.dimY,N,y_bar);
for (x=0;x<img.dimX;x++){
        for (y=0;y<img.dimY;y++){
            if (getPixel( img, int x, int y )!=0){
                res+=vanx_centre[x][p]*vany_centre[y][q]/pow(omega,(p+q+2)/2.) ; //point pour la conversion en float
            }
        }

}

double ** mat_TriAntDiagSup(BmpImg img ,N){
double **
}
double ** coeff_legendre (){
}

