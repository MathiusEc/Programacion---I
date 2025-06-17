/*Se desea desarrollar un sistema de gestion de ventas  para una tienda de electrodomésticos y deberá tener las siguientes funcionalidades: 

1) Listar los productos
2) Realizar una venta
3) Ver todas las ventas (Total de ventas
4) Buscar las ventas por cedula del cliente

Las ventas tendran los siguientes atributos: 
nombre del cliente, cedula del cliente, cantidad de productos (máximo 5), total de la venta, productos vendidos

los productos deberan tener:
nombre y precio

Nota: Los productos son predefinidos*/


struct Venta {
    char nombre_cliente[50];
    char cedula_cliente[20];
    int cantidad_productos; // Máximo 5
    float total_venta;
    char productos_vendidos[5][50]; // Nombres de los productos vendidos
};

struct Producto {
    char nombre[50];
    float precio;
};

void leerCadena(char *cadena, int num);
void listarProductos(struct Producto productos[], int num_productos);
void realizarVenta(struct Venta *venta, struct Producto productos[], int contadorProductos);
void listarVentas(struct Venta ventas[], int total_ventas);
struct Venta *buscarVenta(struct Venta ventas[], int total_ventas, char cedula_cliente[]);
void imprimirsolouno(struct Venta *venta);