#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
int main(void)
{
    char * input_path="hoho.bmp";
    double Mindist;
    char * output;
    dataBaseGOD();
    DataBase bdd;
    bdd = creatListeBDD(sourcetxtDB);
    printf("enter your image directory ... \n");
//    scanf("%s \n" ,input_path);
    BmpImg InputImg=readBmpImage(input_path);
    Moments InputMom = get_mom(InputImg,N);

    Mindist = Dist_Euc(InputMom.leg,((Moments*)bdd.images->root->data)->leg,N);
    output = ((Moments*)bdd.images->root->data)->label;

    for(bdd.images->current=bdd.images->root;hasNext(bdd.images);getNext(bdd.images)){
        if (Mindist>Dist_Euc(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N)){
            Mindist=Dist_Euc(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N);
            output = ((Moments*)bdd.images->current->data)->label;
        }
    }
    printf("%f \t %s\n" ,Mindist,output);
  // killBDD(&bdd);
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
