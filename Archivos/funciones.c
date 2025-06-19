
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
}

void imprimirProducto(struct Producto productos[5])
{
    printf("Productos disponibles:\n");
    printf("#\tNombre\t\tPrecio\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\t%s\t\t%.2f\n", i + 1, productos[i].nombre, productos[i].precio);
    }
}
