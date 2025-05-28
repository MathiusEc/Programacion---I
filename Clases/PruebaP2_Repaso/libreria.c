/*Desarrolla un programa en C para gestionar el inventario de una pequeña librería. El sistema debe permitir:

Agregar un libro

Título
Autor
ISBN (no debe repetirse)
Precio
Vender un libro (Se elimina ese libro del inventario)

Buscar libros por autor

El usuario ingresa el nombre del autor y el sistema muestra todos los libros de ese autor.
Listar todos los libros

Mostrar todos los libros con su información y estado.
Restricciones y recomendaciones:

Usa arreglos de cadenas para almacenar los títulos, autores e ISBNs.
Usa un arreglo de float para los precios y un arreglo de int para el estado (0 = disponible, 1 = vendido).
Usa punteros para modificar los datos dentro de las funciones.
Valida que el ISBN no se repita al agregar un libro.
El sistema debe permitir hasta 10 libros.*/

#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 10
void agregarLibro(char titulos[MAX_LIBROS][50], char autores[MAX_LIBROS][50], char isbns[MAX_LIBROS][20], float precios[MAX_LIBROS],
                  int *totalLibros)
{
    if (*totalLibros >= MAX_LIBROS)
    {
        printf("No se pueden agregar más libros, inventario lleno.\n");
        return;
    }

    char isbn[20];
    int duplicado, len, val;

    do
    {
        printf("Ingrese el ISBN del libro: ");
        fflush(stdin);
        fgets(isbn, 20, stdin);
        len = strlen(isbn) - 1;
        if (len >= 0 && isbn[len] == '\n')
        {
            isbn[len] = '\0'; // Eliminar el salto de línea
        }

        duplicado = 0;
        for (int i = 0; i < *totalLibros; i++)
        {
            if (strcmp(isbns[i], isbn) == 0)
            {
                duplicado = 1;
                printf("El ISBN ya existe. Por favor, ingrese otro.\n");
                break;
            }
        }
    } while (duplicado == 1);

    strcpy(isbns[*totalLibros], isbn);

    printf("Ingrese el título del libro: ");
    fflush(stdin);
    fgets(titulos[*totalLibros], 50, stdin);
    len = strlen(titulos[*totalLibros]) - 1;
    if (len >= 0 && titulos[*totalLibros][len] == '\n')
    {
        titulos[*totalLibros][len] = '\0'; // Eliminar el salto de línea
    }

    printf("Ingrese el autor del libro: ");
    fflush(stdin);
    fgets(autores[*totalLibros], 50, stdin);
    len = strlen(autores[*totalLibros]) - 1;
    if (len >= 0 && autores[*totalLibros][len] == '\n')
    {
        autores[*totalLibros][len] = '\0'; // Eliminar el salto de línea
    }

    printf("Ingrese el precio del libro: ");
    do
    {
        fflush(stdin);
        val = scanf("%f", &precios[*totalLibros]);
        if (val != 1)
        {
            printf("Por favor, ingrese un valor correcto.\n");
            fflush(stdin);
        }
    } while (val != 1 || precios[*totalLibros] < 0);

    (*totalLibros)++;
    printf("Libro Agregado\n");
}

void buscarLibrosPorAutor(char titulos[MAX_LIBROS][50], char autores[MAX_LIBROS][50], char isbns[MAX_LIBROS][20], float precios[MAX_LIBROS],
                          int totalLibros)
{
    char autorBuscar[50];
    int encontrado = 0;

    printf("Ingrese el nombre del autor a buscar: ");
    fflush(stdin);
    fgets(autorBuscar, 50, stdin);
    int len = strlen(autorBuscar) - 1;
    if (len >= 0 && autorBuscar[len] == '\n')
    {
        autorBuscar[len] = '\0'; // Eliminar el salto de línea
    }

    for (int i = 0; i < totalLibros; i++) // Recorre hasta totalLibros, no MAX_LIBROS
    {
        if (strcmp(autores[i], autorBuscar) == 0)
        {
            printf("Título: %s, Autor: %s, ISBN: %s, Precio: %.2f\n",
                   titulos[i], autores[i], isbns[i], precios[i]);
            encontrado = 1;
        }
    }

    if (encontrado == 0)
    {
        printf("No se encontraron libros del autor %s.\n", autorBuscar);
    }
}

void listarLibros(char titulos[MAX_LIBROS][50], char autores[MAX_LIBROS][50], char isbns[MAX_LIBROS][20], float precios[MAX_LIBROS],
                  int totalLibros)
{
    if (totalLibros == 0)
    {
        printf("No hay libros en el inventario.\n");
        return;
    }

    printf("Listado de libros:\n");
    for (int i = 0; i < totalLibros; i++)
    {
        printf("Título: %s, Autor: %s, ISBN: %s, Precio: %.2f\n",
               titulos[i], autores[i], isbns[i], precios[i]);
    }
}
void venderLibro(char titulos[MAX_LIBROS][50], char autores[MAX_LIBROS][50], char isbns[MAX_LIBROS][20], float precios[MAX_LIBROS],
                 int *totalLibros) // Cambiar totalLibros a puntero para modificar su valor
{
    char isbn[20];
    int len, encontrado = -1;

    listarLibros(titulos, autores, isbns, precios, *totalLibros);

    printf("Ingrese el ISBN del libro a vender: ");
    fflush(stdin);
    fgets(isbn, 20, stdin);
    len = strlen(isbn) - 1;
    if (len >= 0 && isbn[len] == '\n')
    {
        isbn[len] = '\0'; // Eliminar el salto de línea
    }

    // Buscar el libro por ISBN
    for (int i = 0; i < *totalLibros; i++)
    {
        if (strcmp(isbns[i], isbn) == 0)
        {
            printf("Libro vendido: %s por %s\n", titulos[i], autores[i]);
            encontrado = i; // Guardar la posición del libro a eliminar
            break;
        }
    }

    if (encontrado != -1)
    {
        // Desplazar los libros para eliminar el libro vendido
        for (int i = encontrado; i < *totalLibros - 1; i++)
        {
            strcpy(titulos[i], titulos[i + 1]);
            strcpy(autores[i], autores[i + 1]);
            strcpy(isbns[i], isbns[i + 1]);
            precios[i] = precios[i + 1];
        }

        (*totalLibros)--; // Reducir el número total de libros
    }
    else
    {
        printf("Libro no encontrado o ya vendido.\n");
    }
}
int main(int argc, char *argv[])
{
    char titulos[MAX_LIBROS][50];
    char autores[MAX_LIBROS][50];
    char isbns[MAX_LIBROS][20];
    float precios[MAX_LIBROS];
    int opc, val, totalLibros = 0;

    do
    {
        printf("==================================================\n");
        printf("           SISTEMA DE GESTION DE LIBRERIA        \n");
        printf("==================================================\n");
        printf("1. Agregar libro\n");
        printf("2. Buscar libros por autor\n");
        printf("3.Vender libro \n");
        printf(">> ");

        val = scanf("%d", &opc);
        if (val != 1)
        {
            printf("Por favor, ingrese un valor correcto.\n");
            fflush(stdin);
        }

        switch (opc)
        {
        case 1:
            agregarLibro(titulos, autores, isbns, precios, &totalLibros);
            break;
        case 2:
            if (totalLibros == 0)
            {
                printf("No hay libros disponibles para buscar.\n");
            }
            else
            {
                buscarLibrosPorAutor(titulos, autores, isbns, precios, totalLibros);
            }
            break;

        case 3:
            if (totalLibros == 0)
            {
                printf("No hay libros disponibles para vender.\n");
            }
            else
            {
                venderLibro(titulos, autores, isbns, precios, &totalLibros);
            }
            break;

        default:
            printf("Saliendo del sistema...\n");
            break;
        }

    } while (opc != 4 || val != 1);

    return 0;
}