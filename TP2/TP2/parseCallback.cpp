#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "parseCallback.h"
#include "Simulation.h"

#define OK 1
#define NOTOK 0

int parseCallback(char* key, char* value, void* userData)
{
	simulationType* data = (simulationType*) userData;	//Crea un nuevo puntero para utilizar userData

	int parseOK = NOTOK; //Devuelve por default error

	if (key != NULL)	 //Verifica si es una clave
	{
		if (!(strcmp(HEIGHT, key)))		//Si la clave es la altura
		{
			int height = (atoi(value));			//Transforma lo escrito por el usurio en un numero

			if (0 < height && MAXH >= height)	//Si la altua no es 0 ni maxima
			{
				data->height = height;			//Guarda su valor 
				parseOK = OK;					//E indica que no hay error
			}

			else
			{
				printf("Error:Altura invalida");
			}
		}	

		else if (!(strcmp(WIDTH, key)))	//Si la clave es el ancho
		{
			int width = (atoi(value));		//Transforma lo escrito por el usurio en un numero

			if (0 < width && MAXW >= width)	//Si el ancho no es 0 ni maximo
			{
				data->width = width;		//Guarda su valor
				parseOK = OK;				//E indica que no hay error
			}

			else
			{
				printf("Error:Ancho invalido");
			}
		}

		else if (!(strcmp(ROBOTS, key))) //Si la clave es el numero de robots
		{
			int robots = (atoi(value));	//Transforma lo escrito por el usurio en un numero

			if (0 < robots)				//Si no es negativo ni 0
			{
				data->robotCount = robots;	//Guarda su valor
				parseOK = OK;			//E indica que no hay error
			}

			else
			{
				printf("Error:Numero de Robots invalido");
			}
		}
		
		else
		{
			printf("Error:Clave invalida");
		}
	}

	else	//Si no es clave es un parametro
	{
		if (!(strcmp(MODO1, value)))	//Si es el modo 1
		{
			data->modo = MODE1;	//Establece el modo correcto
			parseOK = OK;		//E indica que no hay error
		}

		else if (!(strcmp(MODO2, value)))
		{
			data->modo = MODE2;	//Establece el modo correcto
			data->robots = 0;	//Ignora el numero de robots
			parseOK = OK;		//E indica que no hay error
		}

		else
		{
			printf("Error:Modo invalido");
		}
	}

	return parseOK;
}