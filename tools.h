#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"

// Matrice diagonale
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice diagonale de dimension dim
  */

double ** creer_mat_diago (int dim);

// creation et allocation d'une Matrice
/**
  * @param dim_x nombre des lignes de la matrice
  * @param dim_y nombre des colonnes de la matrice
  * @return une matrice de dimension dim_x * dim_y
  */
double ** creer_mat (int dim_x, int dim_y) ;

// Matrice anti diagonle diagonale
/**
  * @param dim dimension de la matrice
  * 
  * @return une matrice de dimension dim_x * dim_y
  */
double ** creer_mat_anti_diag (int dim);

// Matrice de reconstruction de l'image equation 12
/**
  * @param dim_y dimension de la matrice
  * @param dim_x dimension de la matrice
  * @param n dimension de la matrice
  * @return une matrice de dimension dim_x * dim_y
  */

Moments creer_moments(int n );



void Free_moments (Moments *mom );



double** img_rec (char * filename,int dim_x,int dim_y );


double pixel_rec (Moments mom ,double x_norm , double y_norm  );


Moments get_mom(BmpImg img,int n);
#endif // TOOLS_H_INCLUDED
