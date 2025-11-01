# Práctica N° 3
Práctica de Sistemas Operativos 

## Profesor:
Ing. Diana Martínez, PhD.

## Integrantes:
* Joel Velez
* Christopher Pulupa
* Sebastián Reyes
* Joseph Cruz
* Jair Lezcano
* Kevin Azaña

## Objetivos de la Práctica
* 1.1. Familiarizar al estudiante con el uso de las funciones fork, system, exec.
* 1.2. Realizar varias actividades de creación de procesos padres e hijos.

## Resolución
### 3.1 Uso de Fork
Resultados
* Inicio del proceso padre PID = 2993
* Inicio del proceso hijo PID = 2993, PPID = 2959
* Continuación del padre PID = 2994
* Fin del Proceso 2993
* Fin del proceso 2994

### 3.1.2 Incremento de 10 en 10 del padre y el hijo guarda en un archivo
Para que el hijo pueda leer los valores actualizados por el padre, se usará la memoria compartida con pipe();
* pipe(): redirige la salida estándar de un comando para que sirva como entrada estándar de otro comando, permitiendo encadenar procesos para que el resultado de uno sea procesado por el siguiente.

Explicación del funcionamiento:

1. Se crea un pipe, que sirve para comunicar padre ↔ hijo.
* fd[0]: extremo de lectura.
* fd[1]: extremo de escritura.

2. El padre:

* Cierra el extremo de lectura.
* Incrementa una variable valor en pasos de 10.
* Envía cada valor al hijo mediante write(fd[1], &valor, sizeof(int)).

3. El hijo:

* Cierra el extremo de escritura.
* Abre un archivo valores.txt.
* Lee los valores enviados por el padre y los guarda en el archivo.

4. Cierra el archivo al terminar.

* Al final, el padre espera a que el hijo termine usando wait(0).

