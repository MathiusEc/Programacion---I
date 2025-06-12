
struct Huesped
{
    char nombre[50];
    char documento[20]; // Ejemplo: DNI, Pasaporte
    char telefono[15];
};


struct Habitacion
{
    char id[10];
    char tipo[20]; // Ejemplo: "Individual", "Doble", "Suite"
    float precioPorNoche;
    int tiempo;
    char estado[20]; 
    struct Huesped huesped; // Huésped asociado a la habitación
};

void leerCadena(char *cadena, int num);
void crearHuesped(struct Huesped *huesped);
void reservarHabitacion(struct Habitacion habitaciones[], struct Huesped *huesped, int *ubicacion);
void listarReservas(struct Habitacion habitaciones[], int ubicacion);
struct Habitacion* buscarReservaPorHuesped(struct Habitacion habitaciones[], char documento[], int ubicacion);
void LiberarHabitacion(struct Habitacion habitaciones[], char id[]);
void listarHabitaciones(struct Habitacion habitaciones[]);
void imprimirunasolaReserva(struct Habitacion *habitacion);