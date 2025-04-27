/*Encontrar elementos comunes entre dos matrices*/


#include <stdio.h>

void buscarComunes(int filas1, int columnas1, int arreglo1[filas1][columnas1], int filas2, int columnas2, int arreglo2[filas2][columnas2])
{
    int comunes[filas1 * columnas1]; // Arreglo para almacenar los elementos comunes
    int contador = 0;

    // Recorrer ambos arreglos para buscar elementos comunes
    for (int i = 0; i < filas1; i++)
    {
        for (int j = 0; j < columnas1; j++)
        {
            for (int k = 0; k < filas2; k++)
            {
                for (int l = 0; l < columnas2; l++)
                {
                    if (arreglo1[i][j] == arreglo2[k][l])
                    {
                        comunes[contador] = arreglo1[i][j];
                        contador++;
                        break;
                    }
                }
            }
        }
    }

    // Mostrar los elementos comunes
    printf("Elementos comunes: ");
    for (int i = 0; i < contador; i++)
    {
        printf("%d ", comunes[i]);
    }
    printf("\n");
}

int main()
{
    // Dos arreglos multidimensionales
    int arreglo1[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int arreglo2[3][2] = {{3, 4}, {7, 8}, {1, 9}};

    // Llamada al algoritmo
    buscarComunes(2, 3, arreglo1, 3, 2, arreglo2);
    return 0;
}