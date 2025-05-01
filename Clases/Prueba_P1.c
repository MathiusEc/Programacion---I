/*Prueba*/
/*Se desea desarrolar un programam que me permita conocer el ganador de un torneo de box con 6 participantes, la prijera etapa son llaves preestablecidad,

La segunda etapa sera la final entre aquellos que alcanzen los 2 mejores puntajes

los úntos se asignan asi: ganador 1 punto, por KO por 3 puntos

Ingreasr nombres de competidores y validar entradas*/

#include <stdio.h>
#include <string.h>

#define MAX_COMPETIDORES 6
#define llaves 3

void ingresarNombres(char nombres[][30], int n);
void resultados(char nombres[MAX_COMPETIDORES][30], int ganador[llaves], int sigRonda[MAX_COMPETIDORES]);
void finalistas(char nombres[MAX_COMPETIDORES][30], int sigRonda[MAX_COMPETIDORES], int ganador[llaves]);
void granFinal(char nombres[MAX_COMPETIDORES][30], int ganador[llaves]);

int main(int argc, char *argv[])
{
    char nombres[MAX_COMPETIDORES][30];
    int ganador[llaves] = {1, 2, 3};
    int sigRonda[MAX_COMPETIDORES] = {0};

    ingresarNombres(nombres, MAX_COMPETIDORES);
    printf("\n");
    resultados(nombres, ganador, sigRonda);
    printf("\n");
    finalistas(nombres, sigRonda, ganador);
    printf("\n");
    granFinal(nombres, ganador);
    return 0;
}

void ingresarNombres(char nombres[][30], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre del competidor %d: ", i);
        fflush(stdin);
        fgets(nombres[i], 30, stdin);
        int len = strlen(nombres[i]) - 1;
        nombres[i][len] = '\0'; // Eliminar el salto de línea

        if (strlen(nombres[i]) == 0)
        {
            printf("Error: Nombre de competidor no puede estar vacío. Inténtelo de nuevo.\n");
            i--; // Decrementar i para repetir la entrada
        }
    }
}

void resultados(char nombres[MAX_COMPETIDORES][30], int ganador[llaves], int sigRonda[MAX_COMPETIDORES])
{
    int puntos, opc, val;
    int resu;

    printf("Ingrese quien gano %s entre %s\n", nombres[0], nombres[1]);
    printf("1. Para %s\n", nombres[0]);
    printf("2. Para %s\n", nombres[1]);
    printf(">> ");
    scanf("%d", &resu);

    if (resu == 1)
    {
        printf("Fue por KO?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            sigRonda[0] = 3;
        }
        else
        {
            sigRonda[0] = 1;
        }
    }
    else if (resu == 2)
    {
        printf("Fue por KO?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            sigRonda[1] = 3;
        }
        else
        {
            sigRonda[1] = 1;
        }
    }

    printf("Ingrese quien gano %s entre %s\n", nombres[2], nombres[3]);
    printf("1. Para %s\n", nombres[2]);
    printf("2. Para %s\n", nombres[3]);
    printf(">> ");
    scanf("%d", &resu);

    if (resu == 1)
    {
        printf("Fue por KO?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            sigRonda[2] = 3;
        }
        else
        {
            sigRonda[2] = 1;
        }
    }
    else if (resu == 2)
    {
        printf("Fue por KO?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            sigRonda[3] = 3;
        }
        else
        {
            sigRonda[3] = 1;
        }
    }

    printf("Ingrese quien gano %s entre %s\n", nombres[4], nombres[5]);
    printf("1. Para %s\n", nombres[4]);
    printf("2. Para %s\n", nombres[5]);
    printf(">> ");
    scanf("%d", &resu);

    if (resu == 1)
    {
        printf("Fue por KO?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            sigRonda[4] = 3;
        }
        else
        {
            sigRonda[4] = 1;
        }
    }
    else if (resu == 2)
    {
        printf("Fue por KO?\n");
        printf("1. Si\n");
        printf("2. No\n");
        printf(">> ");
        scanf("%d", &opc);
        if (opc == 1)
        {
            sigRonda[5] = 3;
        }
        else
        {
            sigRonda[5] = 1;
        }
    }
}

void finalistas(char nombres[MAX_COMPETIDORES][30], int sigRonda[MAX_COMPETIDORES], int ganador[llaves])
{
    // Asignamos los ganadores de cada llave
    for (int i = 0; i < llaves; i++)
    {
        if (sigRonda[i * 2] > sigRonda[i * 2 + 1])
        {
            ganador[i] = i * 2;
        }
        else
        {
            ganador[i] = i * 2 + 1;
        }
    }

    // Ordenamos los finalistas por puntos y en caso de empate, por el orden de la llave
    for (int i = 0; i < llaves - 1; i++)
    {
        for (int j = 0; j < llaves - i - 1; j++)
        {
            int idx1 = ganador[j];
            int idx2 = ganador[j + 1];

            if (sigRonda[idx1] < sigRonda[idx2] || 
               (sigRonda[idx1] == sigRonda[idx2] && ganador[j] < ganador[j + 1])) 
            {
                int temp = ganador[j];
                ganador[j] = ganador[j + 1];
                ganador[j + 1] = temp;
            }
        }
    }

    // Mostramos los finalistas
    printf("Los finalistas son:\n");
    printf("1. %s con %d puntos (Llave %d)\n", nombres[ganador[0]], sigRonda[ganador[0]], ganador[0] / 2 + 1);
    printf("2. %s con %d puntos (Llave %d)\n", nombres[ganador[1]], sigRonda[ganador[1]], ganador[1] / 2 + 1);
}

void granFinal(char nombres[MAX_COMPETIDORES][30], int ganador[llaves])
{
    int resu;
    int finalista1 = ganador[0];
    int finalista2 = ganador[1];

    do
    {
        printf("Ingrese quien ganó entre %s y %s\n", nombres[finalista1], nombres[finalista2]);
        printf("1. Para %s\n", nombres[finalista1]);
        printf("2. Para %s\n", nombres[finalista2]);
        printf(">> ");
        scanf("%d", &resu);

        if (resu != 1 && resu != 2)
        {
            printf("Entrada no válida. Intente de nuevo.\n");
        }
    } while (resu != 1 && resu != 2);

    if (resu == 1)
    {
        printf("¡Felicidades %s, ganaste el torneo!\n", nombres[finalista1]);
    }
    else
    {
        printf("¡Felicidades %s, ganaste el torneo!\n", nombres[finalista2]);
    }
}    