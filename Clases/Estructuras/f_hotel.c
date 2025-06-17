/*Desarrollar un sistema que permita gestionar las reservas de habitaciones en un hotel. El sistema debe manejar huéspedes y
habitaciones. Cada reserva está asociada a un huésped y una habitación específica.

Se pueden realizar operaciones como registrar huéspedes, reservar habitaciones (entre 5 predefinidas), listar reservas, cambiar estado
de las habitaciones, listar las habitaciones, buscar reservas por huésped
y calcular el costo total de una reserva.*/

#include <stdio.h>
#include <string.h>
#include "hotel.h"

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void crearHuesped(struct Huesped *huesped)
{
    printf("Ingrese el nombre del huesped: ");
    leerCadena(huesped->nombre, 30);

    printf("Ingrese el documento del huesped: ");
    leerCadena(huesped->documento, 20);

    printf("Ingrese el telefono del huesped: ");
    leerCadena(huesped->telefono, 15);
}

void reservarHabitacion(struct Habitacion habitaciones[], struct Huesped *huesped, int *ubicacion)
{
    if (*ubicacion >= 5)
    {
        printf("No se pueden realizar más reservas, el hotel está lleno.\n");
        return;
    }

    char idHabitacion[10];
    int encontrado = 0;

    printf("Ingrese el ID de la habitación a reservar: ");
    leerCadena(idHabitacion, 10);

    for (int i = 0; i < 5; i++)
    {
        if (strcmp(habitaciones[i].id, idHabitacion) == 0 && strcmp(habitaciones[i].estado, "Disponible") == 0)
        {
            strcpy(habitaciones[i].estado, "Reservada");
            habitaciones[i].huesped = *huesped;
            *ubicacion += 1;
            encontrado = 1;

            crearHuesped(&habitaciones[i].huesped);

            printf("Ingrese el tiempo de reserva (en noches): ");
            scanf("%d", &habitaciones[i].tiempo);

            printf("Reserva realizada con éxito en la habitación %s.\n", habitaciones[i].id);
            printf("El costo total de la reserva es: %.2f\n", habitaciones[i].precioPorNoche * habitaciones[i].tiempo);
            break;
        }
    }

    if (!encontrado)
    {
        printf("Habitación no encontrada o no disponible.\n");
    }
}

void listarReservas(struct Habitacion habitaciones[], int ubicacion)
{
    if (ubicacion == 0)
    {
        printf("No hay reservas registradas.\n");
        return;
    }

    printf("Listado de reservas:\n");
    printf("ID\tTipo\tPrecio/Noche\tTiempo\tEstado\tHuesped\tTelefono\tDocumento\tCosto Total\n");
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(habitaciones[i].estado, "Reservada") == 0)
        {
            printf("%s\t%s\t%.2f\t%d\t%s\t%s\t%s\t%s\t%.2f\n", habitaciones[i].id, habitaciones[i].tipo,
                   habitaciones[i].precioPorNoche, habitaciones[i].tiempo, habitaciones[i].estado,
                   habitaciones[i].huesped.nombre, habitaciones[i].huesped.telefono, habitaciones[i].huesped.documento,
                   habitaciones[i].precioPorNoche * habitaciones[i].tiempo);
        }
    }
}

struct Habitacion *buscarReservaPorHuesped(struct Habitacion habitaciones[], char documento[], int ubicacion)
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(habitaciones[i].estado, "Reservada") == 0 && strcmp(habitaciones[i].huesped.documento, documento) == 0)
        {
            return &habitaciones[i];
        }
    }
    return NULL;
}

void LiberarHabitacion(struct Habitacion habitaciones[], char id[])
{
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(habitaciones[i].id, id) == 0)
        {
            // Cambiar el estado a "Disponible"
            strcpy(habitaciones[i].estado, "Disponible");

            // Limpiar los datos del huésped
            strcpy(habitaciones[i].huesped.nombre, "");
            strcpy(habitaciones[i].huesped.telefono, "");
            strcpy(habitaciones[i].huesped.documento, "");

            habitaciones[i].tiempo = 0;

            printf("La habitación %s ha sido liberada y está disponible nuevamente.\n", habitaciones[i].id);
            return;
        }
    }
    printf("Habitación no encontrada.\n");
}

void listarHabitaciones(struct Habitacion habitaciones[])
{
    printf("Listado de habitaciones:\n");
    printf("ID\tTipo\tPrecio/Noche\tEstado\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%s\t%.2f\t%s\n", habitaciones[i].id, habitaciones[i].tipo, habitaciones[i].precioPorNoche, habitaciones[i].estado);
    }
}

void imprimirunasolaReserva(struct Habitacion *habitacion)
{
    if (habitacion != NULL)
    {
        printf("ID: %s\n", habitacion->id);
        printf("Tipo: %s\n", habitacion->tipo);
        printf("Precio por noche: %.2f\n", habitacion->precioPorNoche);
        printf("Tiempo de reserva: %d noches\n", habitacion->tiempo);
        printf("Estado: %s\n", habitacion->estado);
        printf("Huesped: %s\n", habitacion->huesped.nombre);
        printf("Telefono: %s\n", habitacion->huesped.telefono);
        printf("Documento: %s\n", habitacion->huesped.documento);
        printf("Costo total: %.2f\n", habitacion->precioPorNoche * habitacion->tiempo);
    }
    else
    {
        printf("No se encontró la reserva.\n");
    }
}