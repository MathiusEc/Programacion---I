/* Realizar un algoritmo donde se ingresen el nombre de 4 equipos, de ahi calcular  el cuadrangular final (6 partidos)
 se debe registar la cantidad de goles, el gol diferencia, y los 2 finalistas*/

#include <stdio.h>
#include <string.h>

#define NUM_EQUIPOS 4

void ingresarEquipos(char equipos[NUM_EQUIPOS][30]);
void ingresarResultados (char equipos[NUM_EQUIPOS][30], int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS], int puntos[NUM_EQUIPOS]);
void diferenciaGoles (int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS], int diferencia_goles[NUM_EQUIPOS]);
void ordenarEquipos (int diferencia_goles[NUM_EQUIPOS], int puntos[NUM_EQUIPOS], char equipos[NUM_EQUIPOS][30], int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS]);
void tabla(char equipos[NUM_EQUIPOS][30], int puntos[NUM_EQUIPOS], int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS], int diferencia_goles[NUM_EQUIPOS]);


int main()
{
    char equipos[NUM_EQUIPOS][30], temp_nombre[30];
    int puntos[NUM_EQUIPOS] = {0};
    int goles_favor[NUM_EQUIPOS] = {0};
    int goles_contra[NUM_EQUIPOS] = {0};
    int diferencia_goles[NUM_EQUIPOS] = {0};
    int goles1, goles2, len, val;

    ingresarEquipos(equipos);
    printf("\n");

    ingresarResultados(equipos, goles_favor, goles_contra, puntos);
    printf("\n");

    diferenciaGoles(goles_favor, goles_contra, diferencia_goles);
    printf("\n");

    ordenarEquipos(diferencia_goles, puntos, equipos, goles_favor, goles_contra);
    printf("\n");

    tabla(equipos, puntos, goles_favor, goles_contra, diferencia_goles);
    printf("\n");
    return 0;
}


void ingresarEquipos(char equipos[NUM_EQUIPOS][30])
{
    int len;
    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        printf("Ingrese el nombre del equipo %d: ", i);
        fflush(stdin);
        fgets(equipos[i], 30, stdin);
        len = strlen(equipos[i]) - 1;
        equipos[i][len] = '\0';

        if (strlen(equipos[i]) == 0)
        {
            printf("Error: Nombre de equipo no puede estar vacío. Inténtelo de nuevo.\n");
            i--;
        }
    }
}

void ingresarResultados (char equipos[NUM_EQUIPOS][30], int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS], int puntos[NUM_EQUIPOS])
{
    int goles1, goles2, val;

    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        for (int j = i + 1; j < NUM_EQUIPOS; j++)
        {
            printf("Ingrese los goles de %s contra %s: \n", equipos[i], equipos[j]);
            do
            {
                fflush(stdin);
                printf(">>");
                val = scanf("%d", &goles1);

                if (val != 1 || goles1 < 0)
                {
                    printf("Error: Ingrese valores numéricos válidos (mayores o iguales a 0).\n");
                }

                fflush(stdin);
                printf(">>");
                val = scanf("%d", &goles2);

                if (val != 1 || goles2 < 0)
                {
                    printf("Error: Ingrese valores numéricos válidos (mayores o iguales a 0).\n");
                }

                goles_favor[i] += goles1;
                goles_contra[i] += goles2;
                goles_favor[j] += goles2;
                goles_contra[j] += goles1;

                if (goles1 > goles2)
                {
                    puntos[i] += 3;
                }
                else if (goles1 < goles2)
                {
                    puntos[j] += 3;
                }
                else
                {
                    puntos[i] += 1;
                    puntos[j] += 1;
                }
            } while (goles1 < 0 || goles2 < 0 || val != 1);
        }
    }

}

void diferenciaGoles (int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS], int diferencia_goles[NUM_EQUIPOS])
{
    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        diferencia_goles[i] = goles_favor[i] - goles_contra[i];
    }
}

void ordenarEquipos (int diferencia_goles[NUM_EQUIPOS], int puntos[NUM_EQUIPOS], char equipos[NUM_EQUIPOS][30], int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS])
{
    char temp_nombre[30];
    for (int i = 0; i < NUM_EQUIPOS - 1; i++)
    {
        for (int j = i + 1; j < NUM_EQUIPOS; j++)
        {
            if (puntos[j] > puntos[i] || (puntos[j] == puntos[i] && diferencia_goles[j] > diferencia_goles[i]))
            {
                // Ordenamiento por burbuja
                int temp_puntos = puntos[i];
                puntos[i] = puntos[j];
                puntos[j] = temp_puntos;

                int temp_goles_favor = goles_favor[i];
                goles_favor[i] = goles_favor[j];
                goles_favor[j] = temp_goles_favor;
                int temp_goles_contra = goles_contra[i];
                goles_contra[i] = goles_contra[j];
                goles_contra[j] = temp_goles_contra;

                int temp_diferencia = diferencia_goles[i];
                diferencia_goles[i] = diferencia_goles[j];
                diferencia_goles[j] = temp_diferencia;

                strcpy(temp_nombre, equipos[i]);
                int k;
                for (k = 0; k < 30; k++)
                {
                    equipos[i][k] = equipos[j][k];
                }
                for (k = 0; k < 30; k++)
                {
                    equipos[j][k] = temp_nombre[k];
                }
            }
        }
    }
}

void tabla(char equipos[NUM_EQUIPOS][30], int puntos[NUM_EQUIPOS], int goles_favor[NUM_EQUIPOS], int goles_contra[NUM_EQUIPOS], int diferencia_goles[NUM_EQUIPOS])
{
    printf("\nTabla de posiciones:\n");
    printf("Equipo\tPuntos\tGF\tGC\tDG\n");
    for (int i = 0; i < NUM_EQUIPOS; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n", equipos[i], puntos[i], goles_favor[i], goles_contra[i], diferencia_goles[i]);
    }

    printf("\nLos equipos que jugarán la final son:\n1. %s\n2. %s\n", equipos[0], equipos[1]);
}