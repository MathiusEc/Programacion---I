

#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    struct Producto productos[5];
    struct Venta ventas[5];

    int opc, val;
    int contE = 0;
    
    do
    {
        printf("\n=========Menu=========\n");
        printf("1. Inicializar Producto\n");
        printf("2. Imprimir Producto\n");
        printf("3. Realizar Venta\n");
        printf("4. Ver todas las ventas\n");
        printf("5. Buscar ventas\n");
        printf("6. Salir\n");
        printf(">> ");
        val = scanf("%d", &opc);
        fflush(stdin); // Limpiar el buffer de entrada
        if (val != 1)
        {
            printf("Entrada invalida, por favor ingrese un numero.\n");
            fflush(stdin); // Limpiar el buffer de entrada
        }
       
        switch (opc)
        {
        case 1:
            inicializarProducto(productos);
            break;
        case 2:
            if (leerProducto(productos) == 0)
            {
                printf("No hay productos disponibles\n");
            }
            else
            {
                imprimirProducto(productos);
            }
            break;

        case 3:
            realizarVenta(ventas, productos, &contE);
            break;

        case 4:
            leerVentas(ventas, &contE);
            if (contE == 0)
            {
                printf("No hay ventas registradas.\n");
            }
            else
            {
                listarVentas(ventas, contE);
            }
            break;

        case 5:
            buscarVenta();
            break;
        default:
            break;
        }
    } while (opc != 6 || val != 1);

    return 0;
}