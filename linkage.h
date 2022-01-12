#ifndef LINKAGE_H_INCLUDED
#define LINKAGE_H_INCLUDED

#define N  46
#define sourceDB "DATA/DB/DBimg.txt" //repertoire du fichiers Map images
#define sourcetxtDB "DATA/DB/txtDB.txt" //repertoire du fichiers Map Moment des images
#define destDB "DATA/DB/" //repertoire du base de données
#define dimRecx 32
#define dimRecy 32
#define Testfile "InputImg/TestImg.txt"
#define TestDir "InputImg/"
typedef struct {
    int n;
    double ** centres_norm;
    double ** leg;
    char* label;
} Moments;


#endif // LINKAGE_H_INCLUDED
