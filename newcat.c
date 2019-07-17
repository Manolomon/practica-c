#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
 
void imprimir_uso (FILE* stream, int exit_code) {
    fprintf (stream, "Usage: ./newcat [OPTION]... [FILE]...\n");
    fprintf (stream,
        "  -h  --help            Display this usage information.\n");
    exit (exit_code);
}
 
int main (int argc, char* argv[]) {
    int siguiente_opcion;
    char ch;
    FILE *fp;
    const char* const opciones_cortas = "ho:v";
    const struct option opciones_largas[] = {
        { "help",     0, NULL, 'h' },
        { NULL,       0, NULL, 0   }
    };

    if (argc == 1) {
        imprimir_uso(stderr, 1);
    }
 
    do {
        siguiente_opcion = getopt_long(argc, argv, opciones_cortas, opciones_largas, NULL);
        switch (siguiente_opcion) {
            case 'h':
            imprimir_uso (stdout, 0);
 
            case '?':
            imprimir_uso (stderr, 1);
 
            case -1:
            break;
 
            default:
            abort ();
        }
    } while (siguiente_opcion != -1);
    int i;
    for (i = optind; i < argc; ++i) {
        printf ("\nArgumento: %s\n", argv[i]);
        fp = fopen(argv[i], "r"); // Permiso de sólo lectura (read)
        if (fp == NULL) {
            perror("Error while opening the file.\n");
            exit(EXIT_FAILURE);
        }
        while((ch = fgetc(fp)) != EOF){ 
            printf("%c", ch);
        }
        fclose(fp);
    }
    return 0;
}
