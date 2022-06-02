#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

#include <chrono>
#include <string>

// Aqui defino el tamano del arreglo maximo
#define SIZE 32

using namespace std;

void ReadMatrix(double **, int);
void WriteMatrix(double **, int);

void MatrixAdd(double **A, double **B, double **Result, int N);
void MatrixSubtrac(double **A, double **B, double **Result, int N);

void StrassenAlgorithm(double **A, double **B, double **C, int N);

// Leyendo datos de la matriz con datos aleatorios
void ReadMatrix(double A[][SIZE], int N)
{
    for (auto i = 0; i < N; ++i)
    {
        for (auto j = 0; j < N; ++j)
        {
            A[i][j] = rand() % 5;
        }
    }
}

// Imprimiendo la matriz
void WriteMatrix(double A[][SIZE], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%0.1lf \t", A[i][j]);
        }
        printf("\n");
    }
}

// Anadiendo dos matrices cuadradas
void MatrixAdd(double A[][SIZE], double B[][SIZE], double Result[][SIZE], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            Result[i][j] = A[i][j] + B[i][j];
        }
    }
}

/*Función que resta una matriz cuadrada de otra*/
void MatrixSubtrac(double A[][SIZE], double B[][SIZE], double Result[][SIZE], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            Result[i][j] = A[i][j] - B[i][j];
        }
    }
}

/* Algoritmo Strassen. (Divide y Conquista)*/
void StrassenAlgorithm(double A[][SIZE], double B[][SIZE], double C[][SIZE], int N)
{
    if (N == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int Divide = (int)(N / 2);

        double A11[SIZE][SIZE], A12[SIZE][SIZE], A21[SIZE][SIZE], A22[SIZE][SIZE];
        double B11[SIZE][SIZE], B12[SIZE][SIZE], B21[SIZE][SIZE], B22[SIZE][SIZE];
        double C11[SIZE][SIZE], C12[SIZE][SIZE], C21[SIZE][SIZE], C22[SIZE][SIZE];
        double P1[SIZE][SIZE], P2[SIZE][SIZE], P3[SIZE][SIZE], P4[SIZE][SIZE], P5[SIZE][SIZE], P6[SIZE][SIZE], P7[SIZE][SIZE];
        double AResult[SIZE][SIZE], BResult[SIZE][SIZE];

        int i, j;
        for (i = 0; i < Divide; i++)
        {
            for (j = 0; j < Divide; j++)
            {
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + Divide];
                A21[i][j] = A[i + Divide][j];
                A22[i][j] = A[i + Divide][j + Divide];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + Divide];
                B21[i][j] = B[i + Divide][j];
                B22[i][j] = B[i + Divide][j + Divide];
            }
        }

        MatrixAdd(A11, A22, AResult, Divide);
        MatrixAdd(B11, B22, BResult, Divide);
        StrassenAlgorithm(AResult, BResult, P1, Divide);

        MatrixAdd(A21, A22, AResult, Divide);
        StrassenAlgorithm(AResult, B11, P2, Divide);

        MatrixSubtrac(B12, B22, BResult, Divide);
        StrassenAlgorithm(A11, BResult, P3, Divide);

        MatrixSubtrac(B21, B11, BResult, Divide);
        StrassenAlgorithm(A22, BResult, P4, Divide);

        MatrixAdd(A11, A12, AResult, Divide);
        StrassenAlgorithm(AResult, B22, P5, Divide);

        MatrixSubtrac(A21, A11, AResult, Divide);
        MatrixAdd(B11, B12, BResult, Divide);
        StrassenAlgorithm(AResult, BResult, P6, Divide);

        MatrixSubtrac(A12, A22, AResult, Divide);
        MatrixAdd(B21, B22, BResult, Divide);
        StrassenAlgorithm(AResult, BResult, P7, Divide);

        MatrixAdd(P3, P5, C12, Divide);
        MatrixAdd(P2, P4, C21, Divide);

        MatrixAdd(P1, P4, AResult, Divide);
        MatrixAdd(AResult, P7, BResult, Divide);
        MatrixSubtrac(BResult, P5, C11, Divide);

        MatrixAdd(P1, P3, AResult, Divide);
        MatrixAdd(AResult, P6, BResult, Divide);
        MatrixSubtrac(BResult, P2, C22, Divide);

        for (i = 0; i < Divide; i++)
        {
            for (j = 0; j < Divide; j++)
            {
                C[i][j] = C11[i][j];
                C[i][j + Divide] = C12[i][j];
                C[i + Divide][j] = C21[i][j];
                C[i + Divide][j + Divide] = C22[i][j];
            }
        }
    }
}

int main()
{
    double A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
    int i, j;
    int N, M, Count = 0;

    printf("Dimension: ");
    scanf("%d", &N);

    M = N;

    printf("Matrix A:\n");
    ReadMatrix(A, M);
    printf("Matrix B:\n");
    ReadMatrix(B, M);

    if (M > 1)
    {

        while (M >= 2)
        {
            M /= 2;
            Count++;
        }

        M = N;

        if (M != (pow(2.0, Count)))
        {
            N = pow(2.0, Count + 1);

            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    if ((i >= M) || (j >= M))
                    {
                        A[i][j] = 0.0;
                        B[i][j] = 0.0;
                    }
                }
            }
        }
    }

    auto beginMultiplyStraseen = chrono::high_resolution_clock::now();
    StrassenAlgorithm(A, B, C, N);
    auto endMultiplyStraseen = chrono::high_resolution_clock::now();
    auto MultiplyStraseenElapsed = chrono::duration_cast<chrono::microseconds>(endMultiplyStraseen - beginMultiplyStraseen);

    printf("Matris A:\n\n");
    WriteMatrix(A, M);
    printf("Matris B:\n\n");
    WriteMatrix(B, M);
    printf("Producto de las dos matrices:\n\n");
    WriteMatrix(C, M);

    cout << "MultiplyStraseen Sort: " + to_string(MultiplyStraseenElapsed.count()) + " microsegundos." << endl;

    return 0;
}