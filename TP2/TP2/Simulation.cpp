#include <stdio.h>
#include "Simulation.h"


simulationType* createSim(simulationType* sim)
{
	sim->floor = createFloor(sim->width, sim->height);

	if (sim->floor == NULL)
	{
		return NULL;
	}

	sim->robots = createRobots(sim->robotCount, sim->width, sim->height);

	if (sim->robots == NULL)
	{
		return NULL;
	}

	return sim;
}


simulationType* simulationStep(simulationType* sim)
{
	for (uint i = 0; i < sim->robotCount; i++)
	{
		cleanTile(sim->floor, (uint)(((sim->robots) + i)->x), (uint)(((sim->robots) + i)->y), sim->width);		// Limpia todas las casillas en las que hayan robots.																					// para ello se llama multiples veces a la funcion cleanTile.
	}

	moveRobot(sim->robots, sim->robotCount, sim->width, sim->height);		// Mueve todos los robots con un llamado

	(sim->tickCount)++;

	return sim;
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


uint getSimTicks(simulationType* sim)
{
	return (sim->tickCount);
}