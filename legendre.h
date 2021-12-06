#ifndef LEGENDRE_H_INCLUDED
#define LEGENDRE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"
// calculateur du coef de legendre
/**
  * @param x la valeur du coeff_legendre et sa position de ligne
  * @param i l'ordre et la position dans la colonne de la matrice
  * @return le coeff de legendre
  */
double coeff (int x, int i);

// calculateur du coef de legendre
/**
  * @param n la dimension de la matrice de legendre
  * @return lune matrice de coeff de legendre
  */
double ** coeff_legendre (int n);

// calculateur distance euclidienne
/**
  * @param mat1 la valeur du coeff_legendre et sa position de ligne
  * @param i l'ordre et la position dans la colonne de la matrice
  * @return le coeff de legendre
  */
double Dist_Euc (double ** mat1 , double **mat2 , int n ); // tested with moments calculated from same image 

// lecture  des moment de legendre d'un fichier
/**
  * @param filename string of char
  * @return matrice de moment de legendre
  */
double ** lire_moments(char * filename );
void ecrire_mom (char * filename ,double ** moments ,int n );
double ** Moments_Legendre (BmpImg img, int n );
double Moment_Leg (BmpImg img,int p,int q, int n );
double Norm_Const(int p, int q);
double P(double x,int n );

#endif // LEGENDRE_H_INCLUDED
