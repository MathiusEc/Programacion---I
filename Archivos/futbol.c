/*La liga pro, tiene dificulatades para obtener estadisiticas de los partidos, comos los marcadores, los goleadores
del campeonato y la tabla de posiciciones
 
por lo cual ha buscao un ingeniero que solucione.
*/

#include <stdio.h>
#include <string.h>
#include "futbol.h"

int main (int argc, char *argv[]) {
    struct Equipo equipos[3];
    struct Jugador jugadores[6];
    struct Partido partidos[5];

    int opc;
    int contPartidos = 0; // Contador de partidos realizados
    
    
    
    do
    {
        printf("Bienvenido al sistema de gestión de partidos de fútbol.\n");
        printf("1. Inicializar equipos\n");
        printf("2. Inicializar jugadores\n");
        printf("3. Imprimir tabla de posiciones\n");
        printf("4. Imprimir jugadores\n");
        printf("5. Realizar partido\n");
        printf("6. Mostrar tabla de goleadores\n");
        printf("7. Salir\n");
        scanf("%d", &opc);
        fflush(stdin); // Limpiar el buffer de entrada
        

        switch (opc)
        {
        case 1:
            inicializarEquipo(equipos);
            break;
        case 2:
            inicializarJugador(jugadores, equipos);
            break;

        case 3:
            if (leerEquipo(equipos) == 0)
            {
                printf("No hay equipos disponibles\n");
            }
            else
            {
                imprimirEquipo(equipos);
            }
            break;

        case 4:
            if (leerJugador(jugadores) == 0)
            {
                printf("No hay jugadores disponibles\n");
            }
            else
            {
                imprimirJugador(jugadores);
            }
            break;

        case 5:
            realizarPartido(partidos, jugadores, 6, equipos, &contPartidos);
            break;

        case 6:
            leerPartidos(partidos, &contPartidos);
            mostrarTablaGoleadores(partidos, contPartidos);
            break;

        default:
            break;
        }
    } while (opc != 7);
    
    


    return 0;
}