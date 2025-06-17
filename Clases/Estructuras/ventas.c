/*Se desea desarrollar un sistema de gestion de ventas  para una tienda de electrodomésticos y deberá tener las siguientes funcionalidades: 

1) Listar los productos
2) Realizar una venta
3) Ver todas las ventas (Total de ventas
4) Buscar las ventas por cedula del cliente

Las ventas tendran los siguientes atributos: 
nombre del cliente, cedula del cliente, cantidad de productos (máximo 5), total de la venta, productos vendidos

los productos deberan tener:
nombre y precio

Nota: Los productos son predefinidos*/


#include <stdio.h>
#include <string.h> 
#include "ventas.h"

int main (int argc, char *argv[]) {
    struct Producto productos[5] = {
        {"Televisor", 300.00},
        {"Refrigerador", 500.00},
        {"Lavadora", 400.00},
        {"Horno Microondas", 150.00},
        {"Aire Acondicionado", 600.00}
    };

    struct Venta ventas[100];
    int total_ventas = 0;
    int opcion, val;

    do
    {
        printf("\nMenu de Ventas:\n");
        printf("1. Listar los productos\n");
        printf("2. Realizar una venta\n");
        printf("3. Ver todas las ventas\n");
        printf("4. Buscar ventas por cedula del cliente\n");
        printf("5. Salir\n");
        printf(">> ");
        val = scanf("%d", &opcion);
        if (val != 1) {
            printf("Entrada invalida. Por favor, ingrese un numero.\n");
            fflush(stdin); // Limpiar el buffer de entrada
        }

        switch (opcion)
        {
        case 1:
            listarProductos(productos, 5);
            break;

        case 2:
            realizarVenta(&ventas[total_ventas], productos, 5);
            total_ventas++;
            break;
            
        case 3:
            listarVentas(ventas, total_ventas);
            break;

        case 4:
            {
                char cedula_cliente[20];
                printf("Ingrese la cédula del cliente: ");
                leerCadena(cedula_cliente, 20);
                struct Venta *venta = buscarVenta(ventas, total_ventas, cedula_cliente);
                if (venta != NULL) {
                    imprimirsolouno(venta);
                } else {
                    printf("No se encontraron ventas para la cédula %s.\n", cedula_cliente);
                }
            }
            break;
        default:
            break;
        }
    } while (opcion != 5 || val != 1);
    

    return 0;
}