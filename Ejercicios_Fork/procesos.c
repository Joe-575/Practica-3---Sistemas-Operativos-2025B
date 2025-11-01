#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Ejemplo de fork \n");
	printf("Inicio del proceso padre PID=%d\n", getpid());
	if(fork()){
		/*proceso hijo*/
		printf("Inicio proceso hijo PID=%d, PPID=%d\n", getpid(), getppid());
		sleep(1);
	}else{
		/*proceso padre*/
		printf("Continuacion del padre PID=%d\n", getpid());
		sleep(1);
	}
	printf(" Fin del proceso %d\n", getpid());
	return 0;
}

