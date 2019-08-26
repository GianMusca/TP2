#ifndef SIMULATION_H
#define SIMULATION_H

#include "Robots.h"
#include "Piso.h"

typedef enum { MODE1, MODE2 } modeType;

typedef struct
{
	robotType* robots;
	tileType* floor;
	uint robotCount;
	uint width;
	uint height;
	uint tickCount;
	modeType modo;

} simulationType;

simulationType* createSim(uint robotCount, uint width, uint height);
void destroySim(simulationType* sim);
simulationType* simulationStep(simulationType* sim);
uint getSimTicks(simulationType* sim);
bool isSimOver(simulationType* sim);

#endif