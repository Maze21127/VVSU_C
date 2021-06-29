#include <malloc.h>

double **add(double **first, double **second, int n){
    double **result = (double **) malloc(n * sizeof(double *));
    for(int i = 0; i < n; i++) {
      result[i] = (double *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
          result[i][j] = first[i][j] + second[i][j];
        }
    }
    return result;
}

double **diff(double **first, double **second, int n){
    double **result = (double **) malloc(n * sizeof(double *));
    for(int i = 0; i < n; i++) {
      result[i] = (double *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
          result[i][j] = first[i][j] - second[i][j];
        }
    }
    return result;
}

double **mul(double **first, double **second, int n){
    double **result = (double **) malloc(n * sizeof(double *));
    for(int i = 0; i < n; i++) {
      result[i] = (double *)malloc(n * sizeof(int));
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result[i][j]=0;
            for(int k = 0; k < n; k++) {
              result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    return result;
}
