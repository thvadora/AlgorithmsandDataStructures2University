Ejercicio 4: Especificar los siguientes TADs en C, y utilizarlos para un prototipo que genere números primos.
Notar que podrán entregar este ejercicio la semana siguiente.

Algoritmo generador de numeros primos:

Para generar los números primos menores que un n dado se nos ocurre el siguiente algoritmo.
En realidad no se nos ocurrió ahora sino hace 2200 años. Tampoco se nos ocurrió a nosotros
sino a Eratóstenes.

Tenemos todos los números entre 2 y n-1. Tomamos el primero (que es el 2) y eliminamos todos
sus múltiplos. Y seguimos de esta manera, tomamos el primero que queda (que ahora es el 3)
y eliminamos sus múltiplos. Tomamos el primero que queda (que es el 5 porque el 4 fue eliminado
por ser múltiplo de 2) y eliminamos todos sus múltiplos. Etc. De esta manera vamos tomando
todos los primos entre 2 y n-1.

TADs necesarios:

Para implementar este algoritmo identificamos que necesitamos Booleanos (para poder
determinar si ser "x es múltiplo de y" es Verdadero o False)
y Naturales (por ejemplo, para poder utilizar los números entre 2 y n-1).

Como
Escribir en un archivo TADBooleano.c/h una especificación e implementacion en C del TAD Booleano,
con los constructores Verdadero y Falso y las operaciones lógicas y, o, no.

Luego escribir en un archivo TADNatural.c/h una especificación en C del TAD Natural,
con los constructores Cero y Sucesor, y las operaciones es_cero, predecesor (que se aplica
solamente a naturales que no sean Cero), más, menos (se aplica cuando el segundo argumento
es menor_o_igual al primero) y por. También las operaciones menor_o_igual, es_múltiplo_de.

El prototipo del algoritmo se da en Ejemplo.hs. Esta en Haskell.

Finalmente
Completar un prototipo del algoritmo mencionado usando estos TADs.

Para compilar y ejecutar tu codigo, vas a tener que usar los mismos comandos dados en ejercicios
y semanas anteriores.
Ademas te hara falta realizar un main desde cero.
Consejo, si aprendiste a leer el codigo, esta tarea no deberia ser difícil, bastaría con
copiar y pegar mains anteriores y modificarlo para su uso en este ejercicio.
Tene en cuenta que no es necesario obtener el input desde un archivo, simplemente podes
usar lectura de la entrada estandar para tomar como parametro los primeros n's primos.
Finalmente tu programa correra con un comando similar al siguiente:

./primos 1000

Observación: si definiste correctamente los TADs vas a visualizar los números primos menores
a 1000.
