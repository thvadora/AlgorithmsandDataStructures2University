<!---
 -
 - Author   2017 Daniel Fridlender
 -
 - Revision 2018 Sergio Canchi
 -
 -
 -->


Ejercicio 3: Implementación top-down del algoritmo de ordenación rápida, segunda parte

En la carpeta ayed2-2018/semana02/lab/ejercicios/ej3
disponés de los siguientes archivos:

README3.txt : es el archivo que estás viendo.
sort_helpers.h : contiene descripciones de goes_before, array_is_sorted y swap
sort_helpers.o : contiene implementaciones ilegibles de todo lo descripto en sort_helpers.h (código compilado para la arquitectura x86-64)
                 Nota: Si usted esta trabajando en una computadora con arquitectura distinta a la mencionada, entonces seleccione
                 y renombre uno de los siguientes archivos, sort_helpers.o_32 o sort_helpers.o_macos segun la arquitectura de su maquina.
sort.h : contiene descripción de la función quick_sort
sort.c : contiene una implementación incompleta de quick_sort,
         falta implementar quick_sort_rec y partition

Ahora tenés que copiar los archivos array_helpers.h, array_helpers.c y main.c del
ejercicio 2.

Luego copiar el procedimiento quick_sort_rec del ejercicio 2 en el archivo sort.c y
definir la función partition.

Para finalizar la implementación de quick_sort tenés que abrir el archivo sort.c, copiar
tu implementación de quick_sort_rec del ejercicio anterior y, ahora sí, implementar la
función partition usando como guía la presentación que hicimos del algoritmo de ordenación
rápida en clase.

Una vez implementada la función partition, compilá ejecutando

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main.c

y ya podés correr el programa, ejecutando

./sorter ../input/example-unsorted.in

Si anda bien (o sea, si no reporta error) probá con otros archivos de la carpeta ../input
no te olvides de probar con el archivo ../input/empty.in

Mostrale lo que hiciste a alguno de los profes y luego pasá al ejercicio 4 haciendo

cd ../ej4

y abrí el archivo README4.txt

