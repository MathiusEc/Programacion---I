/*de un triangulo que esta en un plano cartesiano, se debe obtener el área*/

#include <stdio.h>
#include <math.h>
#include "FUnciones_Area.h"

int main (int argc, char *argv[]) {

    float puntos[3][2]; // matriz de 3x2
    float l1, l2, l3; // lados del triangulo
    float s, p; // semiperimetro y perimetro
    float ar; // area del triangulo

    leerComponentes(puntos);

    calcularDistancia(&l1, &l2, &l3, puntos);

    perimetro(&s, &p, l1, l2, l3);

    ar = area(s, l1, l2, l3);

    printf("El perimetro del triangulo es: %.2f\n", p);
    printf("El area del triangulo es: %.2f\n", ar);
    return 0;
}