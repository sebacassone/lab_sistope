#include "funciones.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float suma_formula(int posicion_particula, int energia_particula, int posicion_arreglo, float energia_arreglo, int largo_arreglo)
{
    float energia_particual_float = (float)energia_particula;
    float peo = abs(posicion_particula - posicion_arreglo) + 1;                              // se transforma la energia de la particula a float
    float residuo_energia = (10e-3 * energia_particual_float) / (largo_arreglo * sqrt(peo)); // se aplica la formula entregada en enunciado
    float min_energy = ((10e-3) / largo_arreglo);                                            // se calcula el umbral minimo de energia

    if (residuo_energia >= min_energy)
    { // si el residuo de energia es mayor al minimo, se le suma a la energia ya existente del material
        return energia_arreglo + residuo_energia;
    }
    else
    {
        return energia_arreglo; // si no, se devuelve la energia del material
    }
}

int o_proporcional(float energia_maxima, float energia_material)
{
    float porcentaje_o = ((energia_material * 100) / energia_maxima);
    return (int)porcentaje_o;
}
