#include "legendre.h"

double coeff (unsigned int  x, unsigned int  i)  // Tested OK 2.0
{
    if (x==0 && i==0)
    {
        return 1;
    }
    else
    {
        if (x==1 && i==0)
        {
            return 0 ;
        }
        else
        {
            if (x!=1 && i==0)
            {
                return ((-((double)x-1)/(double)x)*coeff(x-2,0));
            }
            else
            {
                if (i>= x-1)
                {
                    return (((2*((double)x-1)+1)/(double)x)* coeff(x-1,i-1));
                }
                else
                {
                    return (((2*((double)x-1)+1)/x)* coeff(x-1,i-1)+(-((double)x-1)/(double)x)*coeff(x-2,i));
                }
            }
        }
    }
}

double ** coeff_legendre (unsigned int n )  // Tested OK 2.0
{
    double ** a= creer_mat_diago(n+1);
    unsigned int  x,i;
    a[0][0] = 1;
    a[1][0]= 0 ;
    for (x=2; x<=n; x++ )
    {
        for (i=0; i<=x; i++)
        {
             if (i==0)
            {
                a[x][i]=-((double)x-1)/((double)x) *a[x-2][0];
            }
            else {
                if (i>= x-1){
                    a[x][i]=((2*((double)x-1)+1)/(double)x)* a[x-1][i-1];
                }
                else {
                     a[x][i]=((2*((double)x-1)+1)/x)* a[x-1][i-1] +(-((double)x-1)/(double)x)*a[x-2][i];
                }
            }
        }
    }
    return a;
}
double Pn(double x, unsigned int n){
    if(n==0){
        return 1;
    }else if(n==1){
        return x ;
    }else{
        return (double)((2*n-1)*x*Pn(x,n-1)-(n-1)*Pn(x,n-2))/n;
    }
}

double P(double x,unsigned int  n, double ** co )  // OK OK 2.0
{
    unsigned int i ;
    double poly =0.00;

    for (i=0; i<=n; i++)
    {
        poly+= co[n][i]*pow(x,i);
    }
    return poly;
}
double Norm_Const(unsigned int  p, unsigned int  q)
{
    double C;
    C=(2*p + 1)*(2*q + 1)/(4.);

    return C;
}
double Moment_Leg (BmpImg img,unsigned int  p,unsigned int  q, unsigned int  n , double ** co , double ** momg)  // Tested OK
{
    unsigned int  i,j;
    double res=0.00;
    double c = Norm_Const(p, q);


    for (i=0 ; i<=p ; i++){
        for (j=0 ; j<=q; j++ ){
                 printf("debut moment leg \n");
            res += co[p][i]*co[q][j] * momg[i][j]   ;
                printf("debut fin leg \n");
        }
    }
    res*= c ;
    return res ;
}
double ** Moments_Legendre (BmpImg img, unsigned int  n, double ** momg ) // Tested OK
{
    double ** mat = creer_mat_anti_diag(n);
    double ** co= coeff_legendre(n);
    unsigned int  p,q;

    for (p=0 ; p<n ; p++ ){
        for (q=0 ; q<n-p;q++){

            mat[p][q]=Moment_Leg (img, p,q,n,co,momg);


        }
    }
    return mat ;
}
void ecrire_mom (char * filename , Moments mom  ) // Tested OK
{
unsigned int  i , j;
FILE * fichier = fopen (filename,"w");
if ( fichier != NULL ) {
    fprintf(fichier , "%d \n" , mom.n);
    fprintf(fichier , "Moments geometrique centres, normes : \n");
    for (i=0 ; i< mom.n  ; i++ ){
        for (j=0 ; j<mom.n-i ; j++){
            fprintf(fichier , "%f " , mom.centres_norm[i][j]);
        }
        fprintf(fichier, "\n");
    }
     fprintf(fichier , "Moments de Legendre : \n");
    for (i=0 ; i< mom.n ; i++ ){
        for (j=0 ; j<mom.n-i ; j++){
            fprintf(fichier , "%f " , mom.leg[i][j]);
        }
        fprintf(fichier, "\n");
    }
}
else {printf("Error Opening File Please Fix the problem and retry \n");}
fclose(fichier);
}

Moments lire_moments (char * filename ){
unsigned int  i , j;
unsigned int  n ;
Moments mom ;
FILE * fichier = fopen (filename,"r");
if ( fichier != NULL ) {
fscanf(fichier , "%d \n" , &n);
mom = creer_moments(n);
fscanf(fichier , "Moments geometrique centres, normes : \n");
for (i=0 ; i< n ; i++ ){
    for (j=0 ; j<n-i ; j++){
        fscanf(fichier , "%lf" , &mom.centres_norm[i][j]);
    }
    fscanf(fichier, "\n");
    }
fscanf(fichier , "Moments de Legendre : \n");
for (i=0 ; i< n ; i++ ){
    for (j=0 ; j< n-i ; j++){
        fscanf(fichier , "%lf" , &mom.leg[i][j]);
    }
    fscanf(fichier, "\n");
    }

}
else {printf("Error Opening File Please Fix the problem and retry \n");
fclose (fichier);
}
return mom  ;

}
void afficher_moments (Moments mom ){
    unsigned int i,j;
    printf("Moments geometrique centres, normes : \n");
    for ( i = 0 ; i<mom.n ; i++ ){
        for ( j =0;j<mom.n-i ; j++){
            printf("%lf " ,mom.centres_norm[i][j]);
        }
        printf("\n");
}
printf("Moments de Legendre : \n");
    for ( i = 0 ; i<mom.n ; i++ ){
        for ( j =0;j<mom.n-i ; j++){
            printf("%lf " ,mom.leg[i][j]);
        }
        printf("\n");
}

}




/*
double ** lire_moments_centre_norme(char * filename,int * n  ){ // Tested OK
int i , j;
FILE * fichier = fopen (filename,"r");
if ( fichier != NULL ) {
fscanf(fichier , "%d \n" , n);
double ** mat = creer_mat_anti_diag(*n);
fscanf(fichier , "Moments geometrique centres, normes : \n");
for (i=0 ; i< *n ; i++ ){
    for (j=0 ; j<*n-i ; j++){
        fscanf(fichier , "%lf" , &mat[i][j]);
    }
    fscanf(fichier, "\n");
    }
return mat ;
}
else {printf("Error Opening File Please Fix the problem and retry");
fclose (fichier);


return NULL ;
}
}

double ** lire_moments_legendre(char * filename,int * n  ){ // Tested OK
int i , j;
FILE * fichier = fopen (filename,"r");
if ( fichier != NULL ) {
fscanf(fichier , "%d \n" , n);
double ** mat = creer_mat_anti_diag(*n);
fscanf(fichier , "Moments de Legendre : \n");
for (i=0 ; i< *n ; i++ ){
    for (j=0 ; j<*n-i ; j++){
        fscanf(fichier , "%lf" , &mat[i][j]);
    }
    fscanf(fichier, "\n");
    }
return mat ;
}
else {printf("Error Opening File Please Fix the problem and retry");
fclose (fichier);


return NULL ;
}
}
*/

