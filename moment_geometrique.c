#include "moment_geometrique.h"

double mom_geo (BmpImg img, int p, int q, int n)    // Tested 2.0
{
    int x,y;
    double res=0;
    double ** vanx=Vander_monde(img.dimX,n,0);
    double ** vany=Vander_monde(img.dimY,n,0);
    for (x=0; x<img.dimX; x++)
    {
        for (y=0; y<img.dimY; y++)
        {
            if (getPixel( img, x, y )!=0)
            {
                res+=vanx[x][p]*vany[y][q] ;
            }
        }

    }
    return res;

}
double mom_geo_centre (BmpImg img,int p, int q, int n)  // Tested Ok 2.0
{
    double res=0.00; // correction res have not been initialized
    double omega = mom_geo(img,0,0,n);
    double x_bar = mom_geo(img,1,0,n)/omega;
    double y_bar = mom_geo(img,0,1,n)/omega;
    int x,y;
    double ** vanx_centre=Vander_monde(img.dimX,n,x_bar);
    double ** vany_centre=Vander_monde(img.dimY,n,y_bar);
    for (x=0; x<img.dimX; x++)
    {
        for (y=0; y<img.dimY; y++)
        {
            if (getPixel( img, x, y )!=0)
            {
                res+=vanx_centre[x][p]*vany_centre[y][q]/pow(omega,(p+q+2)/2.) ; //point pour la conversion en float
            }
        }
    }
    return res;
}
double ** mat_TriAntDiagSup(BmpImg img,int n)   //Tested Ok 2.0
{
    double ** mat_mom = creer_mat_anti_diag (n);
    int p,q;
    for ( p=0; p<n; p++)
    {
        for (q=0; q<n-p; q++)
        {
            mat_mom[p][q]=mom_geo_centre (img,p,q,n);
        }
    }
    return mat_mom;
}
