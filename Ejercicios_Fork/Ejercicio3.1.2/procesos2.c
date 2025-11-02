#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>

int main(){
	int pid;
	int k = 0;
	int pipefd[2];;
	
	//Creaciòn del pipe
	if(pipe(pipefd) == -1){
		printf("Erroe al crear el pipe \n");
		exit(1);
	}

	pid = fork();

	switch(pid){
		case -1: //ha habido un error
			printf("No se ha podido crear el proceso hijo\n");
			break;

		case 0: // es el proceso hijo
			//Proceso hijo: registra los valores en un archivo
			
			close(pipefd[1]);//cerrar extremo de escritura del hijo

			FILE *archivo = fopen("valores.txt", "w");
			if(archivo == NULL){
				printf("Error al abrir el archivo \n");
				exit(1);
			}


			int valorRecibido;
			for(int i=1; i<=10;i++){
				read(pipefd[0], &valorRecibido, sizeof(int));
				fprintf(archivo, "%d\n",valorRecibido);
				printf("Hijo: Registrado valor %d en el archivo \n",valorRecibido);
				sleep(1);
			}

			fclose(archivo);
			close(pipefd[0]); //cerrar extremo de lectura
			printf("Hijo: Archivo guardado\n");
			break;

		default: // distinto de cero es el padre
			 close(pipefd[0]); //Cerrar extremo de lectura del padre
			 for(int i = 1; i<=10; i++){
			 	k +=10;
				printf("Padre: Variable incrementada a %d \n", k);
				write(pipefd[1], &k, sizeof(int));
				sleep(1);
			 }
			
			 //la funciòn wait para que el padre espere hasta que el hijo termine
			 close(pipefd[1]);
			 wait(0);
			 printf("Padre: Proceso hijo culminado \n");
			 break;
	}
	return 0;
}

