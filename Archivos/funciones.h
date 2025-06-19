
struct Cliente
{
    char nombre[20];
    int cedula;
};


struct Producto
{
    char nombre[20];
    float precio;
};

struct Venta
{
    struct Cliente clientes;
    int num_produ;
    struct Producto productos[5];
    float total;
};


void leerCadena(char *cadena, int num);
void inicializarProducto(struct Producto productos[5]);
void imprimirProducto(struct Producto productos[5]);