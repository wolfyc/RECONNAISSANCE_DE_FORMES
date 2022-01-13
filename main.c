#include <stdio.h>
#include <stdlib.h>
#include "tools.h"
#include "myBmpGris.h"
#include"constructeurBDD.h"
#include<string.h>
#define dimRecx 32
#define dimRecy 32
#define Testfile "InputImg/TestImg.txt"
#define TestDir "InputImg/"

int main(void)
{
//variable de commande sur l'interface.
    int a;
//medium de concatenation
    char  tmp[20] ;
//le repertoire vers la source
    char  input_path[]= TestDir;
//initialisation vers le repertoire de la base de données
    char c[] = destDB ;



//double pour stocké la distance entre les images stocké et l'image à testé
    double Mindist;
// variable pour memorisé le nom de l'image reconue.
    char * output;

    printf(" Voulez-vous creer une nouvelle base de donnee ? [1/0] \n");
    scanf("%d",&a);
    while ((a != 1 )&&(a != 0 ))
    {
        printf(" Veuillez rentrer 1 ou 0! [oui/non]:[1/0] \n");
        scanf("%d",&a);
    }
    if (a == 1)
    {
        imgTotxt();
    }
    printf("Voulez-vous faire une reconnaisssance de forme ?[1/0]\n");
    scanf("%d",&a);
    while ((a != 1) && (a != 0))
    {
        printf("Veuillez rentrer 1 ou 0! [oui/non]:[1/0] \n");
        scanf("%d",&a);
    }
    if (a == 0)
    {
        exit(0);
    }

    printf(" Veuillez choisir un nom d'image a reconnaitre de la liste suivante : \n \n ");
    FILE *fichier = fopen(Testfile,"r");
    if (fichier != NULL )
    {
        while (fscanf(fichier,"%s \n",tmp) == 1)
        {
            printf("\t | %s \n",tmp);
        }
    }
    fclose(fichier);
    printf("\n Sinon, veuiller sauvegarder une image dans le fichier InputImg et indiquer son nom : \n" );
    scanf("%s", tmp);
    strcat(input_path,tmp);

    printf("\n Calcule en cours ... \n" );
//declaration de la base de donnée
    DataBase bdd;
//creation de la list chainé et l'affecter à bdd
    bdd = chainageListeBDD(sourcetxtDB);
// De-commentez la prochaine ligne pour re-créer la Base de Données Pour afficher la Base de Données
//afficherBdd(&bdd);
//lecture de l'image
    BmpImg InputImg=readBmpImage(input_path);
//creation du moment de l'image
    Moments InputMom = getMoment(InputImg,N);
    InputMom.label="InputImg";
//cherchons l'image la plus proche a l'image teste dans la base de données
    Mindist = distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->root->data)->leg,N);
    output = ((Moments*)bdd.images->root->data)->label;
    for(bdd.images->current=bdd.images->root; hasNext(bdd.images); getNext(bdd.images))
    {
        if (Mindist>distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N))
        {
            Mindist=distanceEuclidienne(InputMom.leg,((Moments*)bdd.images->current->data)->leg,N);
            output = ((Moments*)bdd.images->current->data)->label;


        }
    }
//affichage du resultat
    printf("\n La forme la plus proche de l'image %s est : %s \n \n La distance euclidienne entre leurs moments de Legendre est : %lf\n",input_path,output,Mindist);

    printf("\n Voulez-vous faire une reconstruction de l'image entre ? [1/0] \n");
    scanf("%d",&a);
    while ((a != 1 )&&(a != 0 ))
    {
        printf("Veuillez rentrer 1 ou 0! [oui/non]:[1/0] \n");
        scanf("%d",&a);
    }
    if (a==1)
    {
        strcat(c,output);
        strcat( c,".txt");
        reconstructionBmp(c,"ImgRec.bmp",dimRecx,dimRecx);
    }


    FreeMoments(&InputMom);
//desallocation dynamique de la BDD
    freeBDD(&bdd);


    return 0;
}
