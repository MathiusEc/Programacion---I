/* Ejercicio de Formula 1

- Registrar los nombres de los pilotos (validando las entradas).
- Simular carreras y asignar puntos según la posición de llegada.
- Ordenar los pilotos según su puntuación total después de varias carreras.
- Determinar al ganador del torneo según el acumulado de puntos.


----Reglas-----
- Cada piloto compite en varias carreras (por ejemplo, 5 carreras).
- Sistema de puntos basado en la posición de llegada:- 1° lugar = 25 puntos
- 2° lugar = 18 puntos
- 3° lugar = 15 puntos
- 4° lugar = 12 puntos
- 5° lugar = 10 puntos
- 6° lugar = 8 puntos

- El piloto con más puntos al final es el ganador del campeonato.

6 pilotos
5 carreras
*/

#include <stdio.h>
#include <string.h>

#define MAX_COMPETIDORES 6
#define MAX_CARRERAS 5

void ingresarNombres(char nombres[][30]);
void resultados(char nombres[][30], int puntos[]);
void ordenarPilotos(char nombres[][30], int puntos[]);
void mostrarResultados(char nombres[][30], int puntos[]);
int determinarGanador(char nombres[][30], int puntos[]);

int main(int argc, char *argv[])
{
    char pilotos[MAX_COMPETIDORES][30];
    int puntos[MAX_COMPETIDORES] = {0}; // Inicializar puntos en 0

    ingresarNombres(pilotos);

    for (int i = 0; i < MAX_CARRERAS; i++)
    {
        printf("\n--- Carrera %d ---\n", i);
        resultados(pilotos, puntos);
        printf("\n");
    }

    ordenarPilotos(pilotos, puntos);
    mostrarResultados(pilotos, puntos);

    int ganador = determinarGanador(pilotos, puntos);
    printf("\nEl ganador del torneo es: %s con %d puntos\n", pilotos[ganador], puntos[ganador]);

    return 0;
}

void ingresarNombres(char nombres[][30])
{
    for (int i = 0; i < MAX_COMPETIDORES; i++)
    {
        int len;

        printf("Ingrese el nombre del piloto %d: ", i);
        fflush(stdin);
        fgets(nombres[i], 30, stdin);
        len = strlen(nombres[i]) - 1;
        nombres[i][len] = '\0';

        if (strlen(nombres[i]) == 0)
        {
            printf("Error: Nombre de piloto no puede estar vacío. Inténtelo de nuevo.\n");
            i--; // Decrementar i para repetir la entrada
        }
    }
}

void resultados(char nombres[][30], int puntos[])
{
    int posicion[MAX_CARRERAS];
    int ocupada[MAX_COMPETIDORES] = {0};
    int val;

    printf("Ingrese los resultados de las carreras:\n");
    printf("La posición 1 es el primer lugar, 2 el segundo, etc.\n");

    for (int i = 0; i <= MAX_CARRERAS; i++)
    {
        do
        {
            printf("Ingrese la posicion del Piloto: %s\n", nombres[i]);
            printf(">> ");
            fflush(stdin);
            val = scanf("%d", &posicion[i]);

            if (val != 1 || posicion[i] < 1 || posicion[i] > MAX_COMPETIDORES || ocupada[posicion[i] - 1] == 1)
            {
                if (val != 1)
                {
                    fflush(stdin);
                    printf("Error: Entrada no válida. Debe ingresar un número.\n");
                }
                else if (posicion[i] < 1 || posicion[i] > MAX_COMPETIDORES)
                {
                    printf("Error: La posición debe estar entre 1 y %d.\n", MAX_COMPETIDORES);
                }
                else if (ocupada[posicion[i] - 1] == 1)
                {
                    printf("Error: La posición %d ya ha sido ocupada por otro piloto.\n", posicion[i]);
                }
            }

        } while (val != 1 || posicion[i] < 1 || posicion[i] > MAX_COMPETIDORES || ocupada[posicion[i] - 1] == 1);

        ocupada[posicion[i] - 1] = 1;
        if (posicion[i] == 1)
        {
            puntos[i] += 25;
        }
        else if (posicion[i] == 2)
        {
            puntos[i] += 18;
        }
        else if (posicion[i] == 3)
        {
            puntos[i] += 15;
        }
        else if (posicion[i] == 4)
        {
            puntos[i] += 12;
        }
        else if (posicion[i] == 5)
        {
            puntos[i] += 10;
        }
        else if (posicion[i] == 6)
        {
            puntos[i] += 8;
        }
    }
}

void ordenarPilotos(char nombres[][30], int puntos[])
{
    for (int i = 0; i < MAX_COMPETIDORES - 1; i++)
    {
        for (int j = 0; j < MAX_COMPETIDORES - i - 1; j++)
        {
            if (puntos[j] < puntos[j + 1])
            {
                // Intercambiar puntos
                int tempPuntos = puntos[j];
                puntos[j] = puntos[j + 1];
                puntos[j + 1] = tempPuntos;

                // Intercambiar nombres
                char tempNombre[30];
                strcpy(tempNombre, nombres[j]);
                strcpy(nombres[j], nombres[j + 1]);
                strcpy(nombres[j + 1], tempNombre);
            }
        }
    }
}

void mostrarResultados(char nombres[][30], int puntos[])
{
    printf("\n--- Resultados Finales ---\n");
    for (int i = 0; i < MAX_COMPETIDORES; i++)
    {
        printf("%s: %d puntos\n", nombres[i], puntos[i]);
    }
}

int determinarGanador(char nombres[][30], int puntos[])
{
    int indiceGanador = 0;

    for (int i = 1; i < MAX_COMPETIDORES; i++)
    {
        if (puntos[i] > puntos[indiceGanador])
        {
            indiceGanador = i;
        }
    }

    return indiceGanador;
}