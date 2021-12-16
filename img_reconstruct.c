#include "img_reconstruct.h"

/*double pixel_rec (Moments mom ,double x_norm , double y_norm  ){
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
*/

double** img_rec (char * filename,unsigned int dim_x,unsigned int  dim_y )  //
{
    unsigned int  x,y,p,q;
    double** mat;
    Moments mom;
    mom=lireMomentsTxt(filename);
    double ** co = matCoefficientLegendre(mom.n);
    mat= creer_mat(dim_x,dim_y);


    for ( x = 0; x < dim_x; x++)
    {

        for ( y = 0; y < dim_y; y++)
        {
            for (p=0 ; p<= mom.n ; p++ )
            {
                for (q=0 ; q<= mom.n-p ; q++)
                {
                    mat[x][y] += mom.leg[p][q]*P((2*(double)x/dim_x-1),p,co)*P((2*(double)y/dim_y-1),q,co);
                }
            }
        }
    }
    return mat ;
}
void bmp_rec (char* filemom, char* imgName,unsigned int dim_x, unsigned int dim_y)
{
    double ** mat=img_rec ( filemom,dim_x,dim_y );

    BmpImg img=createBmpImg("Result",dim_x,dim_y) ;


    unsigned int i,j;
    for ( i = 0 ; i<dim_x; i++)
    {
        for ( j =0 ; j<dim_y; j++)
        {
            if (mat[i][j]< 0 ){
                    mat[i][j]=0;
                    }
            else {
                if ((mat[i][j])>1 ) {
                    mat[i][j]=1;
                }
                }
             setPixel(img,(int)(255*mat[i][j]),i,j);

            }
    }
    writeBmpImage(imgName,&img);
    freeMatrice(&mat,dim_x);
    freeBmpImg(&img);
}

