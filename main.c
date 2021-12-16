#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
int main(void)
{
     //dataBaseGOD();
    DataBase bdd;

    bdd = creatListeBDD(sourcetxtDB);
    // Moments mom1=lireMomentsTxt("DATA/DB/A_bd.txt");
   // afficher_moments(mom1,0);
    afficherListe(bdd.images);
    bdd.images->current=bdd.images->root;
    printf("%d \n" ,bdd.images->length);
    Free_moments((Moments*)bdd.images->root->data);
   //Free_moments((Moments*)bdd.images->last->data);

    //afficherListe(bdd.images);



    return 0;
}
/*
BmpImg img1,img2;

   char* path1 = "A.bmp";
   char* path2 = "A_test.bmp";

   img1 = readBmpImage(path1);
   img2 = readBmpImage(path2);

Moments mom1=get_mom(img1,46);

mom1.label=path1;

Moments mom2=get_mom(img2,46);

mom2.label=path2;
ecrireMomentTxt("test1.txt",mom1);

printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1.label,mom2.label,Dist_Euc(mom1.leg,mom2.leg,N));

 Free_moments(&mom1);

 Free_moments(&mom2);
*/
