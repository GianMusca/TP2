#ifndef SIMULATION_H
#define SIMULATION_H

typedef enum { MODE1, MODE2 } ModeType;
typedef unsigned int uint;
typedef struct
{
	robotType* robots;
	tileType* floor;
	uint robotCount;
	uint width;
	uint heigth;
	uint tickCount;
	modeType modo;

} simulationType;

simulationType* createSim(uint robotCount, uint width, uint height);
void destroySim(simulationType* sim);
bool simulationStep(simulationType* sim);
uint getSimTicks(simulationType* sim);
bool isSimOver(simulationType* sim);

#endif