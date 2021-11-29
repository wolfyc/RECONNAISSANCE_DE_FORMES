#include "processing.h"
//creation de matrice rectangulaire.
double ** creer_mat (int dim_x, int dim_y){ //tested OK 2.0
    double **mat = malloc(dim_x*sizeof(double*));
    int i;
    for (i=0;i<dim_x;i++){
        mat[i]=calloc(dim_y,sizeof(double));
    }
    return mat;
}
//creation matrice anti diago pour moment centrées normé
double ** creer_mat_anti_diag (int dim){// tested OK 2.0
    double **mat = malloc(dim*sizeof(double*));
    int i;
    for (i=0;i<dim;i++){
        mat[i]=calloc(dim-i,sizeof(double));
    }
    return mat;
}

double ** creer_mat_diago (int dim){// tested OK 2.0
    double **mat = malloc(dim*sizeof(double*));
    int i;
    for (i=0;i<dim;i++){
        mat[i]=calloc(i+1,sizeof(double));
    }
    return mat;

}


void freeMatrice(double ***mat, int dim_x){  //Corrected
    for (int i = 0; i< dim_x;i++){
        free((*mat)[i]);
        printf( "%d\n", i );
    }
    free(*mat);
    printf( "free( mat)\n");
    *mat = NULL;
    printf( "mat == null\n");
}




double ** Vander_monde (int dim,int pow_max,double moy){ // tested OK
double ** van_m=creer_mat (dim,pow_max);
int i , j;
for (i=0;i<dim;i++){
    for (j=0;j<pow_max;j++){
        van_m[i][j]=pow(i-moy,j);
    }
}
return van_m;
}

double mom_geo (BmpImg img , int p , int q, int n){ // Tested
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
double mom_geo_centre (BmpImg img,int p, int q, int n){ // Tested Ok
double res=0.00; // correction res have not been initialized
double omega = mom_geo(img,0,0,n);
double x_bar = mom_geo(img,1,0,n)/omega;
double y_bar = mom_geo(img,0,1,n)/omega;
int x,y;
double ** vanx_centre=Vander_monde(img.dimX,n,x_bar);
double ** vany_centre=Vander_monde(img.dimY,n,y_bar);
for (x=0;x<img.dimX;x++){
        for (y=0;y<img.dimY;y++){
            if (getPixel( img, x, y )!=0){
                res+=vanx_centre[x][p]*vany_centre[y][q]/pow(omega,(p+q+2)/2.) ; //point pour la conversion en float
            }
        }
}
return res;}
double ** mat_TriAntDiagSup(BmpImg img ,int n){ //Tested Ok
double ** mat_mom = creer_mat_anti_diag (n);
int p,q;
for ( p=0;p<n;p++){
    for (q=0;q<n-p;q++){
       mat_mom[p][q]=mom_geo_centre (img,p,q,n);
    }
}
return mat_mom;
}
double ** coeff_legendre (int n ){
double ** a= creer_mat_diago(n);
int x,i;
a[0][0]=1;
a[1][0]=0;
for (x=1;x<=n;x++ ){
    if(x>1){
        a[x][0] = ((-x+1)/x)*a[x-2][0]; //generation de la premiere colonne.
    }
    for (i=1;i<=x;i++){
        if (i >= x-1){
            a[x][i] = ((2*(x-1)+1)/x)* a[x-1][i-1]; //i >= x-1;
        }
        else{
                a[x][i] = (((2*(x-1)+1)/x)* a[x-1][i-1])+((-x+1)/x)*a[x-2][i];//sinon
            }

        }
    }
    return a;
}



