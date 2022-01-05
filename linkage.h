#ifndef LINKAGE_H_INCLUDED
#define LINKAGE_H_INCLUDED

#define N 40 
#define sourceDB "DATA/DB/DBimg.txt" //file of image names
#define sourcetxtDB "DATA/DB/txtDB.txt" // file of converted to moments file names
#define destDB "DATA/DB/" //Data Base directory

typedef struct {
    int n;
    double ** centres_norm;
    double ** leg;
    char* label;
} Moments;


#endif // LINKAGE_H_INCLUDED
