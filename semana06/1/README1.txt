Ejercicio 1: Completar la implementación del TAD Pila utilizando arreglos.

En la carpeta ayed2-2018/semana06/1
disponés de los siguientes archivos:

README1.txt : es el archivo que estás viendo.
stack.h : es la descripción de las operaciones para manipular pilas vista en el teórico.
stack.c : contiene implementaciones de dichas operaciones.
match.h : descripción de algoritmo que chequea delimitadores
match.c : su implementación usando pila
main.c : contiene el programa principal.

1) Completar la definición de stack.c
Una vez logrado eso, podés hacer

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c stack.c match.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o match *.o main.c
./match ../input/balanced.in
./match ../input/unbalanced.in

2)Si ejecutan ./match con un nombre de archivo inexistente nos producirá la siguiente salida:

Segmentation fault (core dumped)
¿A que se debe este error? ¿Donde se origina? Ayuda: Se puede encontrar facilmente el error si se utiliza un debugger (por ejemplo GDB).
Si no sabes como utilizar el debugger, consultá a un profesor. 
Modificá el main.c para arreglar el problema. Si el archivo no existe en el sistema de archivos, el main deberá imprimir por pantalla (stderr)
"File does not exist." y abortar la ejecución con código "EXIT_FAILURE". A propósito: ¿sabes porque el ejecutable main devuelve un entero?  ¿Que representa ese entero?

3) Habrán notado que la implementación de stack incluye 2 métodos especiales: "stack_create" y "stack_destroy". Estos métodos también llamados constructor y destructor respectivamente se encargan del manejo de la memoria dinámica del programa. Como regla a seguir cada vez que yo pida memoria dinámica usando malloc, calloc o realloc, deberé llamar al correspondiente free de dicha memoria donde corresponda.
En caso que el programa que este ejecutando finalice y no toda la memoria pedida sea liberada se generará un "memory leak".
Existe una herramienta instalada en el laboratorio que permite corroborar si una ejecución libera toda la memoria que solicitó. Esta herramieta se llama "valgrind"

Una vez finalizado el punto 1 podrás ejecutar:
valgrind --leak-check=full ./match ../input/unbalanced.in

y verás un output similar a este:
==8908== Memcheck, a memory error detector
==8908== Copyright (C) 2002-2015, and GNU GPL'd, by Julian Seward et al.
==8908== Using Valgrind-3.11.0 and LibVEX; rerun with -h for copyright info
==8908== Command: ./match ../input/unbalanced.in
==8908== 
Delimeters mismatch.
==8908== 
==8908== HEAP SUMMARY:
==8908==     in use at exit: 0 bytes in 0 blocks
==8908==   total heap usage: 4 allocs, 4 frees, 5,776 bytes allocated
==8908== 
==8908== All heap blocks were freed -- no leaks are possible  <---- ESTO NOS INDICA QUE NO HAY MEMORY LEAKS. Liberamos toda la memoria!!
==8908== 
==8908== For counts of detected and suppressed errors, rerun with: -v
==8908== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

El programa que compilaste: ¿Tiene memory leaks? ¿Se te ocurre como solucionarlo? Ayuda: valgrind estudia las trazas de memoria, informandonós DONDE se pidió la memoria que no se liberó, pero valgrind no puede "adivinar" donde deberiamos haberla liberado.

¿Pudiste solucionar el memory leak? Genial! A partir de ahora, deberías verificar que tus programas no contengan memory leaks usando la herramienta valgrind.
