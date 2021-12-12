#ifndef CONSTRUCTEURBDD_H_INCLUDED
#define CONSTRUCTEURBDD_H_INCLUDED

#include "tools.h"

typedef struct { // Starting point
    ListeSC * images;
} DataBase ;
// allocation de base de données
/**
  * .
  * @return une list dans la struct en dessus
  */
DataBase creerBDD();
// creation de data
/**
  *
  * @param aucun
  * @return une bdd
  */
DataBase logistics();
//Moments logistic(Moments mom);
ListeSC* creerBDDliste ();
#endif // CONSTRUCTEURBDD_H_INCLUDED
