#ifndef MOMENT_GEOMETRIQUE_H_INCLUDED
#define MOMENT_GEOMETRIQUE_H_INCLUDED
#include "linkage.h"
#include "tools.h"
/*#include "tools.h"
#include "myBmpGris.h"
//*/
// Moment geometrique equation (2)
/**
  * @param img image binaire
  * @param p l'ordre de x
  * @param q l'ordre de y
  * @return un moment geometrique
  */
double mom_geo (BmpImg img, unsigned int p, unsigned int q, unsigned int n );

// Moment geometrique centr� (vandermonde) et norm� equation (6)
/**
  * @param img image binaire
  * @param p l'ordre de x
  * @param q l'ordre de y
  * @return un moment geometrique centr� et norm�
  */
double momentGeoCentreNorme (BmpImg img,unsigned int p, unsigned int q, unsigned int n);

// Matrice des Moments geometriques centr�s (vandermonde) et norm�s equation (6)
/**
  * @param img image binaire
  * @param n la dimension de la matrice
  * @return une matrice anti diagonale superieur des moments geometriques centr�s et norm�s
  */
double ** mat_moments_centre_norme(BmpImg img,unsigned int n);


#endif // MOMENT_GEOMETRIQUE_H_INCLUDED
