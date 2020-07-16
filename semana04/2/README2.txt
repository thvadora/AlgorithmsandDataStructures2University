Ejercicio 2: Ordenar un arreglo de tuplas.

En la carpeta ayed2-2018/semana04/lab/ejercicios/2
disponés de los siguientes archivos:

README2.txt : es el archivo que estás viendo.
helpers.h : contiene descripciones de funciones para cargar y volcar al disco datos
            de los jugadores del tenis profesional.
helpers.c : contiene implementaciones de dichas funciones.
sort.h : descripciones de algoritmo de ordenación.
sort.c : su implementación incompleta.
main.c : contiene al programa principal que por ahora invoca al procedimiento de carga de los
         datos y los vuelve a volcar por la salida estándard.

Abrí el archivo ../input/atpplayers.in para visualizar los datos. Es un listado por orden alfabético
de jugadores profesionales de tenis. El nombre del jugador viene acompañado de una abreviatura de su
pais, el número que ocupa en el ranking, su edad, su puntaje y el número de torneos jugados en el último
año.

También podés observar todos los cambios que debieron hacerse en las descripciones de las funciones
de sort.c y helpers.c (las que no son funciones nuevas) para adaptarlo al nuevo tipo de arreglo
(en lugar de arreglos de enteros de antes).

Como está ahora podés hacer

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c helpers.c sort.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o mysort *.o main.c
./mysort ../input/atpplayers.in

y comprobar que la salida es idéntica a la entrada (salvo por la información sobre
el tiempo utilizado para ordenar). Para comprobar eso, hacé

./mysort ../input/atpplayers.in > atpplayers.out
diff ../input/atpplayers.in atpplayers.out

El ejercicio es realizar los cambios que necesites en el archivo sort.c para ordenar
el arreglo cargado de modo de que el listado de salida sea en el orden según su ranking.


