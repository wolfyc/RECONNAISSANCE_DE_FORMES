#ifndef MOMENT_GEOMETRIQUE_H_INCLUDED
#define MOMENT_GEOMETRIQUE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"

// Moment geometrique equation (2)
/**
  * @param img image binaire
  * @param p l'ordre de x
  * @param q l'ordre de y
  * @return un moment geometrique
  */
double mom_geo (BmpImg img, int p, int q, int n );

// Moment geometrique centré (vandermonde) et normé equation (6)
/**
  * @param img image binaire
  * @param p l'ordre de x
  * @param q l'ordre de y
  * @return un moment geometrique centré et normé
  */
double momentGeoCentreNorme (BmpImg img,int p, int q, int n);

// Matrice des Moments geometriques centrés (vandermonde) et normés equation (6)
/**
  * @param img image binaire
  * @param n la dimension de la matrice
  * @return une matrice anti diagonale superieur des moments geometriques centrés et normés
  */
double ** mat_TriAntDiagSup(BmpImg img,int n);

#endif // MOMENT_GEOMETRIQUE_H_INCLUDED
