ENUNCIADO:
La líder de gimnasio Misty organizó un evento de pesca que se llevará a cabo en su 
acuario, ubicado en Ciudad Celeste.Para ello necesitará muchos y muy variados
pokémon de tipo agua. El lugar indicado en Kanto para obtener a todos estos pokémon
es el arrecife que rodea a las Islas Espuma. Para realizarlo, te pide que la ayudes
a trasladar los pokémon seleccionados desde el arrecife a su acuario, donde será 
realizado el evento. A Misty le preocupa perjudicar la población de las especies más
vulnerables, es por ello que te pide realizar una simulación del arrecife, pudiendo
ver como quedará su estado dependiendo de qué especies se elijan para el evento.

INTRODUCCION AL TP:
El tp comienza primero verificando que se paso por lo menos algun parametro, caso 
contrario, termina. Una vez que verifica eso, crea los punteros necesarios para el
arrecife y el acuario, llamando primero a la funcion crear_arrecife, en caso que la 
funcion retorne NULL, el programa termina, lo mismo ocurre si la funcion 
crear_acuario retorna NULL. Luego crea los vectores de punteros, uno que apunten
a las funciones de requisitos y otro que apunte a las funciones de mostrar el
arrecife, termina eso y comienza con el traslado de los pokemones, cuando entra a 
la funcion tralsadar_pokemon, verifica si la cantidad de pokemones dentro del
arrecife es mayor a la cantidad pedida a trasladar, y despues si hay mas pokemones
dentro del arrecife que cumplan los requisitos que la cantidad a trasladar, en
cualquiera de los dos casos que haya menos pokemones, retorna -1. finalizado eso, 
comienza la busqueda de pokemon que cumpla el requisito y su traslado, en caso
que su tralado falle, la funcion se detiene y retorna -1. se realiza un tralado y
eliminacion a la vez. luego de que e sale de la funcion traladar_pokemon, se imprime
por pantalla los pokemones que estan en el arrecife, para esto, el programa le
pide al usuario que elija la opcion de como quiere mostrar el arrecife, el programa 
repite el proceso de tralado y censo la cantidad de funciones d erequisitos
que existan. una vez que termina con todo los tralados, se guardan los pokemones 
dentro del vector en un archivo .txt, este puede ser enviado como parametro o 
se crea uno por defecto, en caso que el archivo ya exista, se le agregara la 
informacion nueva, sin sobrescribir la anterior. terminado de guardar todos los 
pokemones en un archivo, se procede a liberar la memoria utilizada por el arrecife 
y por acuario, primero se libera la memoria del arrecife y despues la del acuario.
 al terminar esto, el programa finaliza.

LINEA DE COMPILACION
se compila con la siguiente linea:
	"gcc *.c -Wall -Werror -Wconversion -std=c99 -o evento_pesca"
en el cual: 
	gcc: es un compilador de programas en c.
	*.c: significa que se deberan compilar todos los archivos con extencion .c en 
		la carpeta donde nos encontremos.
	-Wall, -Werror, -Wconversion -std=c99: flags nesesarios para que el programa
		nos informe de cualquier error que tengamos.
	-o evento_pesta: como llamaremos al programa ya compilado y listo para ejecutar 

LINEA DE EJECUCION:
se ejecuta de la siguiente manera:
	./evento_pesca arrecife.txt mi_acuario.txt
	./: lo que escribas despues de el sera un archivo dentro del directoria donde te
		encontras y no un comando.
	arrecife.txt: parametro utilizado para abrir el archivo donde se encuantra el 
		arrecife, tiene que ser si o si el primer parametro el cual contiene la 
		direccion del archivo del arrecife, sino el programa el programa.
	mi_acuario.txt: parametro utilizado para crear un archivo donde se guardan los
	pokemones del acuario, en caso que el archivo exista, se agregara la informacion
	nueva, este parametro no es presindible, en caso de no ponerlo, se creara un archivo
	por defecto llamado "pokes_acuario.txt".

EXPLICACION CONCEPTOS:
	Punteros: tipo de datos que almacena direcciones de memoria.
	Aritmerica de punteros: existen distintos tipos de operadores que se utilizan
		para poder manejarse con punteros, como el &, con el cual se accede a la 
		direccion de memoria. El *, con el cual se utiliza para definir una varible
		de tipo puntero y para ver el valor que esta en la dirrecion asignada. El ++
		y el --, con los cuales se pueden utilizar como si fuera un vector cualquiera.
	Punteros a funciones: Un  puntero  a  una  funcion  no  es  mas  que  la 
		direccion  de  memoria  donde  reside  una  determinada  funcion  en 
		un programa en C. Ademas permite ejecutar a la funcion desde cualquier
		parte del programa.
	Malloc y Realloc: Malloc se utiliza cuando se quiere trabajar con memoria 
		dinamica, este reserva memoria(pedida por el usuario) en el heap y se la deja
		al usuario para que trabaje con ella, pero no la libera una vez entregada, el 
		usuario se hace cargo de esa memoria. Malloc retorna devuelve  un  puntero
		a  la  memoria  reservada, hay que aclarar que esta memoria no esta 
		inicializada. Realloc lo que hace es modificar el tamaño de la memoria pedida
		si, se le envia la direccion de la memoria que se quiere modificar y retorna 
		la misma direccion en caso que pudo modificar la misma direccion, en caso que no
		pudiera, retorna o una nueva direccion con el tamaño pedido(libera el bloque anterior) 
		o NULL si no pudo directamente modificar ni el bloque pedido ni uno nuevo.

