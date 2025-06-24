/*Desarrolla un sistema que permita gestionar los préstamos de libros en una biblioteca. 
El sistema debe manejar un archivo para almacenar los libros disponibles y otro archivo para 
registrar los préstamos realizados. Los usuarios pueden realizar operaciones como registrar 
libros, listar libros disponibles, realizar préstamos, buscar préstamos por usuario y listar
todos los préstamos realizados.
 
Estructuras:

Libro: Representa un libro con los campos:

char titulo[50]
char autor[50]
char id
int disponible (1 si está disponible, 0 si está prestado)
Usuario: Representa un usuario con los campos:

char nombre[50]
int cedula
Prestamo: Representa un préstamo con los campos:

struct Usuario usuario
struct Libro libro
char fecha[11] (Formato: DD/MM/AAAA)*/

#include <stdio.h>
#include <string.h>
#include "libro.h"

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void inicializarLibro(struct Libro libros[5])
{
    strcpy(libros[0].titulo, "Cien años de soledad");
    strcpy(libros[0].autor, "Gabriel García Márquez");
    strcpy(libros[0].id, "LIB001");
    libros[0].disponible = 1;

    strcpy(libros[1].titulo, "El amor en los tiempos del cólera");
    strcpy(libros[1].autor, "Gabriel García Márquez");
    strcpy(libros[1].id, "LIB002");
    libros[1].disponible = 1;

    strcpy(libros[2].titulo, "Don Quijote de la Mancha");
    strcpy(libros[2].autor, "Miguel de Cervantes");
    strcpy(libros[2].id, "LIB003");
    libros[2].disponible = 1;

    strcpy(libros[3].titulo, "1984");
    strcpy(libros[3].autor, "George Orwell");
    strcpy(libros[3].id, "LIB004");
    libros[3].disponible = 1;

    strcpy(libros[4].titulo, "El Principito");
    strcpy(libros[4].autor, "Antoine de Saint-Exupéry");
    strcpy(libros[4].id, "LIB005");
    libros[4].disponible = 1;

    guardarLibro(libros); // Guardar los libros inicializados en el archivo
}

void imprimirLibroDisponible(struct Libro libros[5])
{
    printf("Libros disponibles:\n");
    printf("#\tTitulo\t\t\tAutor\t\tID\n");
    for (int i = 0; i < 5; i++)
    {
        if (libros[i].disponible == 1) // Solo imprimir los libros disponibles
        {
            printf("%d\t%s\t%s\t%s\n", i + 1, libros[i].titulo, libros[i].autor, libros[i].id);
        }
    }
}

void guardarLibro(struct Libro libros[5])
{
    FILE *f;
    f = fopen("libros.dat", "wb+"); // wb+ es para escribir y leer en binario
    fwrite(libros, sizeof(struct Libro), 5, f);
    fclose(f);
}

int leerLibro(struct Libro libros[5])
{
    FILE *f;
    f = fopen("libros.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 0; // Retornar 0 si no se pudo abrir el archivo
    }
    fread(libros, sizeof(struct Libro), 5, f); // Leer los libros del archivo
    fclose(f);
    return 1; // Retornar 1 si se leyeron los libros correctamente
}

void realizarPrestamo(struct Prestamo prestamos[5], struct Libro libros[5], struct Usuario usuarios[5], int *contP)
{
    if (*contP >= 5)
    {
        printf("No se pueden realizar más préstamos, límite alcanzado.\n");
        return;
    }

    // Leer los libros desde el archivo para asegurarse de que estén actualizados
    if (!leerLibro(libros))
    {
        printf("No se pudieron cargar los libros desde el archivo.\n");
        return;
    }

    // Mostrar los libros disponibles
    imprimirLibroDisponible(libros);

    struct Usuario usuario;
    struct Libro libro;

    printf("Ingrese el ID del usuario: ");
    leerCadena(usuario.id, 10);
    printf("Ingrese el nombre del usuario: ");
    leerCadena(usuario.nombre, 30);
    
    printf("Ingrese el ID del libro: ");
    leerCadena(libro.id, 10);

    // Buscar el libro
    int encontrado = 0;
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(libros[i].id, libro.id) == 0 && libros[i].disponible == 1)
        {
            encontrado = 1;
            libro = libros[i];
            libros[i].disponible = 0; // Marcar el libro como prestado
            break;
        }
    }

    if (!encontrado)
    {
        printf("Libro no encontrado o no disponible.\n");
        return;
    }

    // Registrar préstamo
    prestamos[*contP].usuarios = usuario;
    prestamos[*contP].libros = libro;

    printf("Ingrese la fecha del préstamo (DD/MM/AAAA): ");
    leerCadena(prestamos[*contP].fecha, 11);
    (*contP)++;
    
    // Guardar los cambios 
    guardarPrestamos(prestamos, *contP);
    guardarLibro(libros); // Guardar los cambios en los libros
    printf("Préstamo realizado con éxito.\n");
}

void listarPrestamos(struct Prestamo prestamos[5], int contP)
{
    if (contP == 0)
    {
        printf("No hay préstamos registrados.\n");
        return;
    }

    printf("Lista de préstamos:\n");
    printf("Usuario\t\tLibro\t\tFecha\n");
    for (int i = 0; i < contP; i++)
    {
        printf("%s\t%s\t%s\n", prestamos[i].usuarios.nombre, prestamos[i].libros.titulo, prestamos[i].fecha);
    }
}

void guardarPrestamos(struct Prestamo prestamos[5], int contP)
{
    FILE *f;
    f = fopen("prestamos.dat", "wb+"); // wb+ es para escribir y leer en binario
    fwrite(prestamos, sizeof(struct Prestamo), contP, f);
    fclose(f);
}

int leerPrestamos(struct Prestamo prestamos[5], int *contP)
{
    FILE *f;
    f = fopen("prestamos.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL)
    {
        printf("Error al abrir el archivo de préstamos.\n");
        return 0; // Retornar 0 si no se pudo abrir el archivo
    }
    *contP = fread(prestamos, sizeof(struct Prestamo), 5, f); // Leer los préstamos del archivo
    fclose(f);
    return 1; // Retornar 1 si se leyeron los préstamos correctamente
}

void buscarPrestamoPorUsuario()
{
    struct Prestamo prestamos[5];
    int contP = 0;
    leerPrestamos(prestamos, &contP); // Leer los préstamos del archivo

    char idUsuario[10];
    printf("Ingrese el ID del usuario a buscar: ");
    leerCadena(idUsuario, 10);

    int encontrado = 0;
    for (int i = 0; i < contP; i++)
    {
        if (strcmp(prestamos[i].usuarios.id, idUsuario) == 0)
        {
            printf("Préstamo encontrado:\n");
            printf("Usuario: %s, Libro: %s, Fecha: %s\n", prestamos[i].usuarios.nombre, prestamos[i].libros.titulo, prestamos[i].fecha);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("No se encontraron préstamos para el usuario con ID: %s\n", idUsuario);
    }
}

