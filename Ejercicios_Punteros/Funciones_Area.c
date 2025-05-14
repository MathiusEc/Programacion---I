#include <stdio.h>
#include <math.h>
#include "FUnciones_Area.h"

void leerComponentes(float puntos[][2]) // se le deja vacio el primer argumento para evitar errores
{
    for (int i = 0; i < 3; i++)
    {
        printf("Ingrese la componente X del punto %d: ", i + 1);
        scanf("%f", &puntos[i][0]);
        printf("Ingrese la componente Y del punto %d: ", i + 1);
        scanf("%f", &puntos[i][1]);
    }
}

float distancia(float x1, float y1, float x2, float y2)
{
    float d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    return d;
}

void calcularDistancia(float *a, float *b, float *c, float puntos[][2])
{
    *a = distancia(puntos[0][0], puntos[0][1], puntos[2][0], puntos[2][1]);
    *b = distancia(puntos[1][0], puntos[1][1], puntos[2][0], puntos[2][1]);
    *c = distancia(puntos[0][0], puntos[0][1], puntos[1][0], puntos[1][1]);
}

float perimetro(float *s, float *p, float a, float b, float c)
{
    *p = (a + b + c);
    *s = *p / 2;
}

float area(float s, float a, float b, float c)
{
    float area = sqrt(s * (s - a) * (s - b) * (s - c));
    return area;
}
