#include <stdio.h>
#include "Simulation.h"
#include "Piso.h"


simulationType* createSim(uint robotCount, uint width, uint height)
{
	simulationType sim;

	sim.floor = createFloor(width, height);
	if (sim.floor == NULL)
	{
		return NULL
	}

	sim.robots = createRobots(RobotCount);
	if (sim.robots == NULL)
	{
		return NULL;
	}

	return &sim;
}

void destroySim(simulationType* sim)
{
	destroyFloor(sim->floor);
	destroyRobots(sim->robots);
}


bool isSimOver(simulationType* sim)
{
	return isFloorClean(sim->floor, sim->width, sim->height);
}