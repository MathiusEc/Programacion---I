
#include <stdio.h>
#include <string.h>
#include "funciones.h"

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void inicializarProducto(struct Producto productos[5])
{
    strcpy(productos[0].nombre, "Micro");
    productos[0].precio = 80;

    strcpy(productos[1].nombre, "Licuadora");
    productos[1].precio = 30;

    strcpy(productos[2].nombre, "Cocina");
    productos[2].precio = 200;

    strcpy(productos[3].nombre, "refri");
    productos[3].precio = 600;

    strcpy(productos[4].nombre, "TV");
    productos[4].precio = 700;

    guardarProducto(productos); // Guardar los productos inicializados en el archivo
}

void imprimirProducto(struct Producto productos[5])
{
    printf("Productos disponibles:\n");
    printf("#\tNombre\t\tPrecio\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t\t%.2f\n", i, productos[i].nombre, productos[i].precio);
    }
}

void guardarProducto(struct Producto *productos)
{
    FILE *f;
    f = fopen("productos.dat", "wb+"); // wb+ es para escribir y leer en binario
    fwrite(productos, sizeof(struct Producto), 5, f);
    fclose(f);
}

int leerProducto(struct Producto productos[5])
{
    /*Al declarar:
        1. productos[5] => darle al compilador la primera dirección de memoria (que es lo q necesitamos)
        2. *prodctos=> le damos un puntero al arreglo*/

    FILE *f;
    f = fopen("productos.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 0;
    }
    fread(productos, sizeof(struct Producto), 5, f); // sizeof(struct Producto) para leer el tamaño de cada producto en bytes
    fclose(f);
    return 1;
}

void realizarVenta(struct Venta ventas[5], struct Producto productos[5], int *numVentas) 
{
    struct Venta nuevaVenta;
    int numProductos, productoIndex;    
    printf("Ingrese el nombre del cliente: ");
    leerCadena(nuevaVenta.clientes.nombre, 20);
    printf("Ingrese la cedula del cliente: ");
    scanf("%d", &nuevaVenta.clientes.cedula);
    printf("Ingrese el numero de productos (maximo 5): ");
    scanf("%d", &numProductos);
    if (numProductos < 1 || numProductos > 5) {
        printf("Numero de productos invalido. Debe ser entre 1 y 5.\n");
        return; // return es para salir de la funcion si el numero de productos es invalido
    }

    nuevaVenta.num_produ = numProductos;
    nuevaVenta.total = 0.0;
    imprimirProducto(productos); // Mostrar los productos disponibles
    printf("Seleccione el producto(0-4)");
    for (int i = 0; i < numProductos; i++)
    {
        printf(">> ");
        fflush(stdin); // Limpiar el buffer de entrada
        scanf("%d", &productoIndex);
        if (productoIndex < 0 || productoIndex >= 5) {
            printf("Producto invalido. Debe ser entre 0 y 4.\n");
            i--; // Decrementar i para repetir la iteracion
            continue; // continue es para saltar al inicio del bucle
        }
        nuevaVenta.productos[i] = productos[productoIndex]; // Guardar el producto seleccionado
        nuevaVenta.total += productos[productoIndex].precio; // Sumar el precio del producto al total
    }
    
    ventas[*numVentas] = nuevaVenta; // Guardar la venta en el arreglo de ventas
    (*numVentas)++; // Incrementar el contador de ventas
    guardarVenta(ventas, *numVentas); // Guardar las ventas en el archivo
    printf("Venta realizada con exito! Total: %.2f\n", nuevaVenta.total);
}

void listarVentas(struct Venta ventas[5], int numVentas) 
{
    if (numVentas == 0) {
        printf("No hay ventas registradas.\n");
        return;
    }
    
    printf("Ventas realizadas:\n");
    for (int i = 0; i < numVentas; i++) {
        printf("Venta #%d\n", i + 1);
        printf("Cliente: %s, Cedula: %d\n", ventas[i].clientes.nombre, ventas[i].clientes.cedula);
        printf("Productos:\n");
        for (int j = 0; j < ventas[i].num_produ; j++) {
            printf("- %s: %.2f\n", ventas[i].productos[j].nombre, ventas[i].productos[j].precio);
        }
        printf("Total: %.2f\n", ventas[i].total);
        printf("-------------------------\n");
    }
}

void guardarVenta(struct Venta *ventas, int numVentas) 
{
    FILE *f;
    f = fopen("ventas.dat", "wb+"); // wb+ es para escribir y leer en binario
    if (f == NULL) {
        printf("Error al abrir el archivo de ventas.\n");
        return;
    }
    fwrite(ventas, sizeof(struct Venta), numVentas, f); // Guardar todas las ventas en el archivo
    fclose(f);
}

int leerVentas(struct Venta ventas[5], int *numVentas) 
{
    FILE *f;
    f = fopen("ventas.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL) {
        printf("Error al abrir el archivo de ventas.\n");
        return 0; // Retornar 0 si no se pudo abrir el archivo
    }
    *numVentas = fread(ventas, sizeof(struct Venta), 5, f); // Leer las ventas del archivo
    fclose(f);
    return 1; // Retornar 1 si se leyeron las ventas correctamente
}

void buscarVenta()
{
    int cedulaBusc;
    struct Venta ventas[5];
    int numVentas = 0;

    leerVentas(ventas, &numVentas); // Leer las ventas del archivo
    printf("Ingrese la cedula del cliente a buscar: ");
    scanf("%d", &cedulaBusc);

    int encontrada = 0;
    for (int i = 0; i < numVentas; i++) {
        if (ventas[i].clientes.cedula == cedulaBusc) {
            printf("Venta encontrada:\n");
            printf("Cliente: %s, Cedula: %d\n", ventas[i].clientes.nombre, ventas[i].clientes.cedula);
            printf("Productos:\n");
            for (int j = 0; j < ventas[i].num_produ; j++) {
                printf("- %s: %.2f\n", ventas[i].productos[j].nombre, ventas[i].productos[j].precio);
            }
            printf("Total: %.2f\n", ventas[i].total);
            encontrada = 1;
        }
    }

    if (!encontrada) {
        printf("No se encontraron ventas para la cedula %d.\n", cedulaBusc);
    }    
}