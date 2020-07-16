<!---
 -
 - Author   2017 Daniel Fridlender
 -
 - Revision 2018 Sergio Canchi
 -
 -
 -->


Ejercicio 2: Implementación top-down del algoritmo de ordenación rápida, primera parte

En la carpeta ayed2-2018/semana02/lab/ejercicios/ej2
disponés de los siguientes archivos:

README2.txt : es el archivo que estás viendo.
array_helpers.h : es el mismo que en el ejercicio anterior.
array_helpers.c : también.
sort_helpers.h : contiene además una descripción de partition
sort_helpers.o : contiene implementaciones ilegibles de todo lo descripto en sort_helpers.h (código compilado para la arquitectura x86-64)
                 Nota: Si usted esta trabajando en una computadora con arquitectura distinta a la mencionada, entonces seleccione
                 y renombre uno de los siguientes archivos, sort_helpers.o_32 o sort_helpers.o_macos segun la arquitectura de su maquina.
sort.h : contiene descripción de la función quick_sort
sort.c : contiene una implementación muy incompleta de quick_sort,
         falta implementar quick_sort_rec
main.c : contiene el programa principal que carga un arreglo de números,
         luego lo ordena con la función quick_sort y finalmente comprueba que
         el arreglo sea permutación ordenada del que cargó inicialmente.

a) Implemente el procedimiento quick_sort_rec en el archivo sort.c

Para esta parte es necesario que abras el archivo sort.c e implementes el
procedimiento quick_sort_rec. Ojo: no es necesario que implementes la función partition puesto
que la misma ya está implementada (salvo que no podés leer el código porque solo disponés
de la versión compilada). Para saber cómo utilizarla, examiná su descripción en sort_helpers.h.
A modo de guía para implementar quick_sort_rec, no dudes en revisar la presentación que
hicimos del algoritmo de ordenación rápida en clase.

b) Completar la función main en el archivo main.c 
Para esta parte es necesario que abras el archivo main.c y completes la función main
con una llamada al procedimiento quick_sort. Para saber como utilizar el procedimiento
quick_sort examiná el archivo sort.c

Una vez completados los incisos a) y b), compilá ejecutando

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main.c

y ya podés correr el programa, ejecutando

./sorter ../input/example-unsorted.in

Si anda bien (o sea, si no reporta error) probá con otros archivos de la carpeta ../input
no te olvides de probar con el archivo ../input/empty.in

Mostrale lo que hiciste a alguno de los profes y luego pasá al ejercicio 3 haciendo

cd ../ej3

y abrí el archivo README3.txt

