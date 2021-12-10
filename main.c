#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"

int main(void)
{
   // BmpImg img;
    //char* path = "A.bmp";
    //img = readBmpImage(path);
    Moments mom;
    //mom = get_mom(img,46);
    char* path2 = "moment_ecrit00.txt";
    //char* path2 = "moment_ecrit00.txt";
    mom=lire_moments(path2);
    afficher_moments(mom);
    bmp_rec(path2,"test0.bmp",32,32,0.75);
    //ecrire_mom(path2,mom);
    printf("Hello world!\n");
    return 0;
}
