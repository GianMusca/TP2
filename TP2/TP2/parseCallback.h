#ifndef PARSECALLBACK_H
#define PARSECALLBACK_H

/*
	PARSE CALLBACK
	parseCallback es una funcion encargada de procesar lo enviado por el usuario, verificando 
	que tanto las opciones como parametros sean los correctos, para luego actuar en consecuencia
	y comunicar al main la informaion recibida de forma organizada.

	NOTA:
		Opciones: constan de 2 argumentos; una clave, precedida por "-", y su valor.
		Parámetros: constan de 1 argumento, el cual NO puede comenzar con "-"

	Recibe:
		argc, contador de argumentos;
		argv, vector de argumentos; estos dos datos son recibidos por el main del programa usuario, y deben ser
	pasados a parseCmdLine tal como son recibidos al iniciar el programa
		userData, puntero genérico. Éste es el medio por el cual el parseCallback se comunicará con el programa principal
	modificando sus campos de la forma correcta.

	Devuelve:
		En caso de exito devuelve 1
		En caso de error devuelve 0.
*/

//Parametros
#define MODO1 "modo1"
#define MODO2 "modo2"

//Claves
#define HEIGHT "height"
#define WIDTH "width"
#define ROBOTS "robots"


#define MAXH 100	//Altura maxima del piso
#define MAXW 70		//Ancho maximo del piso


int parseCallback(char* key, char* value, void* userData);

#endif
