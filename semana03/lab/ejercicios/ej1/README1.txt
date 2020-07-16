Ejercicio 1: Ordenación por permutación

En la carpeta ayed2-2018/semana03/lab/ejercicios/ej1
disponés de los siguientes archivos:

=== ARCHIVOS

README1.txt : es el archivo que estás viendo.
array_helpers.h : el que conocés de la primera clase.
array_helpers.c : idem.
sort_helpers.h : contiene descripciones de goes_before, array_is_sorted y swap.
sort_helpers.c : contiene sus implementaciones.
sort.h : contiene descripción de la función partition_sort
sort.c : contiene una implementación incompleta de partition_sort.
main.c : contiene el programa principal que carga un arreglo de números,
         luego lo ordena con la función partition_sort y finalmente comprueba que
         el arreglo sea permutación ordenada del que cargó inicialmente.

=== DESCRIPCION

Además de los algoritmos que vimos en semanas anteriores, existen otros métodos que permiten ordenar arreglos. Uno de ellos consiste en generar y analizar cada una de las permutaciones del arreglo hasta haber obtenido una permutación ordenada. Por ejemplo, supongamos que deseamos ordenar el siguiente arreglo:

           A = 2 -1 3 8 0

Podríamos listar todas las permutaciones de A hasta encontrar una
que se encuentre ordenada:

=> 2 -1 3 8 0   ==> No está ordenada
=> 2 -1 3 0 8   ==> No está ordenada
=> 2 -1 8 3 0   ==> No está ordenada
=> 2 -1 8 0 3   ==> No está ordenada
....
....
=> 0 -1 2 3 8   ==> Está ordenada (IMPORTANTE: no usamos el orden natural, usamos el orden "goes_before").

Si N es la longitud del arreglo, puede haber hasta N! permutaciones distintas, lo cuál hace que este algoritmo sea muy ineficiente.

Alternativamente, podríamos buscar una permutación ordenada de manera posicional. Para
ello, construimos un arreglo que contiene las posiciones válidas del arreglo original (en este caso: 0, 1, 2, 3 y 4 son
posiciones válidas del arreglo A)

=> 0 1 2 3 4  ==> [ A[0], A[1], A[2], A[3], A[4] ] No está ordenado
=> 0 1 2 4 3  ==> [ A[0], A[1], A[2], A[4], A[3] ] No está ordenado 
=> 0 1 3 2 4  ==> [ A[0], A[1], A[3], A[3], A[4] ] No está ordenado
....
....
=> 4 1 0 2 3  ==> [ A[4], A[1], A[0], A[2], A[3] ] Está ordenado según goes_before. 
                  [ 0   ,  -1,   2  ,  3  ,  8   ]
 
Es decir, iniciamos en el arreglo ascendente

0 1 2 3 4

y analizamos su secuencia de permutaciones una por una, hasta que encontremos la adecuada. El objetivo de este ejercicio es implementar ese algoritmo
utilizando las funciones auxiliares que provee la cátedra.

== INSTRUCCIONES

IMPLEMENTAR: la función "mk_fst_permutation" que retorna la permutación ascendente inicial (en el ejemplo anterior, es [0 1 2 3 4])

La función "next_permutation" es la que genera la secuencia de permutaciones que usamos en los ejemplos anteriores. Toma como argumento un arreglo, y retorna la siguiente permutación de la secuencia. Esa función ya se encuentra implementada en el archivo sort.c

IMPLEMENTAR: la función "sorted" que dado un arreglo y una permutación devuelve verdadero si el arreglo está ordenado posicionalmente siguiendo el orden indicado por la permutación dada. 
=> sorted([2 -1 3 8 0], [0 1 2 4 3], N=4) == false
=> sorted([2 -1 3 8 0], [4 1 0 2 3], N=4) == true 


IMPLEMENTAR: el procedimiento "update" que -por única vez- modifica el arreglo original
para que quede ordenado, aprovechando que la permutación indica cómo tienen que ubicarse sus elementos.

Como siempre:

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c sort_helpers.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sorter *.o main.c
./sorter ../input/example-unsorted.in


IMPORTANTE:

Acordate de probar con otros archivos de la carpeta ../input
fijate que hay archivos nuevos, de arreglos de tamaño 6, 7, 8, 9, etc
andá probando gradualmente con arreglos de tamaño creciente

y no te olvides de probar con el archivo ../input/empty.in


