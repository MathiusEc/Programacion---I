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

int main(int argc, char *argv[])
{
    struct Libro libros[5];
    struct Prestamo prestamos[5];
    struct Usuario usuarios[5]; // Arreglo para almacenar usuarios
    int contP = 0; // Contador de préstamos realizados

    int opc;
    do
    {
        printf("\nBienvenido al sistema de gestión de préstamos de libros.\n");
        printf("1. Inicializar libro\n");
        printf("2. Listar libros disponibles\n");
        printf("3. Realizar préstamo\n");
        printf("4. Buscar préstamo por usuario\n");
        printf("5. Listar todos los préstamos\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc);
        fflush(stdin); // Limpiar el buffer de entrada

        switch (opc)
        {
        case 1:
            inicializarLibro(libros);
            printf("Libros inicializados correctamente.\n");
            break;

        case 2:
            if (leerLibro(libros) == 0)
            {
                printf("No hay libros disponibles.\n");
            }
            else
            {
                imprimirLibroDisponible(libros);
            }
            break;
        case 3:
            realizarPrestamo(prestamos, libros, usuarios, &contP);
            break;

        case 4:
            buscarPrestamoPorUsuario();
            break;
        
        case 5:
            if (leerPrestamos(prestamos, &contP) == 0)
            {
                printf("No hay préstamos registrados.\n");
            }
            else
            {
                listarPrestamos(prestamos, contP);
            }

        default:
            break;
        }
    } while (opc != 6);

    return 0;
}