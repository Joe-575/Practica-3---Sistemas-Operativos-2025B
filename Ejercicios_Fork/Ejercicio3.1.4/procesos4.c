#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijoHasAlgo(int numero);

int main() {
    int i, pid;
    int padre_pid = getpid();
    printf("---> INICIO DEL PROCESO PADRE <--- \n");
    printf("\n PID del padre: %d\n", padre_pid);

    /* Evitar duplicar buffers al hacer fork */
    fflush(NULL);

    for (i = 1; i <= NUM_PROC; i++) {
        pid = fork();  // Crear el hijo

        switch (pid) {
            case -1:
                fprintf(stderr, "Error al crear el proceso\n");
                exit(1);

            case 0:
                // Código para los hijos
                hijoHasAlgo(i);
                exit(0);  // El hijo termina aquí, no ejecuta nada más.

            default:
                // Solo el padre debe imprimir la creación de los hijos
                if (pid > 0) {
                    printf(" Padre crea el hijo %d con PID: %d \n", i, pid);
                    /* Esperar a este hijo antes de crear el siguiente (salida ordenada) */
                    waitpid(pid, NULL, 0);
                }
                break;
        }
    }

    printf("\n Todos los hijos han terminado\n Fin del proceso padre con PID: %d \n", padre_pid);
    return 0;
}

void hijoHasAlgo(int numero) {
    int i, MAX = 10;

    printf("\n Ejecutando el hijo %d:\n", numero);

    switch (numero) {
        case 1:  // El hijo 1: cuenta números pares
            printf("Contando números pares del 1 al %d: \n", MAX * 2);
            for (i = 1; i <= MAX; i++) {
                printf(" %d\t", i * 2);
            }
            break;
        case 2:  // El hijo 2: cuenta números impares
            printf("Contando números impares del 1 al %d: \n", MAX * 2);
            for (i = 1; i <= MAX; i++) {
                printf(" %d\t", i * 2 - 1);
            }
            break;

        case 3:  // El hijo 3: cuenta números del 1 al 10
            printf("Contando números del 1 al %d: \n", MAX);
            for (i = 1; i <= MAX; i++) {
                printf(" %d\t", i);
            }
            break;
    }
    printf("\n");
}
