struct Contactos
{
    char nombre[50];
    char telefono[15];
    char email[50];
};

void leerCadena(char *cadena, int num);
void registrarContacto(struct Contactos contactos[], int *contador);
void listarContactos(struct Contactos contactos[], int contador);
struct Contactos *buscarContacto(struct Contactos contactos[], int contador, char nombreBuscado[]);
void modificarContacto(struct Contactos *contacto);
void eliminarContacto(struct Contactos contactos[], int *contador, char nombreBuscado[]);