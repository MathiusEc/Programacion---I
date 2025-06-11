/* Se desea desarrollar un sistema de gestion de ventas que tenga las siguientes funcionalidades, visualizar productos, crear venta,
listar o imprimir las ventas y buscar las ventas.asm

Los atributos de la venta son los siguientes: nombre del cliente, cedula, total de la venta, productos vendidos.
Los atributos de la productos son los siguientes: nombre del producto, precio.asm

Nota: Los productos deben estar predefinidos, minimos 2, maximo 5
*/

#include <stdio.h>
#include <string.h>
#include "ventas.h"

#define MAX_PRODUCTOS 3

void leerCadena(char *cadena, int num)
{
    fflush(stdin); // Limpiar el buffer de entrada
    fgets(cadena, num, stdin);

    // Eliminar el salto de línea al final
    int len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n')
    {
        cadena[len - 1] = '\0';
    }
}

void listarProductos(struct producto productos[])
{
    printf("Productos disponibles:\n");
    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        printf("%d. %s - Precio: %.2f\n", i + 1, productos[i].nombre_producto, productos[i].precio);
    }
}

void crearVenta(struct ventas *venta, struct producto productos[], int numero_venta)
{
    char nombre_producto[50];
    int opci = 1, cantidad;

    // Inicializar productos vendidos
    for (int i = 0; i < MAX_PRODUCTOS; i++)
    {
        venta->productos_vendidos[i].precio = 0.0;
        venta->productos_vendidos[i].cantidad = 0;  // ← Inicializar cantidad
        strcpy(venta->productos_vendidos[i].nombre_producto, "");
    }

    venta->total_venta = 0.0;

    printf("=== Registro de Venta #%d ===\n", numero_venta + 1);
    printf("Nombre del cliente: ");
    leerCadena(venta->nombre_cliente, 50);
    printf("Cédula: ");
    leerCadena(venta->cedula, 11);

    do
    {
        printf("\nIngrese el nombre del producto que desea comprar:\n");
        listarProductos(productos);
        printf("Producto: ");
        leerCadena(nombre_producto, 50);

        if (strcmp(nombre_producto, "Sillas") == 0)
        {
            printf("Cantidad de Sillas: ");
            scanf("%d", &cantidad);
            fflush(stdin);
            
            // Guardar producto con cantidad
            strcpy(venta->productos_vendidos[0].nombre_producto, productos[0].nombre_producto);
            venta->productos_vendidos[0].precio = productos[0].precio;
            venta->productos_vendidos[0].cantidad = cantidad;  // ← Guardar cantidad
            venta->total_venta += productos[0].precio * cantidad;
            
            printf("¿Desea agregar otro producto? (1: Sí, 0: No): ");
            scanf("%d", &opci);
            fflush(stdin);
        }
        else if (strcmp(nombre_producto, "Mesas") == 0)
        {
            printf("Cantidad de Mesas: ");
            scanf("%d", &cantidad);
            fflush(stdin);
            
            strcpy(venta->productos_vendidos[1].nombre_producto, productos[1].nombre_producto);
            venta->productos_vendidos[1].precio = productos[1].precio;
            venta->productos_vendidos[1].cantidad = cantidad;  // ← Guardar cantidad
            venta->total_venta += productos[1].precio * cantidad;
            
            printf("¿Desea agregar otro producto? (1: Sí, 0: No): ");
            scanf("%d", &opci);
            fflush(stdin);
        }
        else if (strcmp(nombre_producto, "Camas") == 0)
        {
            printf("Cantidad de Camas: ");
            scanf("%d", &cantidad);
            fflush(stdin);
            
            strcpy(venta->productos_vendidos[2].nombre_producto, productos[2].nombre_producto);
            venta->productos_vendidos[2].precio = productos[2].precio;
            venta->productos_vendidos[2].cantidad = cantidad;  // ← Guardar cantidad
            venta->total_venta += productos[2].precio * cantidad;
            
            printf("¿Desea agregar otro producto? (1: Sí, 0: No): ");
            scanf("%d", &opci);
            fflush(stdin);
        }
        else
        {
            printf("Producto no encontrado. Por favor, intente de nuevo.\n");
        }

    } while (opci == 1);

    printf("Venta #%d registrada exitosamente. Total: %.2f\n",
           numero_venta + 1, venta->total_venta);
}

void listarVentas(struct ventas ventas[], int contador)
{
    if (contador == 0)
    {
        printf("No hay ventas registradas.\n");
        return;
    }

    printf("\n=== LISTA DE VENTAS ===\n");
    for (int i = 0; i < contador; i++)
    {
        printf("Venta %d:\n", i + 1);
        printf("Cliente: %s\n", ventas[i].nombre_cliente);
        printf("Cédula: %s\n", ventas[i].cedula);
        printf("Productos vendidos:\n");
        
        for (int j = 0; j < MAX_PRODUCTOS; j++)
        {
            if (ventas[i].productos_vendidos[j].precio > 0)
            {
                float subtotal = ventas[i].productos_vendidos[j].precio * ventas[i].productos_vendidos[j].cantidad;
                printf("- %s x%d - Precio unitario: $%.2f - Subtotal: $%.2f\n",
                       ventas[i].productos_vendidos[j].nombre_producto,
                       ventas[i].productos_vendidos[j].cantidad,  // ← Mostrar cantidad
                       ventas[i].productos_vendidos[j].precio,
                       subtotal);  // ← Mostrar subtotal
            }
        }
        printf("TOTAL DE LA VENTA: $%.2f\n", ventas[i].total_venta);
        printf("----------------------------------------\n");
    }
}

struct ventas *buscarVenta(struct ventas ventas[], int contador, char nombre_cliente[])
{
    for (int i = 0; i < contador; i++)
    {
        if (strcmp(ventas[i].nombre_cliente, nombre_cliente) == 0)
        {
            return &ventas[i];
        }
    }
    return 0;  // Si no se encuentra la venta
}

void imprimirsolouno(struct ventas *venta)
{
    if (venta == NULL)
    {
        printf("Venta no encontrada.\n");
        return;
    }

    printf("\n=== DETALLES DE LA VENTA ===\n");
    printf("Cliente: %s\n", venta->nombre_cliente);
    printf("Cédula: %s\n", venta->cedula);
    printf("Productos vendidos:\n");

    for (int j = 0; j < MAX_PRODUCTOS; j++)
    {
        if (venta->productos_vendidos[j].precio > 0)
        {
            float subtotal = venta->productos_vendidos[j].precio * venta->productos_vendidos[j].cantidad;
            printf("- %s x%d - Precio unitario: $%.2f - Subtotal: $%.2f\n",
                   venta->productos_vendidos[j].nombre_producto,
                   venta->productos_vendidos[j].cantidad,  // ← Mostrar cantidad
                   venta->productos_vendidos[j].precio,
                   subtotal);  // ← Mostrar subtotal
        }
    }
    printf("TOTAL DE LA VENTA: $%.2f\n", venta->total_venta);
}