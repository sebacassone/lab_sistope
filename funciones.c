#include "funciones.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Entradas: int posicion_particula, int energia_particula, int posicion_arreglo,
// int energia_arreglo int largo_arreglo
// Salida: float que la energia que queda en la posicion del arreglo
// Funcionamiento: Calcula la energia residual que llega a la celda, si es mayor
// al umbral minimo de energia, se suma la energia del arreglo con el residuo de energia.
double suma_formula(int posicion_particula, int energia_particula, int posicion_arreglo, double energia_arreglo, int largo_arreglo)
{
    double energia_particula_float = (double)energia_particula;
    double largo_arreglo_float = (double)largo_arreglo;

    double raiz = sqrt(abs(posicion_particula - posicion_arreglo) + 1); // se transforma la energia de la particula a float

    double residuo_energia = ((1000 * energia_particula_float) / (largo_arreglo_float * raiz)); // se aplica la formula entregada en enunciado
    double min_energy = (pow(10, -3) / largo_arreglo);                                          // se calcula el umbral minimo de energia

    if (residuo_energia >= min_energy)
    { // si el residuo de energia es mayor al minimo, se le suma a la energia ya existente del material
        return energia_arreglo + residuo_energia;
    }
    else
    {
        return energia_arreglo; // si no, se devuelve la energia del material
    }
}

// Entradas: float energia_maxima, float energia_material
// Salida: int porcentaje de o
// Funcionamiento: Calcula la cantidad de "o" que deberia imprimir considerando como
// 100% la energia maxima y la energia del material como el porcentaje de "o" que se
// debe imprimir.
int o_proporcional(double energia_maxima, double energia_material)
{
    double porcentaje_o = ((energia_material * 100) / energia_maxima);
    return (int)porcentaje_o;
}
