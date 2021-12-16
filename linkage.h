#ifndef LINKAGE_H_INCLUDED
#define LINKAGE_H_INCLUDED
//#include"listeSC.h"

//#include "listeSC.h"

#define N 40 //presicion
#define sourceDB "DATA/DB/DBimg.txt"
#define sourcetxtDB "DATA/DB/txtDB.txt"
#define destDB "DATA/DB/"
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
