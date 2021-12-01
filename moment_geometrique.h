#ifndef MOMENT_GEOMETRIQUE_H_INCLUDED
#define MOMENT_GEOMETRIQUE_H_INCLUDED
#include "processing.h"
#include "myBmpGris.h"
double mom_geo (BmpImg img, int p, int q, int n );

double mom_geo_centre (BmpImg img,int p, int q, int n);

double ** mat_TriAntDiagSup(BmpImg img,int n);

#endif // MOMENT_GEOMETRIQUE_H_INCLUDED
