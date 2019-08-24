#include <math.h>
#include<cstdlib>
#include<ctime>

typedef struct
{
	double angle;
	double x;
	double y;

} robotType;			//Estructura Robots.

robotType* createRobots(uint RobotCount, uint width, uint height); //NULL if error
void moveRobot(robotType* Robots, uint RobotCount, uint width, uint height);
void destroyRobots(robotType* robots);

double getRobotAngle(robotType*);
double getRobotX(robotType*);
double getRobotY(robotType*);

double getRobotAngle(robotType* robot)		//Devuelve el angulo de un robot.
{
	return (robot->angle);
}

double getRobotX(robotType* robot)			//Devuelve la componente X de la posicion de un robot.
{
	return (robot->x);
}

double getRobotY(robotType* robot)			//Devuelve la componente Y de la posicion de un robot.
{
	return (robot->y);
}

void destroyRobots(robotType* robots)		//Destruye todos los robots.
{
		robots = (robotType*) NULL;
}


robotType* createRobots(uint RobotCount, uint width, uint height)	//Crea todos los robots, asignandole una posicion en el tablero y un angulo.
{
	robotType* robots;
	robots = (robotType*) malloc (width * height * sizeof(robotType));
	for (int i = 0; i < RobotCount; i++)
	{
		*(robots + i)->angle = srand(time(NULL)) % 360;
		*(robots + i)->y = (srand(time(NULL)) % (height-1))+1;		// asigna a la posicion valores entre 1 y height/width-1 
		*(robots + i)->x = (srand(time(NULL)) % (width-1))+1;
	}

	return robots;
	
}

void moveRobot(robotType* robots, uint RobotCount, uint width, uint height)		//DISCLAIMER: No esta terminada. Los "calculos" serian esos pero despues 
																				//faltaria la parte del analisis (es decir, si al moverse toca bordes, etc). Despues lo hago :D
{
	for (int i = 0; i < RobotCount; i++)
	{
		if (getRobotAngle(robot + i) < 90)
		{
			(robots + i)->x += sin((robots + i)->angle);
			(robots + i)->y += cos((robots + i)->angle);
		}

		else if (getRobotAngle(robots + i) > 90 && getRobotAngle(robots + i) < 180)
		{
			(robots + i)->x += cos((robots + i)->angle - 90.0);
			(robots + i)->y -= sin((robots + i)->angle - 90.0);
		}

		else if (getRobotAngle (robots + i) > 180 && getRobotAngle(robots + i) < 270)
		{
			(robots + i)->x -= sin((robots + i)->angle - 180.0);
			(robots + i)->y -= cos((robots + i)->angle - 180.0);
		}

		else if (getRobotAngle(robots + i) > 270 && getRobotAngle(robots + i) < 360)
		{
			(robots + i)->x -= cos((robots + i)->angle - 270.0);
			(robots + i)->y += sin((robots + i)->angle - 270.0);
		}
	}
}