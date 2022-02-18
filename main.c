//
// Created by Severin on 18.02.2022.
//

#include "stdio.h"
#include "stdlib.h"

#include "matrix.h"

int main(){

    //////////////////
    /// File staff ///
    //////////////////

    // Creating and opening files

    FILE *A, *B, *C;
    A = fopen("data1.dat", "r");
    B = fopen("data2.dat", "r");
    C = fopen("result.dat", "w+");

    if (A == NULL){
        printf("Error: file data1.dat doesn't exist.");
        exit(1);
    }

    if (B == NULL){
        printf("Error: file data2.dat doesn't exist.");
        exit(1);
    }

    // Checking for right formatting

    char a = getc(A);
    char b = getc(B);

    if(a != '#'){
        printf("Error: file data1.dat in wrong format.");
        exit(1);
    }

    if(b != '#'){
        printf("Error: file data2.dat in wrong format.");
        exit(1);
    }

    // Checking for same size

    int n_a, n_b, n;

    fscanf(A, "%d", &n_a);
    fscanf(B, "%d", &n_b);

    if (n_a != n_b){
        printf("Error: file matrices from data1.dat and data2.dat are not multiplicable");
    } else {
        n = n_a;
    }

    // Allocating memory for matrices

    double *matrix_A = malloc(sizeof(double) * n * n);
    double *matrix_B = malloc(sizeof(double) * n * n);
    double *matrix_C = malloc(sizeof(double) * n * n);

    if (matrix_A == NULL){
        printf("Error reallocating space for matrix A.");
        exit(1);
    }

    if (matrix_B == NULL){
        printf("Error reallocating space for matrix B.");
        exit(1);
    }

    if (matrix_C == NULL){
        printf("Error reallocating space for matrix C.");
        exit(1);
    }

    // Finally reading

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(A, "%lf", &matrix_A[j + n * i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            fscanf(B, "%lf", &matrix_B[j + n * i]);
        }
    }

    ///////////////////
    /// Multiplying ///
    ///////////////////

    if(optimised_stupid_multiply(matrix_A, matrix_B, matrix_C, n) == 1){
        printf("Error occur during multiplication. Exiting...");
        exit(1);
    }

    ///////////////////////
    /// More file staff ///
    ///////////////////////

    fprintf(C, "# %d", n);

    for (int i = 0; i < n; ++i) {
        fprintf(C, "\n");

        for (int j = 0; j < n; ++j) {
            fprintf(C, "%lf ", matrix_C[j + n * i]);
        }
    }

    fclose(A);
    fclose(B);
    fclose(C);

    return 0;
}
