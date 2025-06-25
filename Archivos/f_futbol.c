/*La liga pro, tiene dificulatades para obtener estadisiticas de los partidos, comos los marcadores, los goleadores
del campeonato y la tabla de posiciciones
 
por lo cual ha buscao un ingeniero que solucione.
*/

#include <stdio.h>
#include <string.h>
#include "futbol.h"

void leerCadena(char *cadena, int num)
{
    fflush(stdin);
    fgets(cadena, num, stdin);

    int len = strlen(cadena) - 1;
    cadena[len] = '\0';
}

void inicializarEquipo(struct Equipo equipos[3])
{
    strcpy(equipos[0].nombre, "Barcelona");
    equipos[0].puntos = 0;
    equipos[0].partidosJugados = 0;
    equipos[0].golesFavor = 0;
    equipos[0].golesContra = 0;

    strcpy(equipos[1].nombre, "Emelec");
    equipos[1].puntos = 0;
    equipos[1].partidosJugados = 0;
    equipos[1].golesFavor = 0;
    equipos[1].golesContra = 0;

    strcpy(equipos[2].nombre, "Liga de Quito");
    equipos[2].puntos = 0;
    equipos[2].partidosJugados = 0;
    equipos[2].golesFavor = 0;
    equipos[2].golesContra = 0;

    guardarEquipo(equipos); // Guardar los equipos inicializados en el archivo
}

void inicializarJugador(struct Jugador jugadores[6], struct Equipo equipos[3])
{
   // Barcelona SC
    strcpy(jugadores[0].nombre, "Gonzalo Mastriani");
    jugadores[0].equipo = equipos[0]; // Asignar estructura completa
    jugadores[0].goles = 0;
 
    strcpy(jugadores[1].nombre, "Joao Rojas");
    jugadores[1].equipo = equipos[0];
    jugadores[1].goles = 0;
 
    // Emelec
    strcpy(jugadores[2].nombre, "Facundo Barceló");
    jugadores[2].equipo = equipos[1];
    jugadores[2].goles = 0;
 
    strcpy(jugadores[3].nombre, "Maicon Solís");
    jugadores[3].equipo = equipos[1];
    jugadores[3].goles = 0;
 
    // Liga de Quito
    strcpy(jugadores[4].nombre, "Alexander Alvarado");
    jugadores[4].equipo = equipos[2];
    jugadores[4].goles = 0;
 
    strcpy(jugadores[5].nombre, "Lisandro Alzugaray");
    jugadores[5].equipo = equipos[2];
    jugadores[5].goles = 0;

    guardarJugador(jugadores); // Guardar los jugadores inicializados en el archivo 

}

void guardarEquipo(struct Equipo *equipos)
{
    FILE *f;
    f = fopen("equipos.dat", "wb+"); // wb+ es para escribir y leer en binario
    fwrite(equipos, sizeof(struct Equipo), 3, f);
    fclose(f);
}

void guardarJugador(struct Jugador *jugadores)
{
    FILE *f;
    f = fopen("jugadores.dat", "wb+"); // wb+ es para escribir y leer en binario
    fwrite(jugadores, sizeof(struct Jugador), 6, f);
    fclose(f);
}   

void guardarPartidos(struct Partido *partidos, int contPartidos)
{
    FILE *f;
    f = fopen("partidos.dat", "wb+"); // wb+ es para escribir y leer en binario
    if (f != NULL) {
        fwrite(&contPartidos, sizeof(int), 1, f); // Guardar la cantidad de partidos
        fwrite(partidos, sizeof(struct Partido), contPartidos, f); // Guardar los partidos
        fclose(f);
    }
}

int leerPartidos(struct Partido partidos[5], int *contPartidos)
{
    FILE *f;
    f = fopen("partidos.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL)
    {
        *contPartidos = 0; // Si no existe el archivo, no hay partidos
        return 0; // Retornar 0 si no se pudo abrir el archivo
    }
    
    fread(contPartidos, sizeof(int), 1, f); // Leer la cantidad de partidos
    fread(partidos, sizeof(struct Partido), *contPartidos, f); // Leer los partidos del archivo
    fclose(f);
    return 1; // Retornar 1 si se leyeron los partidos correctamente
}

void imprimirEquipo(struct Equipo equipos[3])
{
    // Crear una copia del arreglo para ordenarlo sin modificar el original
    struct Equipo equiposOrdenados[3];
    for (int i = 0; i < 3; i++) {
        equiposOrdenados[i] = equipos[i];
    }
    
    // Ordenar por puntos (de mayor a menor)
    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (equiposOrdenados[i].puntos < equiposOrdenados[j].puntos) {
                struct Equipo temp = equiposOrdenados[i];
                equiposOrdenados[i] = equiposOrdenados[j];
                equiposOrdenados[j] = temp;
            }
        }
    }
    
    printf("\n=== TABLA DE POSICIONES ===\n");
    printf("Pos\tEquipo\t\t\tPuntos\tPJ\tGF\tGC\tDG\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < 3; i++)
    {
        int diferencia = equiposOrdenados[i].golesFavor - equiposOrdenados[i].golesContra;
        printf("%d\t%-20s\t%d\t%d\t%d\t%d\t%+d\n", 
               i + 1, 
               equiposOrdenados[i].nombre, 
               equiposOrdenados[i].puntos, 
               equiposOrdenados[i].partidosJugados, 
               equiposOrdenados[i].golesFavor, 
               equiposOrdenados[i].golesContra,
               diferencia);
    }
    printf("------------------------------------------------------------\n");
}

void imprimirJugador(struct Jugador jugadores[6])
{
    printf("\nJugadores disponibles:\n");
    printf("========================================\n");
    printf("#\tNombre\t\t\tEquipo\n");
    printf("========================================\n");
    for (int i = 0; i < 6; i++)
    {
        printf("%d\t%s\t\t%s\n", i, jugadores[i].nombre, jugadores[i].equipo.nombre);
    }
    printf("========================================\n");
}

int leerEquipo(struct Equipo equipos[3])
{
    FILE *f;
    f = fopen("equipos.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 0; // Retornar 0 si no se pudo abrir el archivo
    }
    fread(equipos, sizeof(struct Equipo), 3, f); // Leer los equipos del archivo
    fclose(f);
    return 1; // Retornar 1 si se leyeron los equipos correctamente
}

int leerJugador(struct Jugador jugadores[6])
{
    FILE *f;
    f = fopen("jugadores.dat", "rb+"); // rb+ es para leer y escribir en binario
    if (f == NULL)
    {
        printf("Error al abrir el archivo.\n");
        return 0; // Retornar 0 si no se pudo abrir el archivo
    }
    fread(jugadores, sizeof(struct Jugador), 6, f); // Leer los jugadores del archivo
    fclose(f);
    return 1; // Retornar 1 si se leyeron los jugadores correctamente
}

void realizarPartido(struct Partido partidos[], struct Jugador goleadores[], int numGoleadores, struct Equipo equipos[], int *contPartidos)
{
    int equipo1, equipo2;

    if (*contPartidos >= 5) {
        printf("No se pueden realizar más partidos, ya se alcanzó el límite de 5 partidos.\n");
        return; // Salir de la función si ya se alcanzó el límite
    }

    if (leerEquipo(equipos) == 0) {
        printf("No hay equipos disponibles para realizar un partido.\n");
        return; // Salir de la función si no hay equipos disponibles
    }

    if (leerJugador(goleadores) == 0) {
        printf("No hay jugadores disponibles para registrar goleadores.\n");
        return; // Salir de la función si no hay jugadores disponibles
    }

    mostrarEquiposSeleccion(equipos);
    printf("Seleccione el equipo 1 (0-2): ");
    scanf("%d", &equipo1);
    printf("Seleccione el equipo 2 (0-2): ");
    scanf("%d", &equipo2);
    if (equipo1 < 0 || equipo1 > 2 || equipo2 < 0 || equipo2 > 2 || equipo1 == equipo2) {
        printf("Selección de equipos inválida.\n");
        return; // Salir de la función si la selección es inválida
    }
    partidos[*contPartidos].equipo1 = equipo1; // Guardar índice del equipo 1
    partidos[*contPartidos].equipo2 = equipo2; // Guardar índice del equipo 2

    printf("Ingrese los goles del equipo 1: ");
    scanf("%d", &partidos[*contPartidos].golesEquipo1);
    printf("Ingrese quien metio los goles del equipo 1:\n");
    imprimirJugador(goleadores);
    for (int i = 0; i < partidos[*contPartidos].golesEquipo1; i++) {
        printf("Goleador %d: ", i + 1);
        int goleadorIndex;
        scanf("%d", &goleadorIndex);
        fflush(stdin); // Limpiar el buffer de entrada
        if (goleadorIndex < 0 || goleadorIndex >= numGoleadores) {
            printf("Índice de goleador inválido.\n");
            return; // Salir de la función si el índice es inválido
        }
        partidos[*contPartidos].goleadores[i] = goleadores[goleadorIndex];
    }

    printf("Ingrese los goles del equipo 2: ");
    scanf("%d", &partidos[*contPartidos].golesEquipo2);
    printf("Ingrese quien metio los goles del equipo 2:\n");
    imprimirJugador(goleadores);
    for (int i = 0; i < partidos[*contPartidos].golesEquipo2; i++) {
        printf("Goleador %d: ", i + 1);
        int goleadorIndex;
        scanf("%d", &goleadorIndex);
        fflush(stdin); // Limpiar el buffer de entrada
        if (goleadorIndex < 0 || goleadorIndex >= numGoleadores) {
            printf("Índice de goleador inválido.\n");
            return; // Salir de la función si el índice es inválido
        }
        partidos[*contPartidos].goleadores[i + partidos[*contPartidos].golesEquipo1] = goleadores[goleadorIndex];
    }

    (*contPartidos)++; // Incrementar el contador de partidos
    actualizarEstadisticas(partidos, equipos, *contPartidos); // Actualizar estadísticas de los equipos
    guardarPartidos(partidos, *contPartidos); // Guardar los partidos en el archivo
    printf("Partido registrado exitosamente.\n");
}

void actualizarEstadisticas(struct Partido partidos[], struct Equipo equipos[], int contPartidos)
{
    // Solo procesar el último partido (contPartidos - 1)
    int ultimoPartido = contPartidos - 1;
    
    if (ultimoPartido < 0) return; // No hay partidos para procesar
    
    // Actualizar puntos y goles del último partido
    if (partidos[ultimoPartido].golesEquipo1 > partidos[ultimoPartido].golesEquipo2) {
        equipos[partidos[ultimoPartido].equipo1].puntos += 3; // Equipo 1 gana
    } else if (partidos[ultimoPartido].golesEquipo1 < partidos[ultimoPartido].golesEquipo2) {
        equipos[partidos[ultimoPartido].equipo2].puntos += 3; // Equipo 2 gana
    } else {
        equipos[partidos[ultimoPartido].equipo1].puntos += 1; // Empate
        equipos[partidos[ultimoPartido].equipo2].puntos += 1;
    }

    equipos[partidos[ultimoPartido].equipo1].golesFavor += partidos[ultimoPartido].golesEquipo1;
    equipos[partidos[ultimoPartido].equipo1].golesContra += partidos[ultimoPartido].golesEquipo2;
    equipos[partidos[ultimoPartido].equipo2].golesFavor += partidos[ultimoPartido].golesEquipo2;
    equipos[partidos[ultimoPartido].equipo2].golesContra += partidos[ultimoPartido].golesEquipo1;

    equipos[partidos[ultimoPartido].equipo1].partidosJugados++;
    equipos[partidos[ultimoPartido].equipo2].partidosJugados++;

    guardarEquipo(equipos); // Guardar las estadísticas actualizadas en el archivo
}

void mostrarEquiposSeleccion(struct Equipo equipos[3])
{
    printf("Equipos disponibles:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("%d - %s\n", i, equipos[i].nombre);
    }
}

void mostrarTablaGoleadores(struct Partido partidos[], int contPartidos)
{
    struct {
        char nombre[30];
        char equipo[30];
        int goles;
    } goleadores[50]; // Máximo 50 goleadores únicos
    
    int totalGoleadores = 0;
    
    // Recopilar todos los goleadores de todos los partidos
    for (int i = 0; i < contPartidos; i++) {
        int totalGolesPartido = partidos[i].golesEquipo1 + partidos[i].golesEquipo2;
        
        for (int j = 0; j < totalGolesPartido; j++) {
            // Buscar si el goleador ya existe en la lista
            int encontrado = 0;
            for (int k = 0; k < totalGoleadores; k++) {
                if (strcmp(goleadores[k].nombre, partidos[i].goleadores[j].nombre) == 0) {
                    goleadores[k].goles++;
                    encontrado = 1;
                    break;
                }
            }
            
            // Si no existe, agregarlo
            if (!encontrado && totalGoleadores < 50) {
                strcpy(goleadores[totalGoleadores].nombre, partidos[i].goleadores[j].nombre);
                strcpy(goleadores[totalGoleadores].equipo, partidos[i].goleadores[j].equipo.nombre);
                goleadores[totalGoleadores].goles = 1;
                totalGoleadores++;
            }
        }
    }
    
    // Ordenar goleadores por cantidad de goles (de mayor a menor)
    for (int i = 0; i < totalGoleadores - 1; i++) {
        for (int j = i + 1; j < totalGoleadores; j++) {
            if (goleadores[i].goles < goleadores[j].goles) {
                // Intercambiar
                char tempNombre[30], tempEquipo[30];
                int tempGoles;
                
                strcpy(tempNombre, goleadores[i].nombre);
                strcpy(tempEquipo, goleadores[i].equipo);
                tempGoles = goleadores[i].goles;
                
                strcpy(goleadores[i].nombre, goleadores[j].nombre);
                strcpy(goleadores[i].equipo, goleadores[j].equipo);
                goleadores[i].goles = goleadores[j].goles;
                
                strcpy(goleadores[j].nombre, tempNombre);
                strcpy(goleadores[j].equipo, tempEquipo);
                goleadores[j].goles = tempGoles;
            }
        }
    }
    
    printf("\n=== TABLA DE GOLEADORES ===\n");
    printf("Pos\tJugador\t\t\tEquipo\t\t\tGoles\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < totalGoleadores; i++) {
        printf("%d\t%-20s\t%-20s\t%d\n", 
               i + 1, 
               goleadores[i].nombre, 
               goleadores[i].equipo, 
               goleadores[i].goles);
    }
    printf("------------------------------------------------------------\n");
}


