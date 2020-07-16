<!---
 -
 - Author   2017 Daniel Fridlender
 -
 - Revision 2018 Sergio Canchi
 -
 -
 -->


Ejercicio 1: 

En la carpeta ayed2-2018/semana02/lab/ejercicios/ej1
disponés de los siguientes archivos:

README1.txt : es el archivo que estás viendo.
array_helpers.h : contiene descripciones de funciones auxiliares para manipular arreglos.
array_helpers.c : contiene implementaciones de dichas funciones.
sort_helpers.h : contiene descripciones de goes_before, array_is_sorted y swap
sort_helpers.o : contiene implementaciones ilegibles de esas funciones (código compilado para la arquitectura x86-64)
                 Nota: Si usted esta trabajando en una computadora con arquitectura distinta a la mencionada, entonces seleccione
                 y renombre uno de los siguientes archivos, sort_helpers.o_32 o sort_helpers.o_macos segun la arquitectura de su maquina.
sort.h : contiene descripción de la función insertion_sort
sort.c : contiene una implementación incompleta de insertion_sort, falta implementar insert
main.c : contiene el programa principal que carga un arreglo de números,
         luego lo ordena con la función insertion_sort y finalmente comprueba que
         el arreglo sea permutación ordenada del que cargó inicialmente.

a) Implementación del algoritmo de ordenación por inserción

Para esta parte es necesario que abras el archivo sort.c e implementes el
procedimiento insert. Para guiarte, no dudes en examinar el resto del archivo sort.c y 
la definición del algoritmo de ordenación por inserción que hemos visto en clase. El algoritmo
debe ordenar con respecto a la relación goes_before, provista por sort_helpers.h

b) Verificar el cumplimiento del invariante del "ciclo for del procedimiento insertion_sort"

Para esta parte es necesario que modifiques el procedimiento insertion_sort agregando
la verificación de cumplimiento del invariante del ciclo for del procedimiento insertion_sort visto en el teórico.

Por simplicidad solo verifique esta parte del Invariante: 
-- el segmento inicial a[0,i) del arreglo está ordenado.

Para esto debes hacer uso de las funciones assert y array_is_sorted.

Una vez implementado los incisos a) y b), compilá ejecutando

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main.c

y ya podés correr el programa, ejecutando

./sorter ../input/example-unsorted.in

Si anda bien (o sea, si no reporta error) probá con otros archivos de la carpeta ../input
no te olvides de probar con el archivo ../input/empty.in

¿Te das cuenta qué relación implementa la función goes_before?

Si todo anda bien, pasá al ejercicio 2, haciendo

cd ../ej2

y abrí el archivo README2.txt

