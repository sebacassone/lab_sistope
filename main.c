#include <stdio.h>
#include <stdlib.h> // Se utiliza para atoi
#include <getopt.h>
#include "lectura.h"

int main(int argc, char *argv[])
{
    // Se declaran variables y se inicializan
    int option;
    int N = 0;
    char *input_file = NULL;
    char *output_file = NULL;
    int show = 0;
    // Se utiliza get opt para extraer -N con el número de celdas
    // -i con el nombre del archivo de entrada, -o con el nombre del archivo de salida
    // -D que permite ver por consola el resultado.
    while ((option = getopt(argc, argv, "N:i:o:D")) != -1)
    {
        switch (option)
        {
        case 'N':
            // Se guarda el número de celdas
            N = atoi(optarg);
            break;
        case 'i':
            // Se guarda el nombre del archivo de entrada
            input_file = optarg;
            break;
        case 'o':
            // Se guarda el nombre del archivo de salida
            output_file = optarg;
            break;
        case 'D':
            // Se guarda la opción de mostrar por consola
            show = 1;
            break;
        default:
            // Se muestra un mensaje de error
            printf("Error: Opción no válida\n");
            break;
        }
    }

    // Se lee el archivo de entrada
    Celda *arreglo = leer_archivo(input_file);
    // Se muestra el arreglo por consola
    if (show == 1)
    {
        // Entrada de getopt
        printf("N: %d\n", N);
        printf("Input file: %s\n", input_file);
        printf("Output file: %s\n", output_file);
        printf("Show: %d\n", show);

        // Se imprime el arreglo de Celdas
        for (int i = 0; i < N; i++)
        {
            printf("Posición: %d, Valor: %d\n", arreglo[i].posicion, arreglo[i].valor);
        }
    }
    return 0;
}