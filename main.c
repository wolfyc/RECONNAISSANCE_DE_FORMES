#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"

int main(void)
{
    BmpImg img1,img2,img3,img4,img5;
    char* path1 = "A_test.bmp";
    char* path2 = "A.bmp";
    char* path3 = "F.bmp";
    char* path4 = "D.bmp";
    char* path5 = "E.bmp";
    img1 = readBmpImage(path1);
    img2 = readBmpImage(path2);
    img3 = readBmpImage(path3);
    img4 = readBmpImage(path4);
    img5 = readBmpImage(path5);
    Moments mom1,mom2,mom3,mom4,mom5;
    mom1=get_mom(img1,46);
    mom2=get_mom(img2,46);
    mom3=get_mom(img3,46);
    mom4=get_mom(img4,46);
    mom5=get_mom(img5,46);

   // bmp_rec(path2,"test0.bmp",32,32,0.75);
    //ecrire_mom(path2,mom);
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,path1,path2,Dist_Euc(mom1.leg,mom2.leg,46));
    printf("La distance entre les deux image %s et %s est : %lf\n" ,path1,path3,Dist_Euc(mom1.leg,mom3.leg,46));
    printf("La distance entre les deux image  %s et %s  est : %lf\n" ,path1,path4,Dist_Euc(mom1.leg,mom4.leg,46));
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,path1,path5,Dist_Euc(mom1.leg,mom5.leg,46));

    return 0;
}
