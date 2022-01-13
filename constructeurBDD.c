#include"constructeurBDD.h"


DataBase creerBDD()
{
    DataBase bdd;
    bdd.images = creerListe(sizeof(Moments));
    return bdd;
}

void freeBDD(DataBase *bdd)
{
    freeListe(bdd->images);
}
void afficherBdd (DataBase* bdd)
{
    afficherListe(bdd->images);
}
void imgTotxt()
{
    printf("Creation de la base de donnees en cours ... \n");
    Moments momImg ;
    BmpImg img;
    FILE *DB = fopen(sourceDB,"r");
    FILE *txtDB = fopen(sourcetxtDB,"w");
    int img_count = 0;
    if (DB != NULL && txtDB != NULL)
    {
        fscanf(DB,"%d",&img_count);
        fprintf(txtDB,"%d\n",img_count);
        for (int i = 0 ; i<img_count; i++)
        {
            char DBdest[40] = destDB;
            char *imgName = calloc (20,sizeof(char));
            char *imgPath = calloc (20,sizeof(char));
            fscanf(DB,"%s %s",imgPath,imgName);
            img = readBmpImage(imgPath);
            //   printf("%s" ,imgPath);
            momImg = getMoment(img,N);
            momImg.label = imgName;
            strcat(DBdest,imgName);
            strcat(DBdest,".txt");
            fprintf(txtDB,"%s\n",DBdest);

            ecrireMomentTxt(DBdest,momImg);
            // printf("%s\n",imgName);
            //   printf("image %s uploaded \n", imgName);
            free(imgName);
            free(imgPath);

        }
        // printf("\nBDD Text files succesfully created ! ;) \n");
        fclose(DB);
        fclose(txtDB);
    }
    else
        printf("ERROR DB FILE MISSING OR DAMMAGED");
    FreeMoments(&momImg);
    printf(" base de donnees creer avec succes \n");

}

DataBase chainageListeBDD(char* sourcetxt)
{

    int i ;
    DataBase data_base = creerBDD();
    Moments momImg;
    unsigned int fileCount = 0;
    FILE *txtDB = fopen(sourcetxtDB,"r");
    if (txtDB != NULL)
    {
        fscanf (txtDB,"%d\n",&fileCount);
        for ( i=1; i<=fileCount; i++)
        {
            //  printf("filepath of file %d aquired thus ",i);
            char* filePath = calloc (25,sizeof(char));
            fscanf(txtDB,"%s\n",filePath);

            momImg = lireMomentsTxt(filePath);

            ajout(data_base.images,&momImg,2);

            //printf("%s added to liste\n",((Moments*)data_base.images->current->data)->label);
            free(filePath);

        }
    }
    else
    {
        printf("ERROR DB FILE MISSING OR DAMMAGED\n");
    }
    fclose(txtDB);
    return data_base;
}


