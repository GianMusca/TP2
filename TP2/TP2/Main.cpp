#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "parseCmdLine.h"
#include "parseCallback.h"
#include "Simulation.h"
#include "Visual.h"

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>		//No olvides instalar allegro

#define YES 1
#define NO 0
#define ERR -1
#define TICK 50


bool simDataIsValid(simulationType* data);


int main(int argc, char* argv[])
{
	simulationType data = { NULL,NULL,1,10,10,0,MODE1 };
	//simulationType data;
	//int syntaxOk = parseCmdLine(argc, argv, parseCallback, &data);

	if (simDataIsValid(&data) /*&& !(syntaxOk == ERR)*/)
	{
		//Modo 1
		if (data.modo == MODE1)
		{
			simulationType* sim = createSim(&data);
			if (sim == NULL)
			{
				return ERR;
			}

			ALLEGRO_DISPLAY* display = createDisplay(sim->floor, sim->robots, sim->robotCount, sim->width, sim->height);

			while (!isSimOver(sim))
			{
				simulationStep(sim);
				
				drawFloor(sim->floor, sim->robots, sim->robotCount, sim->width, sim->height, display);  //front-end

				Sleep(TICK);
			}
		//delete display
			printf("\nPiso limpio\n");
			destroySim(sim);
		}

		//Modo 2
		else
		{
			double histogram[100] = { 0.0 };
			int robotCount = 1;

			do
			{
				for (int simNum = 0; simNum < 1000; simNum++)
				{
					simulationType* sim = createSim(&data);
					while (!isSimOver(simulationStep(sim)))
					{
						//sigue limpiando
						//(...)
					}
					histogram[robotCount - 1] += getSimTicks(sim) / 1000.0;
					destroySim(sim);
					//front-end
				}

				robotCount++;

			} while ((histogram[robotCount - 1] - histogram[robotCount]) > 0.1);

		}

	}
}


bool simDataIsValid(simulationType* data)
{
	bool ret = YES;

	if (data == NULL)
	{
		ret = NO;
	}

	return ret;
}