#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

#include "linkage.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<string.h>
#include "myBmpGris.h"
#include "moment_geometrique.h"
#include "legendre.h"
#include "listeSC.h"
#include "img_reconstruct.h"

// creation et allocation d'une Matrice
/**
  * @param dim_x nombre des lignes de la matrice
  * @param dim_y nombre des colonnes de la matrice
  * @return une matrice de dimension dim_x * dim_y
  */
double ** creerMatrice (unsigned int dim_x, unsigned int dim_y) ;

  /**
  * @param dim dimxdim la dim de la mat
  * @param pow_max l'ordre max de la mat
  * @param moy la translation des pixel ie pour centr� les moment geo.
  * @return une matrice de vandermonde de dimension dim
  */
double ** matVandermonde (unsigned int dim,unsigned int pow_max,double moy);

// Matrice anti diagonle diagonale
/**
  * @param dim dimension de la matrice
  * @return une matrice de dimension dim_x * dim_y
  */
double ** creerMatAntiDiagonal (unsigned int dim);

// Matrice diagonle
/**
  * @param dim dimension de la matrice
  *
  * @return une matrice de dimension dim
  */
double ** creerMatDiagonale (unsigned int dim);

// Matrice de reconstruction de l'image equation 12
/**
  * @param ***mat pointeur vers mat 2D
  * @param dim_x dimension vertical de la matrice
  * @return no return
  */
void freeMatrice(double ***mat, unsigned int dim_x);



/**
  * @param n l'ordre
  * @return une structure moment initialisé
  */
Moments creerMoments(unsigned int n );

/**
  * @param mom l'adresse du moment
  * @return free la memoire d'un moment
  */
void FreeMoments (Moments *mom );
/**
  * @param img une image
  * @param n l'ordre 
  * @return le Moment de l'image
  */
Moments getMoment(BmpImg img,unsigned int n);

/**
  * @param mat1 matrice de double des moment de legendre
  * @param mat2 matrice de double des moment de legendre
  * @param n l'ordre
  * @return la distance euclidienne entre deux matrice
  */
double distanceEuclidienne (double ** mat1 , double **mat2 ,unsigned int n );
 /** 
  * @param aucun
  * @return ART butterfly
  * */
void printButterfly();

/** 
  * @param filename chaine de caractère du fichier txt à ecrire
  * @param mom
  * @return ART butterfly
  * */
void ecrireMomentTxt (char * filename , Moments mom  ) ;

Moments lireMomentsTxt (char * filename );

void afficherMoments (Moments mom, int legOrcenNor ); //0 for leg -- 1 for norm 2 for leg
#endif // TOOLS_H_INCLUDED
