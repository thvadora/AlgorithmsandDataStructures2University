Ejercicio 1: Analizar una implementación ingenua del TAD contador.

En la carpeta Algoritmos2.2018/semana05/lab/ejercicios/1
disponés de los siguientes archivos:

README1.txt : es el archivo que estás viendo.
counter.h : es la descripción "ingenua" de las operaciones
            para manipular contadores vista en el teórico.
counter.c : contiene implementaciones de dichas funciones.
main.c : contiene al programa principal que lee uno a uno los caracteres de un
         archivo chequeando si los paréntesis están balanceados..

Como está ahora podés hacer

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c counter.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o match *.o main.c
./match ../input/onlyopen.in

Que estas haciendo cuando copias y pegas la primer linea?
Que estas haciendo cuando copias y pegas la segunda linea?

Sino entendes, llama a un profesor!!!!!!!
Recien cuando entiendas pasa a la segunda parte.

¿Es correcta la respuesta que da el algoritmo? (mirá el archivo onlyopen.in).

Probá cambiar en el main.c init(c) por c = 0, inc(c) por c++, etc. y volvé a compilar y
ejecutar.

¿Es correcta ahora la respuesta?

¿A qué se debe esta diferencia?
¿Qué estaba ocurriendo cuando usábamos las operaciones del TAD contador y por qué?

Volvé a usar main.c como estaba (con init(c), inc(c), etc). Escribí printf's que
te muestren los valores de c justo antes y justo después de la invocación a inc(c).

¿Cómo es posible?

Una vez que hayas entendido lo que está ocurriendo podés resolver el problema.
Hay dos formas de hacerlo:

1) cambiar counter.h para que las descripciones operaciones devuelvan el valor de c:

counter init();
/*
    Returns a counter's initial value.
*/

counter inc(counter c);
/*
    Returns value of c+1.
*/

counter dec(counter c);
/*
    Returns value of c-1.
*/

bool is_init(counter c);
/*
    Return whether the counter c has the initial value.
*/

Cambiar también counter.c y main.c adecuandolo a estos cambios.

Hacelo andar: que compile y corra bien...

2) la otra solución es pasar la dirección del contador como parámetro cuando
se lo desea modificar. Para ello, pasá al ejercicio 2.
