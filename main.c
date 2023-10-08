#include <stdio.h>
#include <stdlib.h> // Se utiliza para atoi
#include <getopt.h>
#include "lectura.h"
#include "funciones.h"

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
            // se verifica que n sea un numero entero
            
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
//encuentra el valor maximo del arreglo_posiciones
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

    // funcion para crear un archivo

    FILE *archivo = fopen("output.txt", "w");
    if (archivo == NULL)
    {
        printf("Error: No se pudo crear el archivo de salida\n");
        exit(1);
    }
    // Se imrpime el material com mas energia
    fprintf(archivo,"El material con más energía es el material %d : %f \n", posicion_max, max);
    // Se imprime el arreglo de posiciones en el archivo de salida
    for (int i = 0; i < N; i++)
    {
        fprintf(archivo, "%d:  %f\n", i, arreglo_posiciones[i]);
    }


    // Se muestra el arreglo por consola
    if (show == 1)
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
            printf("Posición: %d, Valor: %f | ",  i, arreglo_posiciones[i]);

            for (int t = 0; t < o_proporcional(max, arreglo_posiciones[i]); t++){
                 printf("o");
            }
            printf("\n");
               
        }
            
    }
    return 0;
}
