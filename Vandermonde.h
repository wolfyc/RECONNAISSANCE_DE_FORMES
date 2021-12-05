#ifndef VANDERMONDE_H_INCLUDED
#define VANDERMONDE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"
// Matrice de Vandermonde avec la capa de centré un pixel
/**
  * @param dim dimxdim la dim de la mat
  * @param pow_max l'ordre max de la mat
  * @param moy la translation des pixel ie pour centré les moment geo.
  * @return une matrice de vandermonde de dimension dim
  */
double ** Vander_monde (int dim,int pow_max,double moy);


#endif // VANDERMONDE_H_INCLUDED
