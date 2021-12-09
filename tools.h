#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "linkage.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "myBmpGris.h"
#include "moment_geometrique.h"
//#include "tools.h"
#include "legendre.h"
#include "listeSC.h"
#include "img_reconstruct.h"
//#include "legendre.h"
//linking headers with their .C fies


/*

 typedef struct {
    int n ;
    double ** centres_norm;
    double ** leg ;
} Moments;
//*/

// creation et allocation d'une Matrice
/**
  * @param dim_x nombre des lignes de la matrice
  * @param dim_y nombre des colonnes de la matrice
  * @return une matrice de dimension dim_x * dim_y
  */
double ** creer_mat (int dim_x, int dim_y) ;
// Matrice diagonale
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice diagonale de dimension dim
  */

  /**
  * @param dim dimxdim la dim de la mat
  * @param pow_max l'ordre max de la mat
  * @param moy la translation des pixel ie pour centré les moment geo.
  * @return une matrice de vandermonde de dimension dim
  */
double ** Vander_monde (int dim,int pow_max,double moy);

// Matrice anti diagonle diagonale
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice de dimension dim_x * dim_y
  */
double ** creer_mat_anti_diag (int dim);

// Matrice diagonle
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice de dimension dim
  */
double ** creer_mat_diago (int dim);

// Matrice de reconstruction de l'image equation 12
/**
  * @param ***mat pointeur vers mat 2D
  * @param dim_x dimension vertical de la matrice
  * @return no return
  */
void freeMatrice(double ***mat, int dim_x);



// Matrice de reconstruction de l'image equation 12
/**
  * @param dim_y dimension de la matrice
  * @param dim_x dimension de la matrice
  * @param n dimension de la matrice
  * @return une matrice de dimension dim_x * dim_y
  */

Moments creer_moments(int n );

void Free_moments (Moments *mom );

Moments get_mom(BmpImg img,int n);

double Dist_Euc (double ** mat1 , double **mat2 , int n ); // tested with moments calculated from same image


#endif // TOOLS_H_INCLUDED
