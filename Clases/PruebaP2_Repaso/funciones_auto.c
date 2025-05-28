/* Se desea desarrollar un sistema de compra y venta de vehiculos que trenga las siguientas funcionalidades
agregar vehiculo, vender vehiculo, buscar vehiculo por cedula de dueño,
los vehiculos debe tener los siguinetes atributos:
nombre del dueño
cedula del dueño placa
estado si esta vendido o disponible
se debe validar que la placa no se repita*/

#include <stdio.h>
#include <string.h>
#include "funciones_auto.h"

void agregarVehiculo(char vehiculos[5][30], char duenio[5][30], int *ubicacion, char color[5][30], float precio[5])
{
    char placa[30];
    int duplicado, len, val;

    if (*ubicacion >= 5)
    {
        printf("No se pueden agregar mas de 5 vehiculos.\n");
        return;
    }

    do
    {
        printf("Ingrese el nombre del dueño del vehiculo: ");
        fflush(stdin);
        fgets(duenio[*ubicacion], 30, stdin);
        len = strlen(duenio[*ubicacion]) - 1;
        if (len >= 0 && duenio[*ubicacion][len] == '\n')
        {
            duenio[*ubicacion][len] = '\0'; 
        }

        printf("Ingrese la placa del vehiculo: ");
        fflush(stdin);
        fgets(placa, 30, stdin);
        placa[strcspn(placa, "\n")] = '\0';

        duplicado = 0;
        for (int i = 0; i < *ubicacion; i++)
        {
            if (strcmp(vehiculos[i], placa) == 0)
            {
                duplicado = 1;
                printf("La placa ya existe. Por favor ingrese una placa diferente.\n");
                break;
            }
        }
    } while (duplicado == 1);

    strcpy(vehiculos[*ubicacion], placa);

    printf("Ingrese el color del vehiculo: ");
    fflush(stdin);
    fgets(color[*ubicacion], 30, stdin);
    len = strlen(color[*ubicacion]) - 1;
    if (len >= 0 && color[*ubicacion][len] == '\n')
    {
        color[*ubicacion][len] = '\0';
    }

    do
    {
        printf("Ingrese el precio del vehiculo: ");
        fflush(stdin);
        val = scanf("%f", &precio[*ubicacion]);

        if (val != 1)
        {
            printf("Por favor, ingrese un valor correcto.\n");
            fflush(stdin); 
        }

        if (precio[*ubicacion] < 0)
        {
            printf("El precio no puede ser negativo. Por favor, ingrese un precio valido.\n");
            return;
        }

    } while (precio[*ubicacion] < 0 || val != 1);

    printf("Vehiculo agregado: %s, Dueño: %s, Color %s, Precio %f\n", vehiculos[*ubicacion], duenio[*ubicacion], color[*ubicacion], precio[*ubicacion]);
    (*ubicacion)++;
}


void venderVehiculo(char vehiculos[5][30], char duenio[5][30], int ubicacion, int vendido[5], char color[5][30], float precio[5])
{
    char placa[30];
    int len, encontrado = 0;

    if (ubicacion == 0)
    {
        printf("No hay vehiculos disponibles para vender.\n");
        return;
    }

    printf("Ingrese la placa del vehiculo a vender: ");
    fflush(stdin);
    fgets(placa, 30, stdin);
    len = strlen(placa) - 1;
    if (len >= 0 && placa[len] == '\n')
    {
        placa[len] = '\0'; 
    }

    for (int i = 0; i < ubicacion; i++)
    {
        if (strcmp(vehiculos[i], placa) == 0 && vendido[i] == 0)
        {
            vendido[i] = 1; // Marcar como vendido
            printf("Vehiculo vendido: %s, Dueño: %s, Precio: %f, Color: %s\n", vehiculos[i], duenio[i], precio[i], color[i]);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 0)
    {
        printf("Vehiculo no encontrado o ya vendido.\n");
    }
}

void listadoVehiculos(char vehiculos[5][30], char duenio[5][30], int vendido[5], char color[5][30], float precio[5], int ubicacion)
{
    if (ubicacion == 0) {
        printf("No hay vehículos registrados.\n");
        return;
    }

    printf("\nListado de vehículos:\n");
    for (int i = 0; i < ubicacion; i++) {
        printf("Placa: %s | Dueño: %s | Color: %s | Precio: %.2f | Estado: ", 
               vehiculos[i], duenio[i], color[i], precio[i]);

        if (vendido[i] == 1) {
            printf("Vendido\n");
        } else {
            printf("Disponible\n");
        }
    }
}

void buscarVehiculoPorCedula(char duenio[5][30], char vehiculos[5][30], int vendido[5], char color[5][30], float precio[5], int ubicacion)
{
    char cedula[30];
    int len, encontrado = 0;

    printf("Ingrese la cedula del dueño del vehiculo a buscar: ");
    fflush(stdin);
    fgets(cedula, 30, stdin);
    len = strlen(cedula) - 1;
    if (len >= 0 && cedula[len] == '\n')
    {
        cedula[len] = '\0'; 
    }

    for (int i = 0; i < ubicacion; i++)
    {
        if (strcmp(duenio[i], cedula) == 0)
        {
            printf("Vehiculo encontrado: Placa: %s, Dueño: %s, Color: %s, Precio: %.2f, Estado: ", 
                   vehiculos[i], duenio[i], color[i], precio[i]);

            if (vendido[i] == 1) {
                printf("Vendido\n");
            } else {
                printf("Disponible\n");
            }
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("No se encontraron vehiculos para el dueño con cedula %s.\n", cedula);
    }
}