<!---
 -
 - Author   2017 Daniel Fridlender
 -
 - Revision 2018 Sergio Canchi
 -
 -
 -->


Ejercicio 4: Comparación de todos los algoritmos de ordenación implementados

En la carpeta ayed2-2018/semana02/lab/ejercicios/ej4
disponés de los siguientes archivos:

README4.txt : es el archivo que estás viendo.
sort_helpers.h : contiene además descripciones de manejadores de contadores
sort_helpers.o : contiene implementaciones ilegibles de todo lo descripto en sort_helpers.h (código compilado para la arquitectura x86-64)
                 Nota: Si usted esta trabajando en una computadora con arquitectura distinta a la mencionada, entonces seleccione
                 y renombre uno de los siguientes archivos, sort_helpers.o_32 o sort_helpers.o_macos segun la arquitectura de su maquina.
sort.h : contiene descripción de las funciones de ordenación implementadas
sort.c : contiene una implementaciones incompletas de los algoritmos de ordenación trabajados
main.c : contiene el programa principal que carga un arreglo de números,
         luego lo ordena uno de los algoritmos de ordenación implementados
         y muestra el tiempo de ejecución, número de comparaciones e intercambios realizados.

Ahora tenés que copiar los archivos array_helpers.h y array_helpers.c de un ejercicio
anterior.

a) Abrí el archivo sort.c y copiar el código de cada uno de los algoritmos de ordenación resueltos en los ejercios anteriores.

b) Abrí el archivo main.c y completar la función main siguiendo los pasos indicados en los comentarios.


Una vez completados los incisos a) y b), compilá ejecutando

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main.c

y ya podés correr el programa, ejecutando

./sorter ../input/example-unsorted.in

Si anda bien (o sea, si no reporta error) probá con otros archivos de la carpeta ../input

Mostrale lo que hiciste a alguno de los profes y luego terminaste con el lab de la segunda
semana.
