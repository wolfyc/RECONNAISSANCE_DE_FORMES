#include "legendre.h"

double coeff (int x, int i)  // Tested OK 2.0
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

double ** coeff_legendre (int n )  // Tested OK 2.0
{
    double ** a= creer_mat_diago(n+1);
    int x,i;
    for (x=0; x<=n; x++ )
    {
        for (i=0; i<=x; i++)
        {
            a[x][i]=coeff(x,i);
            printf("%f \t", a[x][i]);
        }
        printf("\n");
    }
    return a;
}

double P(double x,int n )  // OK OK 2.0
{
    int i ;
    double poly =0.00;
    double ** a= coeff_legendre ( n );
    printf("ok all ");
    for (i=0; i<=n; i++)
    {
        poly+= a[n][i]*pow(x,i);
        printf("%f \n", poly);
    }
    return poly;
}
double Norm_Const(int p, int q)
{
    double C;
    C=(2*p + 1)*(2*q + 1)/(4.);

    return C;
}
double Moment_Leg (BmpImg img,int p,int q, int n )  // Tested OK
{
    int i,j;
    double res=0.00;
    double c = Norm_Const(p, q);
    for (i=0 ; i<=p ; i++){
        for (j=0 ; j<=q; j++ ){
            res += coeff (p,i)*coeff (q,j)*mom_geo_centre (img,i, j, n)   ;
        }
    }
    res*= c ;
    return res ;
}
double ** Moments_Legendre (BmpImg img, int n ) // Tested OK 
{
    double ** mat = creer_mat_anti_diag(n);
    int p,q;
    for (p=0 ; p<n ; p++ ){
        for (q=0 ; q<n-p;q++){
            mat[p][q]=Moment_Leg (img, p,q,n);
        }
    }
    return mat ;
}
void ecrire_mom (char * filename ,double ** moments ,int n ) // Tested OK
{
int i , j;
FILE * fichier = fopen (filename,"w");
if ( fichier != NULL ) {
    fprintf(fichier , "%d \n" , n);
    for (i=0 ; i< n ; i++ ){
        for (j=0 ; j<n-i ; j++){
            fprintf(fichier , "%f " , moments[i][j]);
        }
        fprintf(fichier, "\n");
    }
}
else {printf("Error Opening File Please Fix the problem and retry");} 
fclose(fichier);
}

double ** lire_moments(char * filename ){ // Tested OK 
int n, i , j;
FILE * fichier = fopen (filename,"r");
if ( fichier != NULL ) {
fscanf(fichier , "%d \n" , &n);
double ** mat = creer_mat_anti_diag(n);
float tmp ; // Does not work without this temporary Variable
for (i=0 ; i< n ; i++ ){
    for (j=0 ; j<n-i ; j++){
        fscanf(fichier , "%f" , &tmp);
        mat[i][j]=tmp;
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

double Dist_Euc (double ** mat1 , double **mat2 , int n ) {  // tested with moments calculated from same image 
                                                             //except that one of them is saved and red (in/from) a file 
int p,q;                                                     // Result was 0.000004 Due to the use of the tmp variable 
double res = 0.00 ;                                          // in the function <lire_moments>
    for (p=0 ; p<n ; p++ ){
        for (q=0 ; q<n-p;q++){
            res+= pow(mat1[p][q]-mat2[p][q],2);
        }
    }
res = sqrt (res);

return res;
}
