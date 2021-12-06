#ifndef LEGENDRE_H_INCLUDED
#define LEGENDRE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"

// calculateur du coef de legendre
/**
  * @param x la valeur du coeff_legendre et sa position de ligne
  * @param i l'ordre et la position dans la colonne de la matrice
  * @return le coeff de legendre
  */
double coeff (int x, int i);

// calculateur du coef de legendre
/**
  * @param n la dimension de la matrice de legendre
  * @return lune matrice de coeff de legendre
  */
double ** coeff_legendre (int n);

// calculateur distance euclidienne
/**
  * @param mat1 la valeur du coeff_legendre et sa position de ligne
  * @param i l'ordre et la position dans la colonne de la matrice
  * @return le coeff de legendre
  */
double Dist_Euc (double ** mat1 , double **mat2 , int n ); // tested with moments calculated from same image

// lecture  des moment centres et normes à partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment centrés et normés
  */
double ** lire_moments_centre_norme(char * filename,int * n  );
// lecture  des moment de legendre à partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double ** lire_moments_legendre(char * filename,int * n  );

// lecture  des moment centres et normes à partir d'un fichier
/**
  * @param filename string of char
  * @param n l'ordre des moments à ecrire dans le fichier
  * @param momg matrice moment geomtique centrés normés
  * @param leg matrice de poly de legendre
  * @return sans retour
  */
void ecrire_mom (char * filename ,double ** momg , double ** leg ,int n  );

// lecture  des moment centres et normes à partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
 
//double ** lire_moments(char * filename );
//void ecrire_mom (char * filename ,double ** moments ,int n );
Moments lire_moments (char * filename );

double ** Moments_Legendre (BmpImg img, int n );
// lecture  des moment centres et normes à partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double Moment_Leg (BmpImg img,int p,int q, int n );
// lecture  des moment centres et normes à partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double Norm_Const(int p, int q);
// lecture  des moment centres et normes à partir d'un fichier
/**
  * @param filename string of char
  * @param n pointeur vers l'ordre des moments lu du fichiers
  * @return matrice de moment de legendre
  */
double P(double x,int n );
void afficher_moments (Moments mom );

#endif // LEGENDRE_H_INCLUDED
