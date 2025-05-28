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

int main(int argc, char *argv[])
{

    char vehiculos[5][30];
    char duenio[5][30];
    char color[5][30];
    char cedula[5][30];
    float precio[5];
    int vendido[5] = {0};
    int ubicacion = 0;
    int opcion, len, val;

    do
    {
        printf("==================================================\n");
        printf("      SISTEMA DE COMPRA Y VENTA DE VEHICULOS     \n");
        printf("==================================================\n");
        printf("1. Agregar vehiculo\n");
        printf("2. Vender vehiculo\n");
        printf("3. Buscar vehiculo por cedula de dueño\n");
        printf("4. Salir\n");
        printf(">> ");

        val = scanf("%d", &opcion);
        if (val != 1)
        {
            printf("Por favor, ingrese un valor correcto..\n");
            fflush(stdin);
        }

        switch (opcion)
        {
        case 1:
            agregarVehiculo(vehiculos, duenio, &ubicacion, color, precio, cedula);
            break;
        case 2:
            if (ubicacion == 0)
            {
                printf("No hay vehiculos disponibles para vender.\n");
            }
            else
            {
                listadoVehiculos(vehiculos, duenio, vendido, color, precio, ubicacion, cedula);
                venderVehiculo(vehiculos, duenio, ubicacion, vendido, color, precio, cedula);
            }
            break;
        case 3:
            if (ubicacion == 0)
            {
                printf("No hay vehiculos disponibles para buscar.\n");
            }
            else
            {
                buscarVehiculoPorCedula(duenio, vehiculos, vendido, color, precio, ubicacion, cedula);
            }
            
            break;
        default:
            printf("Saliendo del sistema...\n");
            break;
        }
    } while (opcion != 4 || val != 1);

    return 0;
}