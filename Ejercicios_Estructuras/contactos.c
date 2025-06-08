/* Crea un programa que permita:

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


int main (int argc, char *argv[]) 
{
    struct Contactos contactos[MAX_CONTACTOS];
    struct Contactos *contactoEncontrado;
    int contador = 0;
    int opcion, val;

    do
    {
        printf("\nMenu de Contactos:\n");
        printf("1. Registrar contacto\n");
        printf("2. Listar contactos\n");
        printf("3. Buscar contacto\n");
        printf("4. Modificar contacto\n");
        printf("5. Eliminar contacto\n");
        printf("6. Salir\n");
        printf(">> ");
        val = scanf("%d", &opcion);
        if (val != 1 || opcion < 1 || opcion > 6) {
            printf("Opción inválida. Por favor, ingrese un número entre 1 y 6.\n");
            fflush(stdin); // Limpiar el buffer de entrada
        }
        
        switch (opcion)
        {
        case 1:
            registrarContacto(contactos, &contador);
            break;

        case 2:
            if (contador == 0) {
                printf("No hay contactos registrados.\n");
            } else {
                listarContactos(contactos, contador);
            }
            break;

        case 3: 
            char nombreBuscado[50];
            printf("Ingrese el nombre del contacto a buscar: ");
            leerCadena(nombreBuscado, 50);
            contactoEncontrado = buscarContacto(contactos, contador, nombreBuscado);
            if (contactoEncontrado != 0) {
                printf("Contacto encontrado: Nombre: %s, Teléfono: %s, Email: %s\n",
                       contactoEncontrado->nombre, contactoEncontrado->telefono, contactoEncontrado->email);
            } else {
                printf("Contacto no encontrado.\n");
            }
            break;
        
        case 4: 
            char nombreBuscado2[50];
            printf("Ingrese el nombre del contacto a modificar: ");
            leerCadena(nombreBuscado2, 50);
            contactoEncontrado = buscarContacto(contactos, contador, nombreBuscado2);
            if (contactoEncontrado != 0) {
                modificarContacto(contactoEncontrado);
            } else {
                printf("Contacto no encontrado.\n");
            }
            break;

        case 5:
            char nombreEliminar[50];
            printf("Ingrese el nombre del contacto a eliminar: ");
            leerCadena(nombreEliminar, 50);
            eliminarContacto(contactos, &contador, nombreEliminar);
            break;
        
        default:
            break;
        }
    } while (opcion != 5 || val != 0);
    
    return 0;
}