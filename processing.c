#include "processing.h"

mat_data ** Vander_monde (int dim,int pow_max){
mat_data **van_m = calloc(dim,sizeof(mat_data*));
for (i=0;i<dim;i++){
    van_m[i]=calloc(dim,sizeof(mat_data));
}
for (i=0;i<dim;i++){
    for (j=0;j<pow_max;j++){
        van_m[i][j]=pow(i,j);
    }
}
return van_m;
}
