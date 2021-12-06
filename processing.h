#ifndef _processing_h_
#define _processing_h_

#define N 46
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//linking headers with their .C fies
#include "legendre.h"
#include "moment_geometrique.h"
#include "myBmpGris.h"
#include "tools.h"
#include "Vandermonde.h"

typedef struct {
    int n ;
    double ** centres_norm;
    double ** leg ;
} Moments ;

double P(double x, int n);

double Norm_Const(int p, int q);



#endif
