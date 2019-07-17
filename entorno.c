#include <stdio.h>
 
/* La variable ENVIRON contiene el ambiente. */
extern char** environ;
 
int main(int argc, char const *argv[]) {
    char** var;
    for (var = environ; *var != NULL; ++var) {
        printf("%s\n", *var);
    }
    return 0;
}