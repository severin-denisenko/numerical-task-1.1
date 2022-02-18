//
// Created by Severin on 18.02.2022.
//

#include "matrix.h"
#include "stdio.h"

// Элементарнейшее умножение по определению

int stupid_multiply(double *A, double *B, double *C, int n){

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[j + n * i] = 0;

            for (int k = 0; k < n; ++k) {
                C[j + n * i] += A[k + n * i] * B[j + n * k];
            }
        }
    }

    return 0;
}

// Элементарнейшее умножение по определению с оптимизациями
// Упрощаем вычисление указателя и вместо обхода по строчкам и столбцам, реализуем обход по строчкм
// якобы первая матрица транспонирована.

int optimised_stupid_multiply(double *A, double *B, double *C, int n){

    for (int i = 0; i < n; ++i)
    {
        double *c = C + i * n;

        for (int j = 0; j < n; ++j){
            c[j] = 0;
        }

        for (int k = 0; k < n; ++k)
        {
            const double *b = B + k * n;
            float a = A[i*n + k];

            for (int j = 0; j < n; ++j) {
                c[j] += a * b[j];
            }
        }
    }

    return 0;
}
