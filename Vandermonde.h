#ifndef VANDERMONDE_H_INCLUDED
#define VANDERMONDE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"
// Matrice de Vandermonde
/**
  * @param dim dimxdim la dim de la mat
  * @param pow_max l'ordre max de la mat
  * @return une matrice de dimension dim
  */
double ** Vander_monde (int dim,int pow_max,double moy);


#endif // VANDERMONDE_H_INCLUDED
