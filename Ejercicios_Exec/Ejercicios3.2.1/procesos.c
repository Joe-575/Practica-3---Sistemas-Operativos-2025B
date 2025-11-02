#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ejecutarNuevoProc(char *programa, char *arg_list[]);

int main(){
    
    char *programa = "ls";
    char *arg_list[] = {"ls", "-l", NULL};

    // Llama a ejecutarNuevoProc para crear el hijo y ejecutar el programa
    int pid = ejecutarNuevoProc(programa, arg_list);
    
    // El padre espera a que el hijo termine
    wait(NULL);
    
    // Imprime que el proceso hijo se ha ejecutado
    fprintf(stdout, "El proceso hijo con PID %d se ha ejecutado \n", pid);
    
    return 0;
}

// Esta función crea un proceso hijo y ejecuta el programa usando execvp
int ejecutarNuevoProc(char *programa, char *arg_list[]){
    int pid = fork();  // Crear el proceso hijo
    switch(pid){
        case -1:
            // Error al crear el proceso hijo
            fprintf(stderr, "No se pudo crear el proceso\n");
            exit(1);
        
        case 0:
            // En el proceso hijo, usamos execvp para ejecutar el comando
            execvp(programa, arg_list);
			
            // Si execvp falla, se imprime el mensaje de error
            fprintf(stderr, "Error al ejecutar exec\n");
            exit(1);  // Termina el hijo en caso de error
            break;
        
        default:
            // En el proceso padre, devuelve el PID del hijo
            return pid;
    }
}
