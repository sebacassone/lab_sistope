#include <stdio.h>
#include <stdlib.h>
#include "salida.h"
#include "lectura.h"
#include "funciones.h"

void escribir_archivo(char *nombre_archivo, float *arreglo_posiciones, int N, int posicion_max, float max)
{
    // funcion para crear un archivo

    FILE *archivo = fopen(nombre_archivo, "w");
    if (archivo == NULL)
    {
        printf("Error: No se pudo crear el archivo de salida\n");
        exit(1);
    }

    // Se imrpime el material com mas energia
    fprintf(archivo, "El material con más energía es el material %d : %f \n", posicion_max, max);
    // Se imprime el arreglo de posiciones en el archivo de salida
    for (int i = 0; i < N; i++)
    {
        fprintf(archivo, "%d:  %f\n", i, arreglo_posiciones[i]);
    }
}

void salida_consola(int N, char *input_file, char *output_file, int show, Celda *arreglo_ataque, float *arreglo_posiciones, float max)
{
    // Entrada de getopt
    printf("N: %d\n", N);
    printf("Input file: %s\n", input_file);
    printf("Output file: %s\n", output_file);
    printf("Show: %d\n", show);

    printf("Se imprime el arreglo de celdas\n");
    // Se imprime el arreglo de Celdas
    for (int i = 0; i < arreglo_ataque[0].largo_del_arreglo; i++)
    {
        printf("Posición: %d, Valor: %d\n", arreglo_ataque[i].posicion, arreglo_ataque[i].valor);
    }

    printf("Se imprime el arreglo de posiciones\n");
    // Se imprime arreglo de posiciones con su grafico
    for (int i = 0; i < N; i++)
    {
        printf("Posición: %d, Valor: %f | ", i, arreglo_posiciones[i]);

        for (int t = 0; t < o_proporcional(max, arreglo_posiciones[i]); t++)
        {
            printf("o");
        }
        printf("\n");
    }
}