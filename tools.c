#include "tools.h"
//creation de matrice rectangulaire.

double ** creer_mat (unsigned int dim_x, unsigned int dim_y)  //tested OK 2.0
{
    double **mat = malloc(dim_x*sizeof(double*));
    unsigned int i;
    for (i=0; i<dim_x; i++)
    {
        mat[i]=calloc(dim_y,sizeof(double));
    }
    return mat;
}
double ** Vander_monde (unsigned int dim,unsigned int pow_max,double moy)  // tested OK 2.0
{
    double ** van_m = creer_mat (dim,pow_max+1);
    unsigned int i, j;
    for (i=0; i<dim; i++)
    {
        for (j=0; j<=pow_max; j++)
        {
            van_m[i][j] = pow(i-moy,j);
        }
    }
    return van_m;
}
//creation matrice anti diago pour moment centr�es norm�
double ** creer_mat_anti_diag (unsigned int dim) // tested OK 2.0
{
    double **mat = malloc(dim*sizeof(double*));
    unsigned int i;
    for (i=0; i<dim; i++)
    {
        mat[i]=calloc(dim-i,sizeof(double));
    }
    return mat;
}

double ** creer_mat_diago (unsigned int dim) // tested OK 2.0
{
    double **mat = malloc(dim*sizeof(double*));
    unsigned int i;
    for ( i=0; i<dim; i++)
    {
        mat[i]=calloc(i+1,sizeof(double));
    }
    return mat;

}


void freeMatrice(double ***mat,unsigned int dim_x)   //Corrected 2.0
{
    unsigned int i;
    for ( i = 0; i< dim_x; i++)
    {
        free((*mat)[i]);
    }
    free(*mat);
    *mat = NULL;
    if ((*mat)==NULL) printf( "Functions succesfully Freed \n");
}

void printButterfly(){
     printf("\t\t\t\t                `         \'\n");
    printf("\t\t\t\t;,,,             `       \'             ,,,;\n");
    printf("\t\t\t\t`YES8888bo.       :     :       .od8888YES\'\n");
    printf("\t\t\t\t  888IO8DO88b.     :   :     .d8888I8DO88\n");
    printf("\t\t\t\t  8LOVEY\'  `Y8b.   `   \'   .d8Y\'  `YLOVE8\n");
    printf("\t\t\t\t jTHEE!  .db.  Yb. \'   \' .dY  .db.  8THEE!\n");
    printf("\t\t\t\t   `888  Y88Y    `b ( ) d\'    Y88Y  888\'\n");
    printf("\t\t\t\t    8MYb  \'\"        ,\',        \"\'  dMY8\n");
    printf("\t\t\t\t   j8prECIOUSgf\"\'   \':'   `\"?g8prECIOUSk\n");
    printf("\t\t\t\t     \'Y\'   .8\'     d\' \'b     \'8.   \'Y\'\n");
    printf("\t\t\t\t      !   .8\' db  d\'; ;`b  db \'8.   !\n");
    printf("\t\t\t\t         d88  `\'  8 ; ; 8  `\'  88b\n");
    printf("\t\t\t\t        d88Ib   .g8 \',\' 8g.   dI88b\n");
    printf("\t\t\t\t       :888LOVE88Y\'     \'Y88LOVE888:\n");
    printf("\t\t\t\t       \'! THEE888\'       `888THEE !\'\n");
    printf("\t\t\t\t          \'8Y  `Y         Y\'  Y8\'\n");
    printf("\t\t\t\t           Y                   Y\n");
    printf("\t\t\t\t           !                   !\n");
    printf("\n");
    printf("\n");
}



Moments creer_moments(unsigned int n ){
    Moments mom ;
    mom.n = n ;
    mom.centres_norm= creer_mat_anti_diag(n+1) ;
    mom.leg= creer_mat_anti_diag(n+1) ;
    mom.label = calloc (15,sizeof(char));
    return mom ;
}

void Free_moments (Moments *mom ){

    freeMatrice (&(mom->centres_norm),mom->n+1);
    freeMatrice(&(mom->leg),mom->n+1);
    mom->n=0 ;
}

Moments get_mom(BmpImg img,unsigned int  n)
{
    Moments mom = creer_moments(n) ;

    mom.centres_norm= mat_moments_centre_norme(img,n);

    mom.leg = matMomentsDeLegendre(img,n,mom.centres_norm);

    return mom;

}

double Dist_Euc (double ** mat1 , double **mat2 , unsigned int  n ) {  // tested with moments calculated from same image
                                                             //except that one of them is saved and red (in/from) a file
unsigned int  p,q;                                                     // Result was 0.000004 Due to the use of the tmp variable
double res = 0.00 ;                                          // in the function <lire_moments>
    for (p=0 ; p<=n ; p++ ){
        for (q=0 ; q<=n-p;q++){
            res+= pow(mat1[p][q]-mat2[p][q],2);
        }
    }
res = sqrt (res);

return res;
}



