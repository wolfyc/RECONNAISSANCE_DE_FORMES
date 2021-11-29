#ifndef _processing_h_
#define _processing_h_

#define N 46
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "myBmpGris.h"

// Matrice de Vandermonde
/**
  * @param dim dimxdim la dim de la mat
  * @param pow_max l'ordre max de la mat
  * @return une matrice de dimension dim
  */
double ** Vander_monde (int dim,int pow_max,double moy);

double mom_geo (BmpImg img, int p, int q, int n );

double mom_geo_centre (BmpImg img,int p, int q, int n);

double ** mat_TriAntDiagSup(BmpImg img,int n);


// Liberation de memoire alloqué dinamiquement
/**
  * @param ***mat notre matrice
  * @param dim_x dimension de la matrice
  * @return une matrice de dimension diagonale dim
  */
void freeMatrice(double ***mat, int dim_x);


double ** coeff_legendre (int n);

// Matrice diagonale
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice de dimension diagonale dim
  */

double ** creer_mat_diago (int dim);

double ** creer_mat (int dim_x, int dim_y) ;

double ** creer_mat_anti_diag (int dim);

double Poly_Leg(double x, int n);

double Norm_Const(int p, int q);



#endif
