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

### 3.1.3 Creación de un proceso hijo sin espera ( Ejecutar código de la Figura 3)
#### Respuestas sin haber modificado nada del código dado el la Figura 3
* a) ¿Cuál es el PID del proceso padre del proceso hijo creado?
***El PID del padre es: 7654***
* b) Verifique a qué proceso corresponde el ID encontrado.
***Corresponde al proceso del padre***
* c) ¿Cómo se denomina al tipo de proceso hijo?
***Se lo denomina huérfano***
* d) Modifique el código de la Figura 3 para que el proceso hijo no quede
huérfano. Demostrar el resultado con el PPID del proceso hijo.

#### Resultados dados con el código modificado tal como lo pide el literal d) y de la última ejecución del código
- ***---> Soy el hijo, mi PID es 8980 y el PPID de mi padre es 8979***
- ***Hijo: sigo vivo, mi PPID sigue siendo 8979***
- ***Hijo: final de ejecución de 8980***
- ***---> Soy el padre, mi PID es 8979 y el PPID de mi hijo es 8990***
- ***Padre: mi hijo ha terminado, ahora yo termino también***
- ***Padre: final de ejecución de 8979***


### 3.1.4 Creación de un proceso padre y de tres procesos hijos. 
* a) Modificar el còdigo de la Figura 4 ara que cada proceso hijo haga una tarea diferente

#### REsultados dados con el còdigo modificado 
- ***---> INICIO DEL PROCESO PADRE <---***
- ***PID del padre: 11437***
- ***Padre crea el hijo 1 con PID: 11438*** 
- ***Ejecutando el hijo 1:***
- ***Contando números pares del 1 al 20:***
- ***2	 4	 6	 8	 10	 12	 14	 16	 18	 20***
- ***Padre crea el hijo 2 con PID: 11439***
- ***Ejecutando el hijo 2:***
- ***Contando números impares del 1 al 20:***
- ***1	 3	 5	 7	 9	 11	 13	 15	 17	 19***
- ***Padre crea el hijo 3 con PID: 11440*** 
- ***Ejecutando el hijo 3:***
- ***Contando números del 1 al 10:***
- ***1	 2	 3	 4	 5	 6	 7	 8	 9	 10***	
- ***Todos los hijos han terminado***
- ***Fin del proceso padre con PID: 11437***

### 3.1.5 Crear còdigo para verificar la creaciòn de un proceso zombie, puede usar como base el còdigo de la Figura 5.
#### Resultados dados con el còdigo modificado

- ***Padre: PID=13969, hijo creado PID=13970**
- ***Padre duerme 30 segundos...***
- ***Hijo: PID=13970, PPID=13969 -> saliendo ahora***

Para verificar que el proceso realmente haya quedado zombie se ejecuta el siguiente comando
***ps aux | grep Z***


