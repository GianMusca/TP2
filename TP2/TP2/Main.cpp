#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "parseCmdLine.h"
#include "parseCallback.h"
#include "Simulation.h"

#define YES 1
#define NO 0
#define ERR -1
#define TICK 50


bool simDataIsValid(simulationType* data);


int main(int argc, char* argv[])
{
	simulationType data;
	int syntaxOk = parseCmdLine(argc, argv, parseCallback, &data);

	if (simDataIsValid(&data) && !(syntaxOk == ERR))
	{
		//Modo 1
		if (data.modo == MODE1)
		{
			simulationType* sim = createSim(&data);
			if (sim == NULL)
			{
				return ERR;
			}

			while (!isSimOver(sim))
			{
				simulationStep(sim);
				//front-end
				Sleep(TICK);
			}

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
				printf("\nRobots = %d\n", robotCount);
				robotCount++;

			} while ((histogram[robotCount - 1] - histogram[robotCount]) > 0.1);

			printf("\nRobots = %d\n", robotCount);

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