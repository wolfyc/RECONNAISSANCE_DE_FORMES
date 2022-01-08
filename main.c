#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
int main(void)
{
//De-commentez la prochaine ligne pour re-créer la Base de Données
  //imgTotxt();
//chaine de caractère de la source vers l'image a testé
    char * input_path="InputImg/B_test.bmp";
//double pour stocké la distance entre les images stocké et l'image à testé
    double Mindist;
//chaine de caractère qui le nom du prediction du program
    char * output;
//declaration de la base de donnée
    DataBase bdd;
//creation de la list chainé et l'affecter à bdd
    bdd = chainageListeBDD(sourcetxtDB);
// De-commentez la prochaine ligne pour re-créer la Base de Données Pour afficher la Base de Données
// afficherListe(bdd.images);
//lecture de l'image
    BmpImg InputImg=readBmpImage(input_path);
//creation du moment de l'image
    Moments InputMom = getMoment(InputImg,N);
    InputMom.label="InputImg";
//cherchons l'image la plus proche a l'image teste dans la base de données
    Mindist = distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->root->data)->leg,N);
    output = ((Moments*)bdd.images->root->data)->label;
    for(bdd.images->current=bdd.images->root;hasNext(bdd.images);getNext(bdd.images)){
            printf("%s \t %lf\n" ,((Moments*)bdd.images->current->data)->label,distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N));
        if (Mindist>distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N)){
            Mindist=distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N);
            output = ((Moments*)bdd.images->current->data)->label;


        }
    }
//affichage du resultat
printf("%s \t %lf\n" ,output,Mindist);
FreeMoments(&InputMom);
//desallocation dynamique de la BDD
freeBDD(&bdd);


    return 0;
}
