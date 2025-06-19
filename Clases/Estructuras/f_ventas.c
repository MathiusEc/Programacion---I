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

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void listarProductos(struct Producto productos[], int num_productos)
{
    printf("Lista de Productos:\n");
    printf("Nombre\t\tPrecio\n");
    for (int i = 0; i < num_productos; i++)
    {
        printf("%s\t%.2f\n", productos[i].nombre, productos[i].precio);
    }
}

void realizarVenta(struct Venta *venta, struct Producto productos[], int contadorProductos)
{
    printf("Ingrese el nombre del cliente: ");
    leerCadena(venta->nombre_cliente, 50);
    
    printf("Ingrese la cédula del cliente: ");
    leerCadena(venta->cedula_cliente, 20);
    
    venta->total_venta = 0.0;
    venta->cantidad_productos = 0;
    int totalProductosComprados = 0; // Contador total de unidades
    int val, continuar = 1;
    int cantidadesVendidas[5] = {0}; // Arreglo paralelo para cantidades de cada tipo
    
    // Inicializar productos vendidos
    for (int i = 0; i < 5; i++)
    {
        strcpy(venta->productos_vendidos[i], "");
    }
    
    do
    {
        if (totalProductosComprados >= 5)
        {
            printf("Ha alcanzado el límite máximo de 5 productos por venta.\n");
            break;
        }
        
        printf("\nProductos disponibles:\n");
        listarProductos(productos, contadorProductos);
        
        printf("Ingrese el nombre del producto: ");
        char nombreProducto[50];
        leerCadena(nombreProducto, 50);
        
        int encontrado = 0;
        for (int i = 0; i < contadorProductos; i++)
        {
            if (strcmp(productos[i].nombre, nombreProducto) == 0)
            {
                int cantidad;
                do
                {
                    printf("Ingrese la cantidad: ");
                    val = scanf("%d", &cantidad);
                    fflush(stdin);
                    if (val != 1 || cantidad <= 0)
                    {
                        printf("Entrada invalida. Por favor, ingrese un numero positivo.\n");
                        fflush(stdin);
                    }
                } while (val != 1 || cantidad <= 0);

                // Verificar si la cantidad no excede el límite
                if (totalProductosComprados + cantidad > 5)
                {
                    int productosRestantes = 5 - totalProductosComprados;
                    printf("Solo puede comprar %d productos más. ¿Desea comprar %d %s? (1: Sí, 0: No): ", 
                           productosRestantes, productosRestantes, nombreProducto);
                    int respuesta;
                    scanf("%d", &respuesta);
                    fflush(stdin);
                    
                    if (respuesta == 1)
                    {
                        cantidad = productosRestantes;
                    }
                    else
                    {
                        encontrado = 1;
                        break;
                    }
                }
                
                // Buscar si el producto ya existe en la venta
                int productoExistente = -1;
                for (int j = 0; j < venta->cantidad_productos; j++)
                {
                    if (strcmp(venta->productos_vendidos[j], nombreProducto) == 0)
                    {
                        productoExistente = j;
                        break;
                    }
                }
                
                if (productoExistente != -1)
                {
                    // El producto ya existe, sumar la cantidad
                    cantidadesVendidas[productoExistente] += cantidad;
                }
                else
                {
                    // Nuevo producto, agregarlo a la venta
                    strcpy(venta->productos_vendidos[venta->cantidad_productos], productos[i].nombre);
                    cantidadesVendidas[venta->cantidad_productos] = cantidad;
                    venta->cantidad_productos++;
                }
                
                totalProductosComprados += cantidad;
                venta->total_venta += productos[i].precio * cantidad;
                encontrado = 1;
                
                printf("Total de productos en la venta: %d/5\n", totalProductosComprados);
                
                break;
            }
        }
        
        if (!encontrado)
        {
            printf("Producto no encontrado. Intente de nuevo.\n");
        }
        
        if (totalProductosComprados < 5)
        {
            printf("¿Desea agregar otro producto? (1: Sí, 0: No): ");
            scanf("%d", &continuar);
            fflush(stdin);
        }
        else
        {
            printf("Ha alcanzado el límite máximo de productos.\n");
            continuar = 0;
        }
        
    } while (continuar == 1 && totalProductosComprados < 5);
}

void listarVentas(struct Venta ventas[], int total_ventas)
{
    if (total_ventas == 0)
    {
        printf("No hay ventas registradas.\n");
        return;
    }

    float sumaTotalVentas = 0.0; // Variable para acumular el total de todas las ventas

    printf("\n=== LISTADO DE VENTAS ===\n");
    printf("ID\tCliente\t\t\tCédula\t\tProducto\t\tTotal\n");
    printf("-----------------------------------------------------------------------------------\n");

    for (int i = 0; i < total_ventas; i++)
    {
        printf("%d\t%s\t\t%s\n", i + 1, ventas[i].nombre_cliente, ventas[i].cedula_cliente);

        // Imprimir los productos vendidos
        for (int j = 0; j < ventas[i].cantidad_productos; j++)
        {
            printf("\t\t\t\t%s\n", ventas[i].productos_vendidos[j]);
        }

        // Imprimir el total de la venta
        printf("\t\t\t\tTOTAL DE LA VENTA:\t\t\t%.2f\n", ventas[i].total_venta);

        // Acumular el total de la venta en la sumatoria
        sumaTotalVentas += ventas[i].total_venta;
    }

    printf("-----------------------------------------------------------------------------------\n");
    printf("TOTAL ACUMULADO:\t\t\t\t\t\t\t%.2f\n", sumaTotalVentas);
}

struct Venta *buscarVenta(struct Venta ventas[], int total_ventas, char cedula_cliente[])
{
    for (int i = 0; i < total_ventas; i++)
    {
        if (strcmp(ventas[i].cedula_cliente, cedula_cliente) == 0)
        {
            return &ventas[i];
        }
    }
    return NULL; // Si no se encuentra la venta
}

void imprimirsolouno(struct Venta *venta)
{
    if (venta == NULL)
    {
        printf("Venta no encontrada.\n");
        return;
    }

    printf("\n=== DETALLES DE LA VENTA ===\n");
    printf("Cliente: %s\n", venta->nombre_cliente);
    printf("Cédula: %s\n", venta->cedula_cliente);
    printf("Productos vendidos:\n");

    for (int i = 0; i < venta->cantidad_productos; i++)
    {
        printf("- %s\n", venta->productos_vendidos[i]);
    }

    printf("TOTAL DE LA VENTA: %.2f\n", venta->total_venta);
}


