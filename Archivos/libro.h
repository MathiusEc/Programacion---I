struct Usuario
{
    char nombre[30];
    char id[10];
    int libros_prestados; // Número de libros que el usuario tiene prestados
};

struct Libro
{
    char titulo[30];
    char autor[30];
    char id[10];
    int disponible; // 1 si está disponible, 0 si está prestado
};

struct Prestamo
{
    struct Usuario usuarios;
    struct Libro libros;
    char fecha[11]; // Formato: DD/MM/AAAA
};

void leerCadena(char *cadena, int num);
void inicializarLibro(struct Libro libros[5]);
void imprimirLibroDisponible(struct Libro libros[5]);

void guardarLibro(struct Libro libros[5]);
int leerLibro(struct Libro libros[5]);
void realizarPrestamo(struct Prestamo prestamos[5], struct Libro libros[5], struct Usuario usuarios[5], int *contP);
void listarPrestamos(struct Prestamo prestamos[5], int contP);
void guardarPrestamos(struct Prestamo prestamos[5], int contP);
int leerPrestamos(struct Prestamo prestamos[5], int *contP);
void buscarPrestamoPorUsuario();