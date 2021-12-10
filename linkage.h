#ifndef LINKAGE_H_INCLUDED
#define LINKAGE_H_INCLUDED




#define N 46

//*
typedef struct { // Starting point 
    ListeSC * images;
} DataBase ; 
typedef struct {
    Moments mom ;
    char * Label ;
} image ; // the names are just a test

 typedef struct {
    int n ;
    double ** centres_norm;
    double ** leg ;
} Moments;
//*/

#endif // LINKAGE_H_INCLUDED
