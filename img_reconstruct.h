#ifndef IMG_RECONSTRUCT_H_INCLUDED
#define IMG_RECONSTRUCT_H_INCLUDED
#include "linkage.h"
#include "tools.h"
/*#include "tools.h"
//#include "myBmpGris.h"
#include "legendre.h"
//*/

// Matrice de reconstruction de l'image equation 12
/**
  * @param mom moment structure geom
  * @param x_norm range
  * @param y_norm range
  * @return valeur elementaire de la matrice de image
  */
double pixel_rec (Moments mom ,double x_norm , double y_norm  );
double** img_rec (char * filename,unsigned int  dim_x,unsigned int  dim_y );
void bmp_rec (char* filemom , char* imgName,unsigned int dim_x , unsigned int dim_y , double threshold);
#endif // IMG_RECONSTRUCT_H_INCLUDED
