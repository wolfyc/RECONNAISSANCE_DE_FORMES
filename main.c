#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
int main(void)
{
    /*ListeSC* BDD = creerListe(sizeof(Moments));
    BDD = creerBDDliste();
// Moments mom = logistic(mom);
    BmpImg img1;
        char* path1 = "A_test.bmp";

    img1 = readBmpImage(path1);
    Moments mom;
    mom=get_mom(img1,N);
    ajout(BDD,&mom,2);
    BDD->current = BDD->root;

    Moments *mom1 = (Moments*)BDD->current->data;
    Moments *mom2 = (Moments*)BDD->current->next->data;
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1->label,mom2->label,Dist_Euc(mom1->leg,mom2->leg,N));

    */
    int i = 0;
    DataBase bdd;
    bdd = logistics();
    bdd.images->current = bdd.images->root;
    Moments *mom1 = ((Moments*)bdd.images->current->data);
    Moments *mom2 = (Moments*)bdd.images->current->next->data;
    //for ((bdd.images)->current = (bdd.images)->root; hasNext(bdd.images); getNext(bdd.images)){
        //printf("%s\n",sizeof(((Moments*)bdd.images->current->data)->label));
   // }
    Moments m = *mom1;
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1->label,mom2->label,Dist_Euc(mom1->leg,mom2->leg,N));
    printf("number of elements in data base is %d \n",bdd.images->length);
    printf("%s %s",m.label,mom2->label);
    /*
    ListeSC * listeBD = creerListe (sizeof (Moments));
    Moments momImg;// = creer_moments(N);
    //char *source = sourceDB;
    BmpImg img;
    FILE *DB = fopen(sourceDB,"r");
    int img_count = 0;
    char *imgName=malloc (15 * sizeof(char));
    char *imgPath = malloc (15 * sizeof(char));
    if (DB != NULL){
        fscanf(DB,"%d",&img_count);
        printf(" img_count is %d",img_count);
        for (int i = 0 ;i<img_count; i++){
            fscanf(DB,"%s %s",imgPath,imgName);
            img = readBmpImage(imgPath);
            momImg = get_mom(img,N);
            momImg.label = imgName;
            ajout(listeBD,&momImg,2);
            }}
    listeBD->current = listeBD->root;

    Moments *mom1 = (Moments*)listeBD->current->data;
    Moments *mom2 = (Moments*)listeBD->current->next->data;
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1->label,mom2->label,Dist_Euc(mom1->leg,mom2->leg,N));
   //*/
    /*
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
    //*/
    return 0;
}
