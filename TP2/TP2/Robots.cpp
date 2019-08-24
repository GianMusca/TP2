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

void moveRobot(robotType* robots, uint RobotCount, uint width, uint height)		
{
	for (int i = 0; i < RobotCount; i++)
	{
		if (canItMove(robot + i))
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

			else if (getRobotAngle(robots + i) > 180 && getRobotAngle(robots + i) < 270)
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

		else
		{
			(robot + i)->angle = srand(time(NULL));

		}
	}
	return;
}
bool canItMove(robotType* robot)	//Esta funcion recibe un puntero a un robot y determina si se podra mover o no.
									//Devuelve True de ser asi, y False en caso contrario
{
	bool ret;
	double x_, y_;
	x_ = robot->x;
	y_ = robot->y;
	if (getRobotAngle(robot + i) < 90)
		{
			if ((x_+= sin((robot)->angle)< width_) &&
				(x_ += sin((robot)->angle) > 0)	&&
				(y_ += cos((robot)->angle))< height_)	&&
				(y_ += cos((robot)->angle)) > 0))
			{
				ret = TRUE;
			}
			else
			{
				ret = FALSE;
			}
		}

	else if (getRobotAngle(robot) > 90 && getRobotAngle(robot) < 180)
	{
		if ((x_ += cos((robot)->angle - 90.0) < width_) &&
			(x_ += cos((robot)->angle - 90.0) > 0) &&
			(y_ -= sin((robot)->angle - 90.0)) < height_) &&
			(y_ -= sin((robot)->angle - 90.0)) > 0))
				{
				ret = TRUE;
				}
		else
		{
			ret = FALSE;
		}
	}

	else if (getRobotAngle (robot) > 180 && getRobotAngle(robot) < 270)
	{
		if ((x_ -= sin((robot)->angle - 180.0) < width_) &&
			(x_ -= sin((robot)->angle - 180.0) > 0) &&
			(y_ -= cos((robot)->angle - 180.0)) < height_) &&
			(y_ -= cos((robot)->angle - 180.0)) > 0))
		{
			ret = TRUE;
		}
		else
		{
			ret = FALSE;
		}
	}
	
	else if (getRobotAngle(robot) > 270 && getRobotAngle(robot) < 360)
	{
		if ((x_ -= cos((robot)->angle - 270.0) < width_) &&
			(x_ -= cos((robot)->angle - 270.0) > 0) &&
			(y_ += sin((robot)->angle - 270.0)) < height_) &&
			(y_ += sin((robot)->angle - 270.0)) > 0))
|		{
			ret = TRUE;
		}
		else
		{
			ret = FALSE;
		}
	}
	return ret;
}

