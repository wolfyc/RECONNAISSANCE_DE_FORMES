#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"

int main(void)
{
    BmpImg img;
    char* path = "A.bmp";
    img = readBmpImage(path);
    Moments mom;
    mom = get_mom(img,42);
    char* path2 = "moment_ecrit";
    ecrire_mom(path2,mom);
    printf("Hello world!\n");
    return 0;
}