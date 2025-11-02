#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t pid;
    pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        /* hijo sale inmediatamente -> quedará como zombie hasta que el padre lo recoja */
        printf("Hijo: PID=%d, PPID=%d -> saliendo ahora\n", getpid(), getppid());
        exit(0);
    } else {
        /* padre no llama wait(), duerme para que puedas comprobar el zombie */
        printf("Padre: PID=%d, hijo creado PID=%d\n", getpid(), pid);
        printf("Padre duerme 30 segundos...\n");
        sleep(30);
    }
    return 0;
}
