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

#endif // TOOLS_H_INCLUDED
