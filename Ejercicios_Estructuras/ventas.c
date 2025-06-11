#include <stdio.h>
#include <string.h>
#include "ventas.h"

#define MAX_VENTAS 1000  // ← Número grande, prácticamente ilimitado

int main(int argc, char *argv[])
{
    struct producto productos[MAX_PRODUCTOS] = {
        {"Sillas", 10.0},
        {"Mesas", 20.0},
        {"Camas", 30.0},
    };
    
    struct ventas ventas[MAX_VENTAS];  // Arreglo grande
    int opcion, val, cont_vent = 0;

    do
    {
        printf("\nSistema de Gestión de Ventas\n");
        printf("1. Visualizar Productos\n");
        printf("2. Crear Venta\n");
        printf("3. Listar Ventas\n");
        printf("4. Buscar Venta\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        val = scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
        {
        case 1:
            listarProductos(productos);
            break;

        case 2:
            crearVenta(&ventas[cont_vent], productos, cont_vent);
            cont_vent++;
            break;

        case 3: 
            listarVentas(ventas, cont_vent);    
            break;
            
        case 4:
            char nomBuscar[50];
            printf("Ingrese el nombre del cliente a buscar: ");
            leerCadena(nomBuscar, 50);
            int encontrado = 0;
            struct ventas *venta = buscarVenta(ventas, cont_vent, nomBuscar);
            imprimirsolouno(venta);
            break;
        default:
            break;
        }
    } while (opcion != 5);

    return 0;
}