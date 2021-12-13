#ifndef LINKAGE_H_INCLUDED
#define LINKAGE_H_INCLUDED
//#include"listeSC.h"

//#include "listeSC.h"

#define N 46 //presicion
#define sourceDB "DATA/DB/DB.txt"
#define destDB "DATA/DB/destDB.txt"
/*
typedef struct { // Starting point
    ListeSC * images;
} DataBase ;

typedef struct {
    Moments mom ;
    char * Label ;
} image ; // the names are just a test
//*/
 typedef struct {
    int n;
    double ** centres_norm;
    double ** leg ;
    char* label;
} Moments;
//*/

#endif // LINKAGE_H_INCLUDED
