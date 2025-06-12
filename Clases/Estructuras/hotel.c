/*Desarrollar un sistema que permita gestionar las reservas de habitaciones en un hotel. El sistema debe manejar huéspedes y 
habitaciones. Cada reserva está asociada a un huésped y una habitación específica. 

Se pueden realizar operaciones como registrar huéspedes, reservar habitaciones (entre 5 predefinidas), listar reservas, buscar reservas por huésped 
y calcular el costo total de una reserva.*/


#include <stdio.h>
#include <string.h>
#include "hotel.h"

int main (int argc, char *argv[]) {

    struct Habitacion habitaciones[5] = {
        {"H001", "Individual", 50.0, 0, "Disponible", {0}},
        {"H002", "Doble", 80.0, 0, "Disponible", {0}},
        {"H003", "Suite", 120.0, 0, "Disponible", {0}},
        {"H004", "Familiar", 100.0, 0, "Disponible", {0}},
        {"H005", "Presidencial", 200.0, 0, "Disponible", {0}}
    };

    int opc, ubicacion = 0;
    struct Huesped huesped;
    struct Habitacion *reserva;

    do
    {
        printf("\nMenu de opciones:\n");
        printf("1. Reservar habitación\n");
        printf("2. Listar reservas\n");
        printf("3. Buscar reserva por huésped\n");
        printf("4. Liberar habitación\n");
        printf("5. Listar habitaciones\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc);
        fflush(stdin);

        switch (opc)
        {
        case 1:
            listarHabitaciones(habitaciones);
            reservarHabitacion(habitaciones, &huesped, &ubicacion);
            break;
        case 2:
            listarReservas(habitaciones, ubicacion);
            break;
        case 3:
            printf("Ingrese el documento del huésped: ");
            leerCadena(huesped.documento, 20);
            reserva = buscarReservaPorHuesped(habitaciones, huesped.documento, ubicacion);
            imprimirunasolaReserva(reserva);
            break;
        case 4:
            printf("Ingrese el ID de la habitación a liberar: ");
            char idHabitacion[10];
            leerCadena(idHabitacion, 10);
            LiberarHabitacion(habitaciones, idHabitacion);
            break;
        case 5:
            listarHabitaciones(habitaciones);
            break;
        default:
            break;
        }
    } while (opc != 6);

    return 0;
}