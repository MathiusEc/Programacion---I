/*Busca un elemento en un arreglo recorriéndolo uno por uno.*/

/*Dado un arreglo con números de teléfono, verifica si el número ingresado está en la lista.*/

#include <stdio.h>
#define TAM 10

int busquedaLineal(int arr[], int n, int clave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == clave) {
            return i;
        }
    }
    return -1;
}

int main() {
    int telefonos[TAM] = {987654321, 123456789, 112233445, 998877665, 556677889, 223344556, 667788990, 889900112, 334455667, 445566778};
    int numero;

    printf("Ingrese el número de teléfono a buscar: ");
    scanf("%d", &numero);

    int resultado = busquedaLineal(telefonos, TAM, numero);

    if (resultado != -1) {
        printf("El número está registrado en la posición: %d\n", resultado);
    } else {
        printf("El número no está registrado.\n");
    }
    return 0;
}