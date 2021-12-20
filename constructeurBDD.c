#include"constructeurBDD.h"

/*Moments logistic(Moments mom){
    BmpImg img1;
    char *path1 = "DATA/DB/A.BMP"; // path to txt file with images.
    img1 = readBmpImage(path1);
    mom=get_mom(img1,N);
    return mom;
}*/
//*
DataBase creerBDD(){
    DataBase bdd;
    bdd.images = creerListe(sizeof(Moments));
    return bdd;
}

void killBDD(DataBase *bdd){
    freeListe(bdd->images);
}

void dataBaseGOD(){
    //DataBase bdd = creerBDD();
    Moments momImg;// = creer_moments(N);
    BmpImg img;
    FILE *DB = fopen(sourceDB,"r");
    FILE *txtDB = fopen(sourcetxtDB,"w");
    //FILE *DBdest = fopen(destDB,"w");
    int img_count = 0;
    if (DB != NULL && txtDB != NULL) {
        fscanf(DB,"%d",&img_count);
        fprintf(txtDB,"%d\n",img_count);
        for (int i = 0 ;i<img_count; i++){
            char DBdest[40] = destDB;
            char *imgName = calloc (20,sizeof(char));
            char *imgPath = calloc (20,sizeof(char));
            fscanf(DB,"%s %s",imgPath,imgName);
            img = readBmpImage(imgPath);
            momImg = get_mom(img,N);
            momImg.label = imgName;
            strcat(DBdest,imgName);
            strcat(DBdest,".txt");
            fprintf(txtDB,"%s\n",DBdest);
            ecrireMomentTxt(DBdest,momImg);
            printf("%s\n",imgName);
            printf("image %s uploaded \n", imgName);
            free(imgName);
            free(imgPath);
            }
        printf("\nBDD Text files succesfully created ! ;) \n");
        fclose(DB);
        fclose(txtDB);
    }else
        printf("ERROR DB FILE MISSING OR DAMMAGED");
    Free_moments(&momImg);

}

DataBase creatListeBDD(char* sourcetxt){
    int i ;
    DataBase data_base = creerBDD();
    Moments momImg;
    unsigned int fileCount = 0;
    FILE *txtDB = fopen(sourcetxtDB,"r");
    if (txtDB != NULL){
        fscanf (txtDB,"%d\n",&fileCount);
        printf("-----file count %d-------\n",fileCount);
        for ( i=1; i<=fileCount; i++){
            printf("filepath of file %d aquired thus ",i);
            char* filePath = calloc (25,sizeof(char));
            fscanf(txtDB,"%s\n",filePath);

            momImg = lireMomentsTxt(filePath);

            ajout(data_base.images,&momImg,2);

        printf("%s added to liste\n",((Moments*)data_base.images->current->data)->label);
        free(filePath);

        }
    }
    else{
        printf("ERROR DB FILE MISSING OR DAMMAGED\n");
    }
    fclose(txtDB);
    printf("Done\n");
   // Free_moments(&momImg);
    return data_base;
}

