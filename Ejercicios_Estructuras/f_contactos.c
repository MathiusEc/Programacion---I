/*Crea un programa que permita:

Registrar hasta 10 contactos (nombre, teléfono, email).
Buscar un contacto por nombre.
Listar todos los contactos.
Modificar el teléfono o email de un contacto.
Eliminar un contacto.
Requisito:
Usa una estructura Contacto y manipula un arreglo de estructuras.
*/

#include <stdio.h>
#include <string.h>
#include "contactos.h"
#define MAX_CONTACTOS 10

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

void registrarContacto(struct Contactos contactos[], int *contador)
{
    if (*contador >= MAX_CONTACTOS)
    {
        printf("No se pueden registrar más contactos.\n");
        return;
    }

    printf("Registro de contacto %d:\n", *contador + 1);
    printf("Nombre: ");
    leerCadena(contactos[*contador].nombre, 50);
    fflush(stdin); // Limpiar el buffer de entrada
    printf("Teléfono: ");
    leerCadena(contactos[*contador].telefono, 15);
    fflush(stdin); // Limpiar el buffer de entrada
    printf("Email: ");
    leerCadena(contactos[*contador].email, 50);
    fflush(stdin); // Limpiar el buffer de entrada
    printf("Contacto registrado exitosamente.\n");

    (*contador)++;
}

void listarContactos(struct Contactos contactos[], int contador)
{
    if (contador == 0)
    {
        printf("No hay contactos registrados.\n");
        return;
    }

    printf("Lista de contactos:\n");
    printf("ID\tNombre\tTeléfono\tEmail\n");

    for (int i = 0; i < contador; i++)
    {
        printf("%d\t%s\t%s\t%s\n", i + 1, contactos[i].nombre, contactos[i].telefono, contactos[i].email);
    }
}

struct Contactos *buscarContacto(struct Contactos contactos[], int contador, char nombreBuscado[])
{
    struct Contactos *contactoEncontrado;
    for (int i = 0; i < contador; i++)
    {
        if (strcmp(contactos[i].nombre, nombreBuscado) == 0)
        {
            contactoEncontrado = &contactos[i];
            return contactoEncontrado;
        }
    }
    return 0;
}

void modificarContacto(struct Contactos *contacto)
{
    printf("Modificar contacto:\n");
    printf("Nuevo teléfono: ");
    leerCadena(contacto->telefono, 15);
    printf("Nuevo email: ");
    leerCadena(contacto->email, 50);
}

void eliminarContacto(struct Contactos contactos[], int *contador, char nombreBuscado[])
{
    for (int i = 0; i < *contador; i++)
    {
        if (strcmp(contactos[i].nombre, nombreBuscado) == 0)
        {
            // Desplazar los contactos hacia la izquierda
            for (int j = i; j < *contador - 1; j++)
            {
                contactos[j] = contactos[j + 1];
            }
            (*contador)--; // Reducir el contador de contactos
            return;
        }
    }
    printf("Contacto eliminado.\n");
}