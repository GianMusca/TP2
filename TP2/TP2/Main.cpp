#include <stdio.h>
#include <stdlib.h>
#include "parseCmdLine.h"
#include "parseCallback.h"
#include "Simulation.h"


int main(int argc, char* argv[])
{
	simulationType data;
	parseCmdLine(argc, argv, parseCallback, &data);

	if (simDataIsValid(&data))
	{
		//Modo 1
		if (data.mode == MODE1)
		{
			simulationType *sim = createSim(data.robots, data.width, data.height);
			if (sim == NULL)
			{
				return ERR;
			}

			while (isSimOver(sim))
			{
				simulationStep(sim);
				//front-end
				_sleep(TICK);
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