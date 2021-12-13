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

DataBase logistics(){
    DataBase bdd = creerBDD();
    Moments momImg;// = creer_moments(N);
    BmpImg img;
    FILE *DB = fopen(sourceDB,"r");
    FILE *txtDB = fopen(sourcetxtDB,"w");
    //FILE *DBdest = fopen(destDB,"w");
    int img_count = 0;
    if (DB != NULL && txtDB != NULL) {
        fscanf(DB,"%d",&img_count);
        //printf(" img_count is %d",img_count);
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
            printf("%s",DBdest);
            fprintf(txtDB,"%s\n",DBdest);
            ecrireMomentTxt(DBdest,momImg);
            ajout(bdd.images,&momImg,2);
            printf("%s\n",imgName);
            printf("image %s uploaded \n", imgName);
            }
        fclose(DB);
    }else
        printf("ERROR DB FILE MISSING OR DAMMAGED");
    Free_moments(&momImg);
    return bdd;
}

