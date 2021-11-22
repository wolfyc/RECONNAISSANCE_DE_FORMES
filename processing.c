#include "processing.h"

double ** creer_mat (dim_x,dim_y){
double **mat = malloc(dim_x*sizeof(double*));
int i;
for (i=0;i<dim_x;i++){
    mat[i]=calloc(dim_y,sizeof(double));
}
return mat;
}
double ** creer_mat_diag (int dim){
double **mat = malloc(dim*sizeof(double*));
int i,j;
for (i=0;i<dim_x;i++){
    mat[i]=calloc(dim-i,sizeof(double));
}
return mat;
}




double ** Vander_monde (int dim,int pow_max,double moy){
double ** van_m=creer_mat (dim,pow_max);
int i , j;
for (i=0;i<dim;i++){
    for (j=0;j<pow_max;j++){
        van_m[i][j]=pow(i-moy,j);
    }
}
return van_m;
}

double mom_geo (BmpImg img , int p , int q, int n){
int x,y;
double res=0;
double ** vanx=Vander_monde(img.dimX,n,0);
double ** vany=Vander_monde(img.dimY,n,0);
for (x=0;x<img.dimX;x++){
        for (y=0;y<img.dimY;y++){
            if (getPixel( img, x, y )!=0){
                res+=vanx[x][p]*vany[y][q] ;
            }
        }

}
return res;

}
double mom_geo_centre (BmpImg img,int p, int q, int n){
double res;
double omega = mom_geo(img,0,0);
double x_bar = mom_geo(img,1,0)/omega;
double y_bar = mom_geo(img,0,1)/omega;
int x,y;
double ** vanx_centre=Vander_monde(img.dimX,n,x_bar);
double ** vany_centre=Vander_monde(img.dimY,n,y_bar);
for (x=0;x<img.dimX;x++){
        for (y=0;y<img.dimY;y++){
            if (getPixel( img, x, y )!=0){
                res+=vanx_centre[x][p]*vany_centre[y][q]/pow(omega,(p+q+2)/2.) ; //point pour la conversion en float
            }
        }
return res;
}

double ** mat_TriAntDiagSup(BmpImg img ,int n){
double ** mat_mom = creer_mat_diag (int n);
int p,q;
for ( p=0;p<n;p++){
    for (q=p;q<n;q++){
       matmom[p][q]=mom_geo_centre (img,p,q,n);
    }
}
return mat_mom;
}
double ** coeff_legendre (){
}

