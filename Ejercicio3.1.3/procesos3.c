#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>	

int main(){
	int pid = fork();

	switch(pid){
		case -1:
			printf("\n No he podido crear el proceso hijo\n");
			break;
		case 0:
			printf("\n ---> Soy el hijo, mi PID es %d y el PPID de mi padre es %d", getpid(), getppid());
			sleep(2);
			printf("\n Hijo: sigo vivo, mi PPID sigue siendo %d", getppid());
			printf("\n HIjo: final de ejecuciòn de %d\n", getpid());
			break;
		default:
			printf("\n ---> Soy el padre, mi PID es %d y el PID de mi hijo es %d", getpid(), pid);
			wait(0);
			printf("\n Padre: mi hijo ha terminado, ahora yo termino");
			printf("\n Padre: final de ejecuciòn de %d \n", getpid());
			break;
	}
	return 0;
}
