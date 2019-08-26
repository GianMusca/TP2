#include <stdio.h>
#include <stdlib.h>
#include <synchapi.h>
#include "parseCmdLine.h"
#include "parseCallback.h"
#include "Simulation.h"

#define YES 1
#define NO 0
#define ERR -1
#define TICK 0


bool simDataIsValid(simulationType* data);


int main(int argc, char* argv[])
{
	simulationType data;
	parseCmdLine(argc, argv, parseCallback, &data);

	if (simDataIsValid(&data))
	{
		//Modo 1
		if (data.modo == MODE1)
		{
			simulationType* sim = createSim(data.robotCount, data.width, data.height);
			if (sim == NULL)
			{
				return ERR;
			}

			while (isSimOver(sim))
			{
				simulationStep(sim);
				//front-end
				Sleep(TICK);
			}

			destroySim(sim);
		}

		//Modo 2
		else
		{
			double histogram[10000] = { 0.0 };
			int robotCount = 1;

			do
			{
				for (int simNum = 0; simNum < 1000; simNum++)
				{
					simulationType* sim = createSim(robotCount, data.width, data.height);
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