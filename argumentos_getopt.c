#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
 
/* Nombre de este programa.  */
const char* nombre_programa;
 
/*  Imprime la información de uso de este programa a stream
(típicamente stdout or stderr) y sale del programa con EXIT_CODE.
No retorna nada.  */
 
void imprimir_uso (FILE* stream, int exit_code) {
    fprintf (stream, "Usage:  %s options [ inputfile ... ]\n", nombre_programa);
    fprintf (stream,
        "  -h  --help            Display this usage information.\n"
        "  -o  --output filename Write output to file.\n"
        "  -v  --verbose         Print verbose messages.\n");
    exit (exit_code);
}
 
int main (int argc, char* argv[]) {
    int siguiente_opcion;
 
    /* Una cadena listando las opciones cortas válidas.  */
    const char* const opciones_cortas = "ho:v";
    /* Un arreglo describiendo las opciones largas válidas */
    const struct option opciones_largas[] = {
        { "help",     0, NULL, 'h' },
        { "output",   1, NULL, 'o' },
        { "verbose",  0, NULL, 'v' },
        { NULL,       0, NULL, 0   }   /* Requerido al final del arreglo.  */
    };
 
    /* El nombre del archivo que recibirá la salida del pograma o NULL
    para la salida estándar */
    const char* nombrearchivo_salida = NULL;
    /* Donde desplegar los mensajes verbosos.  */
    int verbose = 0;
 
    /* Nombre del programa a incorporar en los mensajes.
    El nombre está almacenado en argv[0].  */
    nombre_programa = argv[0];
 
    do {
        siguiente_opcion = getopt_long(argc, argv, opciones_cortas, opciones_largas, NULL);
        switch (siguiente_opcion) {
            case 'h':   /* -h or --help */
            /* El usaurio a solicitado información de uso. Imprimirla en la
            salida estándar y terminar normalmente (código 0) */
            imprimir_uso (stdout, 0);
 
            case 'o':   /* -o or --output */
            /* Esta opción toma un argumento, el nombre del archivo de salida */
            nombrearchivo_salida = optarg;
            break;
 
            case 'v':   /* -v or --verboso */
            verbose = 1;
            break;
 
            case '?':   /* El usuario especificó una opción inválida.  */
            /* Imprimir la información de uso al error estándar y salir
            con un código de salida de uno (terminación no normal) */
            imprimir_uso (stderr, 1);
 
            case -1:    /* Terminar opciones.  */
            break;
 
            default:    /* Algo inesperado.  */
            abort ();
        }
    } while (siguiente_opcion != -1);
 
    /* Se terminaron las opciones. OPTIND apunta al primer argumento que
    que no es opción. Como demostración, se imprimen si se especificó la
    opción verbose fue especificada.  */
    if (verbose) {
        int i;
        for (i = optind; i < argc; ++i)
        printf ("Argumento: %s\n", argv[i]);
    }
 
    /* El programa principal va aquí */
 
    return 0;
}