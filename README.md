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
- La práctica se lleva a cabo en una máquina virtual por medio del programa Oracle VirtualBox, en el sistema operativo Ubuntu Server. 


## Uso de Fork
### 3.1.1 Identificar los valores PID y PPID de cada proceso
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
* a) Modificar el código de la Figura 4 para que cada proceso hijo haga una tarea diferente

#### REsultados dados con el código modificado 
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

### 3.1.5 Crear código para verificar la creación de un proceso zombie, puede usar como base el código de la Figura 5.
#### Resultados dados con el código modificado

- ***Padre: PID=13969, hijo creado PID=13970**
- ***Padre duerme 30 segundos...***
- ***Hijo: PID=13970, PPID=13969 -> saliendo ahora***

Para verificar que el proceso realmente haya quedado zombie se ejecuta el siguiente comando
***ps aux | grep Z***

## Uso de EXEC
### 3.2.1 Crear un proceso hijo que realice una tarea usando exec
#### Resultados dados con el cóigo modificado
- ****total 24***
- ***-rwxrwxr-x 1 joel joel 19456 nov  2 13:21 procesos***
- ***-rw-rw-r-- 1 joel joel  1376 nov  2 13:05 procesos.c***
- ***El proceso hijo con PID 16750 se ha ejecutado***


## Uso de SYSTEM
### 3.2.1 Crear un proceso hijo que liste los procesos del sistema usando system
#### Resultados dados con el código modificado
 Se muestran todos los procesos y dado que son demasiados procesos se mostrarán unos cuantos
- Proceso hijo: Listando los procesos del sistema...
- USER         PID %CPU %MEM    VSZ   RSS TTY      STAT START   TIME COMMAND
- joel        3976  0.0  0.0  21072  1316 ?        Sl   08:52   0:00 /snap/firefox/7084/usr/lib/firefox/cr
- joel        4050  0.0  0.4 300092 16512 ?        S    08:52   0:00 /snap/firefox/7084/usr/lib/firefox/fi
- joel        4056  0.0  0.6 314488 24084 ?        Sl   08:52   0:00 /snap/firefox/7084/usr/lib/firefox/fi
- joel        4085  0.1  2.7 2556740 110944 ?      Sl   08:52   0:23 /snap/firefox/7084/usr/lib/firefox/fi
- joel        4094  0.0  0.7 452088 29520 ?        Sl   08:52   0:00 /snap/firefox/7084/usr/lib/firefox/fi
- joel        4131  0.0  0.1 1765940 7220 ?        Sl   08:52   0:02 /snap/snapd/current/usr/bin/snap user
- Proceso padre: El proceso hijo ha terminado

## Conclusiones
- Mediante la práctica realizada se pudo visualizar los diferentes procesos desde la terminal por medio del comando ***top***. La creación de procesos, donde cada padre puede tener varios hijos y cabe la posibilidad de que algunos de ellos quede huérfano o zombi.
- La implementación del lenguaje C, fundamental para realizar dicha práctica junto con uso del editor de texto ***VIM***. También se ha aprendido a subir los archivos a GitHub por medio de la terminal de Ubuntu.
