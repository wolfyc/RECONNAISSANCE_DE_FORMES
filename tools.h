#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"

// Matrice diagonale
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice de dimension diagonale dim
  */

double ** creer_mat_diago (int dim);

double ** creer_mat (int dim_x, int dim_y) ;

double ** creer_mat_anti_diag (int dim);

#endif // TOOLS_H_INCLUDED
