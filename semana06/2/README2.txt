Ejercicio 2: Completar la implementación del TAD Pila utilizando listas enlazadas.

En la carpeta ayed2-2018/semana06/2
disponés de archivos idénticos a los del ejercicio 1 salvo por README2.txt (este archivo)
y stack.c que define el tipo _stack_t de otra manera.

Completar la definición de stack.c
Una vez logrado eso, podés hacer

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c match.c stack.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o match *.o main.c
./match ../input/balanced.in
./match ../input/unbalanced.in


