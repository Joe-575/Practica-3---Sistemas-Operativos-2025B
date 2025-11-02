#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();  // Crear un proceso hijo

    if (pid < 0) {  // Verificar si hubo un error al crear el hijo
        fprintf(stderr, "Error al crear el proceso\n");
        exit(1);
    }

    if (pid == 0) {  // Si estamos en el proceso hijo
        printf("Proceso hijo: Listando los procesos del sistema...\n");
        // Ejecutamos el comando 'ps aux' para listar los procesos del sistema
        int result = system("ps aux");

        // Verificamos si hubo un error al ejecutar el comando
        if (result == -1) {
            fprintf(stderr, "Error al ejecutar el comando\n");
            exit(1);
        }

        exit(0);  // El hijo termina aquí
    } else {  // Si estamos en el proceso padre
        // Esperamos a que el hijo termine
        wait(NULL);
        printf("Proceso padre: El proceso hijo ha terminado\n");
    }

    return 0;
}
