#include "img_reconstruct.h"

double pixel_rec (Moments mom ,double x_norm , double y_norm  ){
unsigned int p ,q;
double res=0.00;
double ** co = matCoefficientLegendre(mom.n);
 for (p=0 ; p< mom.n ; p++ ){
    for (q=0 ; q<mom.n-p ;q++){

        res += mom.leg[p][q]*P(x_norm,p,co)*P(y_norm,q,co);

    }
}
return res ;
}

double** img_rec (char * filename,unsigned int dim_x,unsigned int  dim_y ){ //
unsigned int  x,y;
double** mat;
Moments mom;
mom=lire_moments(filename);

mat= creer_mat(dim_x,dim_y);

for ( x = 0; x < dim_x; x++)
    {

    for ( y = 0; y < dim_y; y++){

        mat[x][y]= pixel_rec (mom,(2*(double)x/dim_x-1), (2*(double)y/dim_y-1));


    }


    }
    return mat ;
}
void bmp_rec (char* filemom , char* imgName,unsigned int dim_x , unsigned int dim_y , double threshold){
double ** mat=img_rec ( filemom,dim_x,dim_y );
printf("mat created\n");
BmpImg img = createBmpImg("bmpImg",dim_x,dim_y);
unsigned int i,j;
 for ( i = 0 ; i<32;i++){
        for ( j =0 ; j<32;j++){
            if (mat[i][j]>=threshold)
                setPixel(img,255,i,j);
            else
                setPixel(img,0,i,j);
        }
    }
writeBmpImage(imgName,&img);
freeMatrice(&mat,dim_x);
freeBmpImg(&img);
}

