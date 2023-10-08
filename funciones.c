#include "funciones.h"
#include <stdio.h>
#include <math.h>


float suma_formula(int posicion_particula, int energia_particula, int posicion_arreglo, float energia_arreglo ,int largo_arreglo){
    float energia_particual_float = (float)energia_particula;
    float residuo_energia = (10e-3 * energia_particual_float)/ (largo_arreglo * sqrt(abs(posicion_particula - posicion_arreglo) + 1));
    float min = ((10e-3)/largo_arreglo);

    if (residuo_energia  >= min){
        return energia_arreglo + residuo_energia;
    }
    else
    {
        return energia_arreglo;
    }
    
   
}

int o_proporcional(float energia_maxima, float energia_material){
    float porcentaje_o = ((energia_material *100)/energia_maxima);
    return (int)porcentaje_o;
}
