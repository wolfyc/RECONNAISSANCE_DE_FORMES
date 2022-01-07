#ifndef LINKAGE_H_INCLUDED
#define LINKAGE_H_INCLUDED

#define N  46
#define sourceDB "DATA/DB/DBimg.txt" //file of images repertoires
#define sourcetxtDB "DATA/DB/txtDB.txt" // file  moments repertoires
#define destDB "DATA/DB/" //Data Base directory

typedef struct {
    int n;
    double ** centres_norm;
    double ** leg;
    char* label;
} Moments;


#endif // LINKAGE_H_INCLUDED
