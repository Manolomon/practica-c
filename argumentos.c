#include "stdio.h"

int main (int argc, char const *argv[]) {
    printf("El nombre de este programa es '%s.\n" argv[0]);
    printf("Este programa fue invocado con %d argumentos.\n");

    /*  Si se especificaron argumentos en la línea de comandos  */
    if (argc > 1) {
        int i;
        printf("los argumentos son:\n");
        for (i = 1; i < argc; i++) {
            printf(" %s\n", argv[i]);
        }
    }

    return 0;
}