#ifndef LEGENDRE_H_INCLUDED
#define LEGENDRE_H_INCLUDED
#include "linkage.h"
#include "tools.h"
/*
#include "tools.h"
#include "myBmpGris.h"
//*/
// calculateur du coef de legendre
/**
  * @param x la valeur du coeff_legendre et sa position de ligne
  * @param i l'ordre et la position dans la colonne de la matrice
  * @return le coeff de legendre
  */
double coeff (unsigned int  x, unsigned int  i);

// calculateur du coef de legendre
/**
  * @param n la dimension de la matrice de legendre
  * @return lune matrice de coeff de legendre
  */
double ** coeff_legendre (unsigned int  n);
// lecture  des moment centres et normes � partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double P(double x,unsigned int  n );
double Pn(double x, unsigned int n);
// lecture  des moment centres et normes � partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double Norm_Const(unsigned int  p, unsigned int  q);

// lecture  des moment centres et normes � partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double Moment_Leg (BmpImg img,unsigned int  p,unsigned int  q, unsigned int  n , double ** co , double ** momg);

// lecture  des moment centres et normes � partir d'un fichier
/**
  * @param filename string of char
  * @param n l'ordre des moments � ecrire dans le fichier
  * @param momg matrice moment geomtique centr�s norm�s
  * @param leg matrice de poly de legendre
  * @return sans retour
  */
double ** Moments_Legendre (BmpImg img, unsigned int  n ,double ** momg );
void ecrire_mom (char * filename , Moments mom  ) ;

Moments lire_moments (char * filename );
void afficher_moments (Moments mom );

#endif // LEGENDRE_H_INCLUDED
