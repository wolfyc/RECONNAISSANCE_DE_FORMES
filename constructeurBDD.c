#include"constructeurBDD.h"

Moments logistic(Moments mom){
    BmpImg img1;
    //Moments mom1 = creer_moments(N);
    char *path1 = "DATA/DB/A.BMP"; // path to txt file with images.
   // FILE *DB =
    //printf("put an image in the main directory then give its name here|| directory : ");
    //fgets(path1,sizeof(path1),stdin);
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
    int img_count = 0;
    char *imgName=calloc (15 , sizeof(char));
    char *imgPath = calloc (15,sizeof(char));
    if (DB != NULL){
        fscanf(DB,"%d",&img_count);
        //printf(" img_count is %d",img_count);
        for (int i = 0 ;i<img_count; i++){
            fscanf(DB,"%s %s",imgPath,imgName);

            img = readBmpImage(imgPath);
            momImg = get_mom(img,N);
            momImg.label = imgName;

            ajout(bdd.images,&momImg,2);
            printf("%s\n",((Moments*)bdd.images->current->data)->label);
            printf("image %s uploaded \n",imgName);
            }
        fclose(DB);
    }else
        printf("ERROR DB FILE MISSING OR DAMMAGED");
    free(imgName);
    free(imgPath);
    return bdd;
}//*/
/*ListeSC* creerBDDliste (){
    ListeSC * listeBD = creerListe ( sizeof (Moments));
    Moments mom = creer_moments(N);
    mom = logistic(mom);
    ajout(listeBD,&mom,2);
    //Free_moments(&mom);
    return listeBD;
}
*/
