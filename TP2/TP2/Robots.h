#ifndef ROBOTS_H
#define ROBOTS_H

typedef struct
{
	double angle;
	double x;
	double y;

} robotType;			//Estructura Robots.

typedef unsigned int uint;

robotType* createRobots(uint RobotCount, uint width, uint height); //NULL if error
void moveRobot(robotType* Robots, uint RobotCount, uint width, uint height);
void destroyRobots(robotType* robots);

#endif