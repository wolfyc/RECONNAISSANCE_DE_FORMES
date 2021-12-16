#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
int main(void)
{
    /*ListeSC* BDD = creerListe(sizeof(moments));
    BDD = creerBDDliste();
// moments mom = logistic(mom);
    BmpImg img1;
        char* path1 = "A_test.bmp";

    img1 = readBmpImage(path1);
    moments mom;
    mom=get_mom(img1,N);
    ajout(BDD,&mom,2);
    BDD->current = BDD->root;

    moments *mom1 = (moments*)BDD->current->data;
    moments *mom2 = (moments*)BDD->current->next->data;
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1->label,mom2->label,Dist_Euc(mom1->leg,mom2->leg,N));

    */
  //  int i = 0;
   // DataBase bdd;
   // bdd = logistics();
   // bdd.images->current = bdd.images->root;
  //  Moments *mom1 = ((Moments*)bdd.images->current->data);
  //  ecrire_mom("test0000.txt",*mom1);
  // Moments mom = lire_moments("test0000.txt");
  //afficher_moments(mom,0);
  //printf("%s" ,mom.label);
  // bmp_rec("E_bd.txt","v.bmp",32,32,1);
//=======
  //  DataBase bdd= creerBDD();
   // dataBaseGOD();
//    bdd = creatListeBDD(bdd , sourcetxtDB);
   // bdd.images->current = bdd.images->root;
   // Moments *mom1 = ((Moments*)bdd.images->current->data);
   // ecrireMomentTxt("rr.txt",*mom1);
   //bmp_rec("test0000.txt","v.bmp",32,32,1);
//Free_moments(mom1);
   // DataBase bdd;
   // bdd = logistics();
   // bdd.images->current = bdd.images->root;
    //Moments *mom1 = ((Moments*)bdd.images->current->data);
    //ecrireMomentTxt("test0000.txt",*mom1);
    //getNext(bdd.images);
  //  Moments *mom2 =((Moments*)bdd.images->current->next->data);
    //char *label = ((moments*)bdd.images->current->data)->label;
//    afficherData(((moments*)bdd.images->current->data));
    //getNext(bdd.images);
//    afficherData(((moments*)bdd.images->current->data));
 //printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1->label,mom2->label,Dist_Euc(mom1->leg,mom2->leg,N));
//    printf("%s %s",m.label,mom2->label);
    /*
    ListeSC * listeBD = creerListe (sizeof (moments));
    moments momImg;// = creer_moments(N);
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

    moments *mom1 = (moments*)listeBD->current->data;
    moments *mom2 = (moments*)listeBD->current->next->data;
    printf("La distance entre les deux image %s et %s  est : %lf\n" ,mom1->label,mom2->label,Dist_Euc(mom1->leg,mom2->leg,N));
   //*/

/*BmpImg img1;

    char* path1 = "A.bmp";

    img1 = readBmpImage(path1);

 Moments mom1=get_mom(img1,40);
 mom1.label= path1 ;
 afficher_moments(mom1,0);
 ecrireMomentTxt("jj.txt",mom1);
 */
Moments mom1=lireMomentsTxt("jj.txt");

 afficher_moments(mom1,0);
 bmp_rec("jj.txt","testv2.0.bmp",32,32,1);
 Free_moments(&mom1);
 /*   double ** a= mat_moments_centre_norme(img1,46);
    double ** b= matMomentsDeLegendre(img1,46,a);


     for ( int p=0; p<=46; p++)
    {
        for (int q=0; q<=46-p; q++)
        {

           printf("%f " ,a[p][q]) ;

        }
        printf("\n");
    }


   // bmp_rec(path2,"test0.bmp",32,32,0.75);
    //ecrire_mom(path2,mom);
  // afficher_moments(mom1,0);
    //*/
    return 0;
}
