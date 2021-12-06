#include <stdio.h>
#include <stdlib.h>
#include "processing.h"



int main()
{
//int N0;
//BmpImg img = readBmpImage( "A.bmp" );
Moments mom= lire_moments ("test_mom.txt");
//double ** mat = mat_TriAntDiagSup (img,20);
//double ** mat0 = lire_moments_legendre("test_mom.txt" ,&N0);

//double **a= coeff_legendre (8);
for (int i = 0 ; i<20 ; i++ ){
        for (int j =0;j<20-i ; j++){
            printf("%lf " ,mom.centres_norm[i][j]);
        }
        printf("\n");
}
//ecrire_mom_cent("test_mom.txt" , mat , 20);
//ecrire_mom_cent("test_mom.txt" , mat0 , 20);
/*
for (int i = 0 ; i<=8 ; i++ ){
        for (int j =0;j<=i ; j++){
            printf("%f " ,a[i][j]);
        }
        printf("\n");
}
*/
//printf("%d \n" ,N0);
//freeMatrice(&mat,20);
Free_moments(&mom);
//freeMatrice(&mat0,20);
//freeMatrice(&a,8);


    return 0;
}
