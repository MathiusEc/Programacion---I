struct Equipo {
    char nombre[30];
    int puntos;
    int partidosJugados;
    int golesFavor;
    int golesContra;
};

struct Jugador {
    char nombre[30];
    int goles;
    struct Equipo equipo; // El jugador pertenece a un equipo
};

struct Partido {
    int equipo1; // Índice del equipo 1
    int equipo2; // Índice del equipo 2
    int golesEquipo1;
    int golesEquipo2;
    struct Jugador goleadores[10]; // Tamaño fijo para el arreglo
};


void leerCadena(char *cadena, int num);
void inicializarEquipo(struct Equipo equipos[3]);
void inicializarJugador(struct Jugador jugadores[6], struct Equipo equipos[3]);
void guardarEquipo(struct Equipo *equipos);
void guardarJugador(struct Jugador *jugadores);
void imprimirEquipo(struct Equipo equipos[3]);
void imprimirJugador(struct Jugador jugadores[6]);
int leerEquipo(struct Equipo equipos[3]);
int leerJugador(struct Jugador jugadores[6]);
void realizarPartido(struct Partido partidos[], struct Jugador goleadores[], int numGoleadores, struct Equipo equipos[], int *contPartidos);
void actualizarEstadisticas(struct Partido partidos[], struct Equipo equipos[], int contPartidos);
void mostrarEquiposSeleccion(struct Equipo equipos[3]);
void mostrarTablaGoleadores(struct Partido partidos[], int contPartidos);
void guardarPartidos(struct Partido *partidos, int contPartidos);
int leerPartidos(struct Partido partidos[5], int *contPartidos);


