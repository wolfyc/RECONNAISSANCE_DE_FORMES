#ifndef CONSTRUCTEURBDD_H_INCLUDED
#define CONSTRUCTEURBDD_H_INCLUDED

#include "tools.h"

typedef struct { // Starting point
    ListeSC * images;
} DataBase ;

// allocation de base de donn�es
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
void dataBaseGOD();
//Moments logistic(Moments mom);
DataBase creatListeBDD(DataBase *bdd,char* sourcetxt);
#endif // CONSTRUCTEURBDD_H_INCLUDED
