#include"constructeurBDD.h"

Moments logistic(Moments mom){
    BmpImg img1;
    char *path1 = "DATA/DB/A.BMP"; // path to txt file with images.
    img1 = readBmpImage(path1);
    mom=get_mom(img1,N);
    return mom;
}
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
            char *imgName = calloc (15,sizeof(char));
            char *imgPath = calloc (15,sizeof(char));
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
            }
        printf("\nBDD Text files succesfully created ! ;) \n");
        fclose(DB);
        fclose(txtDB);
    }else
        printf("ERROR DB FILE MISSING OR DAMMAGED");
    Free_moments(&momImg);
}

DataBase creatListeBDD(DataBase *bdd,char* sourcetxt){
    //DataBase bdd = creerBDD();
   // killBDD(bdd);
   // *bdd = creerBDD();
    Moments momImg;
    unsigned int fileCount = 0;
    FILE *txtDB = fopen(sourcetxtDB,"r");
    if (txtDB != NULL){
        fscanf (txtDB,"%d",&fileCount);
        printf("\n\n-----file count %d-------\n",fileCount);
        for (int i=0; i<fileCount; i++){
                printf("filepath of file %d aquired thus ",i+1);
            char* filePath = calloc (15,sizeof(char));
            fscanf(txtDB,"%s",filePath);
            momImg = lireMomentsTxt(filePath);
            ajout(bdd->images,&momImg,2);
        printf("%s added to liste\n",((Moments*)bdd->images->current->data)->label);
        }
        fclose(txtDB);
    }else
        printf("ERROR DB FILE MISSING OR DAMMAGED\n");
    Free_moments(&momImg);
    return *bdd;
}

