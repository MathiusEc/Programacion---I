/*
Ser desea desarrollar un programa para gestionar citas en una peluquería canina donde se tendran las siguientes opciones:
1. Registrar cita
2. Buscar por fecha
3. Buscar por cliente
4. Listar citas
Desea otra opción 1 por sí, 2 por no
Dentro de la cita se registra nombre del cliente, fecha (dd/mm/yy)

*/

#include <stdio.h>
#include <string.h>

void registrarCita(char citas[5][30], char clientes[5][30], char fechas[5][11], int *ubicacion)
{
    int duplicado, len;

    if (*ubicacion >= 5)
    {
        printf("No se pueden registrar más de 5 citas.\n");
        return;
    }

    do
    {
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        fgets(clientes[*ubicacion], 30, stdin);
        len = strlen(clientes[*ubicacion]) - 1;
        if (len >= 0 && clientes[*ubicacion][len] == '\n')
        {
            clientes[*ubicacion][len] = '\0'; // Eliminar el salto de línea
        }

        printf("Ingrese la fecha de la cita (dd/mm/yy): ");
        fflush(stdin);
        fgets(fechas[*ubicacion], 11, stdin);
        len = strlen(fechas[*ubicacion]) - 1;
        if (len >= 0 && fechas[*ubicacion][len] == '\n')
        {
            fechas[*ubicacion][len] = '\0'; // Eliminar el salto de línea
        }

        duplicado = 0;
        for (int i = 0; i < *ubicacion; i++)
        {
            if (strcmp(fechas[i], fechas[*ubicacion]) == 0 && strcmp(clientes[i], clientes[*ubicacion]) == 0)
            {
                duplicado = 1;
                printf("Este cliente ya tiene una cita en esta fecha. Por favor, ingrese otra combinación.\n");
            }
        }
    } while (duplicado == 1);

    printf("Ingrese la descripción de la cita: ");
    fflush(stdin);
    fgets(citas[*ubicacion], 30, stdin);
    len = strlen(citas[*ubicacion]) - 1;
    if (len >= 0 && citas[*ubicacion][len] == '\n')
    {
        citas[*ubicacion][len] = '\0';
    }

    (*ubicacion)++;
}

void buscarPorFecha(char citas[5][30], char clientes[5][30], char fechas[5][11], int ubicacion)
{
    char fechaBuscar[11];
    int encontrado = 0;

    printf("Ingrese la fecha a buscar (dd/mm/yy): ");
    fflush(stdin);
    fgets(fechaBuscar, 11, stdin);
    int len = strlen(fechaBuscar) - 1;
    if (len >= 0 && fechaBuscar[len] == '\n')
    {
        fechaBuscar[len] = '\0'; // Eliminar el salto de línea
    }

    for (int i = 0; i < ubicacion; i++)
    {
        if (strcmp(fechas[i], fechaBuscar) == 0)
        {
            printf("Cita encontrada: Cliente: %s, Fecha: %s, Descripción: %s\n", clientes[i], fechas[i], citas[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("No se encontraron citas para la fecha %s.\n", fechaBuscar);
    }
}

void buscarPorCliente(char citas[5][30], char clientes[5][30], char fechas[5][11], int ubicacion)
{
    char clienteBuscar[30];
    int encontrado = 0;

    printf("Ingrese el nombre del cliente a buscar: ");
    fflush(stdin);
    fgets(clienteBuscar, 30, stdin);
    int len = strlen(clienteBuscar) - 1;
    if (len >= 0 && clienteBuscar[len] == '\n')
    {
        clienteBuscar[len] = '\0'; // Eliminar el salto de línea
    }

    for (int i = 0; i < ubicacion; i++)
    {
        if (strcmp(clientes[i], clienteBuscar) == 0)
        {
            printf("Cita encontrada: Cliente: %s, Fecha: %s, Descripción: %s\n", clientes[i], fechas[i], citas[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("No se encontraron citas para el cliente %s.\n", clienteBuscar);
    }
}

int main(int argc, char *argv[])
{
    char citas[5][30];
    char clientes[5][30];
    char fechas[5][11];
    int ubicacion = 0, opc, val, len;

    do
    {
        printf("==================================================\n");
        printf("           SISTEMA DE GESTION DE PELUQUERIA       \n");
        printf("==================================================\n");
        printf("1. Registrar cita\n");
        printf("2. Buscar por fecha\n");
        printf("3. Buscar por cliente\n");
        printf("4. Listar citas\n");
        printf("5. Salir\n");
        printf(">> ");
        val = scanf("%d", &opc);
        if (val != 1)
        {
            printf("Opción inválida.\n");
            fflush(stdin); // Limpiar el buffer de entrada
        }

        switch (opc)
        {
        case 1:
            registrarCita(citas, clientes, fechas, &ubicacion);
            break;
        case 2:
            if (ubicacion == 0)
            {
                printf("No hay citas registradas.\n");
            }
            else
            {
                buscarPorFecha(citas, clientes, fechas, ubicacion);
            }

            break;

        case 3:
            if (ubicacion == 0)
            {
                printf("No hay citas registradas.\n");
            }
            else
            {
                buscarPorCliente(citas, clientes, fechas, ubicacion);
            }

            break;

        case 4:
            if (ubicacion == 0)
            {
                printf("No hay citas registradas.\n");
            }
            else
            {
                printf("\nListado de citas:\n");
                for (int i = 0; i < ubicacion; i++)
                {
                    printf("Cliente: %s | Fecha: %s | Descripción: %s\n", clientes[i], fechas[i], citas[i]);
                }
            }

            break;
        default:
            break;
        }

    } while (val != 1 || opc != 5);

    return 0;
}