Ejercicio 1: Arreglos multidimensionales.

En la carpeta ayed2-2018/semana04/lab/ejercicios/1
disponés de los siguientes archivos:

README1.txt : es el archivo que estás viendo.
array_helpers.h : contiene descripciones de funciones para cargar y volcar al disco los datos climáticos.
array_helpers.c : contiene implementaciones de dichas funciones, la de cargar está incompleta.
main.c : contiene al programa principal que invoca al procedimiento de carga de los datos
         climáticos e inmediatamente procede a volcarlos por la salida estándard.


== Parte 1, Completar la carga de datos.


Abrí el archivo ../input/weather_cordoba.in para ver cómo vienen los datos climáticos.
Cada línea contiene las mediciones realizadas en un día.
Las primeras 3 columnas corresponden al año, mes y día de las mediciones. Las restantes
6 columnas son la temperatura media, la máxima, la mínima, la presión atmosférica, la
humedad y las precipitaciones medidas ese día.
Para evitar los números reales, los grados están expresados en décimas de grados (por
ejemplo, 15.2 grados está representado por 152 (décimas)). La presión también ha sido
multiplicada por 10 y las precipitaciones por 100, o sea que están expresadas en
centésimas de milímetro). Esto permite representar todos los datos con números enteros.
Vos no necesitás multiplicar ni dividir estos valores, esta información es sólo para
que puedas entender los datos.

Lo primero que tenés que hacer es completar el procedimiento de carga de datos en el
archivo array_helpers.c. Además de observar el resto del archivo array_helpers.c para
entenderlo, podés revisar el mismo archivo de la primera semana del lab. Tenes que
completar donde dice "PLEASE COMPLETE".

Una vez que lo hayas hecho podés testear si la carga funciona correctamente ejecutando:

gcc -Wall -Werror -Wextra -pedantic -std=c99 -c array_helpers.c
gcc -Wall -Werror -Wextra -pedantic -std=c99 -o weather *.o main.c
./weather ../input/weather_cordoba.in > weather_cordoba.out

si no hubo ningún error, ahora podés comparar la entrada con la salida:

diff ../input/weather_cordoba.in weather_cordoba.out

si esto último no arroja ninguna diferencia, significa que tu carga funciona correctamente.


== Parte 2, Análisis de los datos.


Crear los archivos
- weather.c ==> Implementación de las funciones mencionadas a continuación.
- weather.h ==> Declaración de las funciones a exportar.

Modificar el archivo main.c para que se muestren los resultados de todas las funciones.

(a) Implementar una función que obtenga la menor temperatura mı́nima histórica registrada en
la ciudad de Córdoba según los datos del arreglo.

(b) Implementar un procedimiento que registre para cada año entre 1980 y 2016 la mayor temperatura máxima registrada durante ese año.

Ayuda: El procedimiento debe tomar como parámetro un arreglo que almacenará los resultados obtenidos.

void procedimiento(tclimate(a), int output[YEARS]) {
	...
	for (unsigned int year = 0; year < YEARS; year++) {		
		...
		output[year] = ... // la mayor temperatura máxima del año  'year' + 1980
	}
}


(c) Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones.



