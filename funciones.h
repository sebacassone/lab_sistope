#include <stdio.h>


//Entradas: int posicion_particula, int energia_particula, int posicion_arreglo, int energia_arreglo int largo_arreglo
//Salida: float que la energia que queda en la posicion del arreglo
//Funcionamiento: Calcula la energia residual que llega a la celda, si es mayor al umbral minimo de energia, se suma la energia del arreglo con el residuo de energia

float suma_formula(int posicion_particula, int energia_particula, int posicion_arreglo,  float energia_arreglo, int largo_arreglo);




int o_proporcional(float energia_maxima, float energia_material);
