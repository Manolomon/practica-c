#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, char const *argv[]) {
    char* nombre_servidor = getenv("SERVER_NAME");
    if (nombre_servidor == NULL) {
        /* La variable SERVER_NAME no estaba configurada. Usar el default. */
        nombre_servidor = "servidor.mi.organizacion.com";
    }
    printf("accediendo al servidor %s\n", nombre_servidor);
    return 0;
}