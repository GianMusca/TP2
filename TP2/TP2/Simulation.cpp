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

bool simulationStep(simulationType* sim)
{
	moveRobot(sim->robots, sim->robotCount, sim->width, sim->height);		// Mueve todos los robots con un llamado
	for (int i = 0; i < sim->robotCount; i++)
	{
		cleanTile(sim->floor, sim->(robots+i)->x, sim->(robots+i)->y, sim->width);		// Limpia todas las casillas en las que haytan robots.
																						// para ello se llama multiples veces a la funcion cleanTile.
	}
}