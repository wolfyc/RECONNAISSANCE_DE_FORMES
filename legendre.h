#ifndef LEGENDRE_H_INCLUDED
#define LEGENDRE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"
double coeff (int x, int i);
double ** coeff_legendre (int n);
double Dist_Euc (double ** mat1 , double **mat2 , int n ); // tested with moments calculated from same image 
double ** lire_moments(char * filename );
void ecrire_mom (char * filename ,double ** moments ,int n );
double ** Moments_Legendre (BmpImg img, int n );
double Moment_Leg (BmpImg img,int p,int q, int n );
double Norm_Const(int p, int q);
double P(double x,int n );

#endif // LEGENDRE_H_INCLUDED
