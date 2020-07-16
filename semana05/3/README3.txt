Ejercicio 3: Encapsular el TAD contador.

En los dos ejercicios anteriores lograste implementar el TAD Contador utilizando dos estilos
diferentes: 1) representando sus operaciones como funciones, 2) pasandole a las operaciones
la dirección del contador para que lo puedan modificar.

ANTES DE CONTINUAR LEYENDO, TODAS LAS COSAS QUE LES DAMOS SON IMPORTANTES, PERO ESTO ES
TEMA DE EVALUACION... AHORA SEGUI LEYENDO:

En cualquiera de los dos casos, sin embargo, quien escribe el main.c puede decidir acceder
directamente al valor del contador (por ejemplo, escribir printf("contador = %u\n",c);) o
modificarlo (por ejemplo, c = 45;).

QUEDO CLARO?? SINO LLAMA A UN PROFESOR!!!!!

Esto NO es deseable ya que luego, cualquier cambio en la implementación del TAD va a
requerir revisar el main.c para modificar eventualmente estas operaciones que no
estaban contempladas en el TAD.

Cuando uno define un TAD es deseable garantizar ENCAPSULAMIENTO, es decir, que solamente
se pueda acceder y/o modificar el contador a través de las operaciones provistas por el
TAD. En c, la forma de conseguir encapsular es utilizando punteros.

Incluiremos en nuestro counter.h la siguiente definición.

typedef struct _counter * counter;

El compilador acepta esta definición aunque por ahora no sabe qué es el tipo _counter, debe
definirse por un struct, pero no se sabe más que eso. Y counter es el tipo de los punteros
a estructuras de ese tipo.

Quien escribe el main solamente podrá usar eso: que un contador es un puntero a una estructura,
pero no conoce cómo está compuesta esa estructura, y por lo tanto no podrá acceder al
ni modificar el valor de lo que se encuentra dentro de ella.

QUEDO CLARO?? SINO LLAMA A UN PROFESOR!!!!!

Para mayor información, abrí el archivo counter.h

Los archivos en esta carpeta (Algoritmos2.2018/semana05/lab/ejercicios/3) son README3.txt,
counter.h (que tenés que abrir y conocer), counter.c (que tenés que modificar) y main.c
(que vas a modificar para comprobar que el contador esté realmente encapsulado).

Para resolver el ejercicio, implementá counter.c y revisá si hace falta cambiar algo
en main.c, compilá y ejecutá.

Una vez que funcione correctamente, intentá acceder o modificar directamente el contador
en el main, sin utilizar sus operaciones.
