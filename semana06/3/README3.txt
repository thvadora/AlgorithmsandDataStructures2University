Ejercicio 3: Completar la implementación del TAD Cola utilizando arreglos.

En la carpeta ayed2-2018/semana06/3
disponés de los siguientes archivos (además de los archivos propios de manejo
de arreglos y de algoritmos de ordenación):

README3.txt : es el archivo que estás viendo.
queue.h : es la descripción de las operaciones para manipular pilas vista en el teórico.
queue.c : contiene implementaciones de dichas operaciones.
main.c : contiene el programa principal que carga un arreglo de naturales y lo ordena
         con el radix sort, un algoritmo que utiliza colas para ordenar.

Completar la definición de queue.c
Una vez logrado eso, podés hacer

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c queue.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o sort *.o main.c
./sort ../input/unsorted-positive-100000.in

¡viste qué rápido que ordena!


