#include <stdio.h>
#include <stdlib.h> // Se utiliza para atoi
#include <getopt.h>
#include "lectura.h"
#include "funciones.h"
#include "salida.h"

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
            // Se verifica que n sea un numero entero
            if (N < 0)
            {
                printf("Error: N debe ser mayor a 0\n");
                return 1;
            }
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
            show = 1;
            break;
        default:
            // Se muestra un mensaje de error
            printf("Error: Opción no válida\n");
            break;
        }
    }

    // Se lee el archivo de entrada y se crea un arreglo con las posiciones.
    Celda *arreglo_ataque = leer_archivo(input_file);
    float *arreglo_posiciones = (float *)malloc(sizeof(float) * N);
    if (arreglo_posiciones == NULL)
    {
        printf("Error: No se pudo crear el arreglo de posiciones\n");
        exit(1);
    }
    if (arreglo_ataque == NULL)
    {
        printf("Error: No se pudo crear el arreglo de ataque\n");
        exit(1);
    }

    // Se comienza a hacer se hace dos ciclos for se recorre todo el arreglo aplicandole la ecuación.
    // Se guarda el resultado en un arreglo de posiciones.
    for (int i = 0; i < arreglo_ataque[0].largo_del_arreglo; i++)
    {
        for (int j = 0; j < N; j++)
        {
            arreglo_posiciones[j] = suma_formula(arreglo_ataque[i].posicion, arreglo_ataque[i].valor, j, arreglo_posiciones[j], N);
        }
    }
    // Encuentra el valor maximo del arreglo_posiciones
    float max = 0;
    int posicion_max = 0;
    for (int i = 0; i < N; i++)
    {
        if (arreglo_posiciones[i] > max)
        {
            max = arreglo_posiciones[i];
            posicion_max = i;
        }
    }

    // Se escribe el archivo de salida
    escribir_archivo(output_file, arreglo_posiciones, N, posicion_max, max);

    // Se muestra el arreglo por consola
    if (show == 0)
    {
        return 0;
    }
    salida_consola(N, input_file, output_file, show, arreglo_ataque, arreglo_posiciones, max);

    return 0;
}
