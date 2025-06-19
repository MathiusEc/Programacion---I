

#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (int argc, char *argv[]) {
    struct Producto productos[5];

    int opc, val;
    int contE = 0;
    


    do
    {
        printf("=========Menu=========\n");
        printf("1. Inicializar Producto\n");
        printf("2. Imprimir Producto\n");
        printf("3. Realizar Venta\n");
        printf("4. Ver todas las ventas\n");
        printf("5. Buscar ventas\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            inicializarProducto(productos);
            break;
        case 2:
            imprimirProducto(productos);
            break;
        default:
            break;
        }
    } while (opc != 6 || val != 1);

    return 0;
}