
typedef struct
{
	double angle;
	double x;
	double y;

} robotType;

robotType* createRobots(uint RobotCount, uint width, uint height); //NULL if error
void moveRobot(robotType* Robots, uint RobotCount, uint width, uint height);
void destroyRobots(robotType* robots);

double getRobotAngle(robotType*);
double getRobotX(robotType*);
double getRobotY(robotType*);