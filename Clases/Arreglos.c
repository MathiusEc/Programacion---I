#include <stdio.h>
#include <string.h>

/*
1. Suma de vectores
2. Suma de matrices
3. Mult. de matrices (Deber)

*/

int main(int argc, char *argv[])
{

    // Vectores
    printf("Suma de vectores");
    int a[10];
    int b[10] = {9, 5, 6, 7, 4, 3, -4, 5, -7, 7};
    int sum;
    int sum2;

    for (int i = 0; i < 10; i++)
    {
        a[i] = 2;
    }

    for (int i = 0; i < 10; i++)
    {
        sum = a[i] + b[i];
        printf(" \n %d", sum);
    }

    // Matrices
    printf("\n\nSuma de matrices\n");
    int c[3][2];
    int d[3][2] = {{3, 4}, {-1, 5}, {-7, 5}};

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            c[j][k] = 1;
        }
    }

    for (int j = 0; j < 3; j++)
    {
        for (int k = 0; k < 2; k++)
        {
            sum2 = c[j][k] + d[j][k];
            printf("%d\t", sum2);
        }
        printf("\n");
    }

    // Multiplicacion de matrices
    printf("\n\nMultiplicacion de matrices\n");

    int e[3][3];
    int f[3][3] = {{3, 4, 2}, {-1, 5, 26}, {-7, 5, 6}};
    int mult[3][3];

    for (int m = 0; m < 3; m++)
    {
        for (int n = 0; n < 3; n++)
        {
            e[m][n] = 1;
        }
    }
    
    for (int o = 0; o < 3; o++)
    {
        for (int p = 0; p < 3; p++)
        {
            mult[o][p] = 0;
            for (int q = 0; q < 3; q++)
            {
                mult[o][p] += e[o][q] * f[q][p];
            }
            printf("%d\t", mult[o][p]);
        }
        printf("\n");
    }

    return 0;
}