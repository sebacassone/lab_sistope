#ifndef SALIDA_H
#define SALIDA_H
#include "lectura.h"

void escribir_archivo(char *nombre_archivo, float *arreglo_posiciones, int N, int posicion_max, float max);

void salida_consola(int N, char *input_file, char *output_file, int show, Celda *arreglo_ataque, float *arreglo_posiciones, float max);

#endif