Ejercicio 2: Implementación de un algoritmo para chequear si una proposición es o no una tautología revisando su tabla de verdad

En la carpeta ayed2-2018/semana03/lab/ejercicios/ej2
disponés de los siguientes archivos:

== ARCHIVOS

README2.txt : es el archivo que estás viendo.
prop.h : tipo abstracto de dato (TAD) proposición.
prop.c : implementación del TAD proposición.
prop_helpers.h : contiene descripciones de operaciones auxiliares sobre proposiciones.
prop_helpers.c : implementación de esas operaciones.
evaluation.h : contiene descripciones de la función de evaluación y de la función que
               determina si una proposición es o no una tautología
evaluation.c : contiene una implementación de la función de evaluación, y una implementación
               muy incompleta de la función que determina si una proposición es o no una
               tautología
main.c : contiene el programa principal que carga una proposición y luego comprueba
         si se trata o no de una tautología.


== DESCRIPCION

En este ejercicio deberán completar la implementación de un algoritmo que verifica si una proposición lógica es o no una tautología.

Las proposiciones válidas serán las siguientes:

p0,p1,p2, ...   Variables proposicionales
T		Constante True
F		Constante False
(PROP)&(PROP)   Conjunción
(PROP)|(PROP)   Disjunción 
(PROP)=>(PROP)  Implicación
(PROP)<=>(PROP) Equivalencia
!(PROP)         Negación


IMPORTANTE: Por restricción del parser, todos los paréntesis son obligatorios.

Como ejemplo, veamos la siguiente proposición:
	
     P = (p0)|!(p1)

El valor de verdad de P depende de los valores de p0 y p1:
- Si p0=(V)erdadero y p1=(F)also, entonces P es verdadero.
- Si p0=(F)also y p1=(V)erdadero, entonces P es falso.
- etc.

Para este caso, hay 4 posibles combinaciones de los valores de p0 y p1, que se pueden escribir en una tabla de verdad:

p0 p1   P=(p0)|!(p1)   
F  F    V
F  V    F
V  F    V
V  V    V

Una proposición es una tautología si es verdadera para todas las combinaciones de la tabla de verdad. En este
ejemplo, la proposición P no es una tautología ya que [p0=F, p1=V] hacen que P=F. 

Ejemplos de tautologías: (p0)|!(p0),  (p0)=>((p0)|(p1)) y ((p0)|(p1))<=>((p1)|(p0))

Una manera de determinar si una proposición P es tautología consiste en analizar cada una de las
líneas de la tabla de verdad y verificar que P sea siempre (V)erdadera.

De manera similiar que en el ejercicio 1, comenzaremos con una línea inicial y generaremos las siguientes líneas
usando una función auxiliar.

En el ejemplo anterior:

F F  Línea inicial  (Todas las variables en F)  
F V  Línea 1
V F  Línea 2
V V  Línea final    (Todas las variables en V)	

IMPLEMENTAR: la función "mk_fst_line" de evaluation.h, que genera la línea inicial de la tabla de verdad.

IMPLEMENTAR: la función "last_line" que verifica si una línea es o no la final.

IMPLEMENTAR: la función "next_line" que genera la siguiente línea de la secuencia.

De esa manera tendremos todas las funciones listas generar la secuencia completa de líneas. La función "is_tautology" 
debe recorrer esa secuencia de líneas y verificar que en todas ellas la proposición sea verdadera. Notemos que
si en una línea la proposición es falsa, el algoritmo debe detenerse sin necesidad de seguir explorando la secuencia completa.

IMPLEMENTAR: la función "is_tautology"

La función "eval" ya se encuentra implementada: se encarga de evaluar una proposición para una línea de la tabla de verdad.

Las líneas se representan con una arreglo de valores booleanos. El largo del arreglo depende la variable proposicional con
mayor índice que se encuentre en la proposición:

(p0)&(p1) Las líneas de la tabla de verdad tienen longitud 2
(p0)&(p9) Las líneas de la tabla de verdad tienen longitud 10

IMPORTANTE: Ver la función get_max_var del tipo de datos prop.h


Como siempre, para compilar

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c prop_helpers.c prop.c evaluation.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o taut *.o main.c
./taut ../input/prop0.in

Acordate de probar con otros archivos con proposiciones de la carpeta ../input


