#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
int main(void)
{
//chaine de caractère de la source vers l'image a testé
    char * input_path="A_test.bmp"; 
//double pour stocké la distance entre les images stocké et l'image a testé
    double Mindist;
//chaine de caractère qui le nom du prediction du program
    char * output;
//declaration de la base de donnée
    DataBase bdd;
//creation de la list chainé et l'affecter à bdd 
    bdd = chainageListeBDD(sourcetxtDB);
//lecture de l'image
    BmpImg InputImg=readBmpImage(input_path);
//creation du moment de l'image
    Moments InputMom = getMoment(InputImg,N);
//cherchons l'image la plus proche a l'image teste dans la base de données
    Mindist = distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->root->data)->leg,N);
    output = ((Moments*)bdd.images->root->data)->label;
    for(bdd.images->current=bdd.images->root;hasNext(bdd.images);getNext(bdd.images)){
        if (Mindist>distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N)){
            Mindist=distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N);
            output = ((Moments*)bdd.images->current->data)->label;

        }
    }
//affichage du resultat
printf("%s \t %lf\n" ,output,Mindist);
//desallocation dynamique de la BDD
freeBDD(&bdd);
// a little art won't hurt
printButterfly();
    return 0;
}
