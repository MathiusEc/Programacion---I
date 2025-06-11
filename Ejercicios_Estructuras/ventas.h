/* Se desea desarrollar un sistema de gestion de ventas que tenga las siguientes funcionalidades, visualizar productos, crear venta, 
listar o imprimir las ventas y buscar las ventas.asm

Los atributos de la venta son los siguientes: nombre del cliente, cedula, total de la venta, productos vendidos.
Los atributos de la producto son los siguientes: nombre del producto, precio.asm

Nota: Los productos deben estar predefinidos, minimos 2, maximo 5
*/
#define MAX_PRODUCTOS 3

struct producto
{
    char nombre_producto[50];
    float precio;
    int cantidad;  // ← Agregar este campo
};

struct ventas
{
    char nombre_cliente[50];
    char cedula[11];
    float total_venta;
    struct producto productos_vendidos[MAX_PRODUCTOS]; // Asumiendo un máximo de 5 productos por venta
};


void leerCadena(char *cadena, int num);
void listarProductos(struct producto productos[]);
void crearVenta(struct ventas *venta, struct producto productos[], int numero_venta);
void listarVentas(struct ventas ventas[], int contador);
struct ventas *buscarVenta(struct ventas ventas[], int contador, char nombre_cliente[]);
void imprimirsolouno(struct ventas *venta);