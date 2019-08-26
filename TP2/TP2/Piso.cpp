#include <stdio.h>
#include <stdlib.h>
#include "Piso.h"

#define YES 1
#define NO 0


tileType* createFloor(uint width, uint height)
{
	tileType* floor;
	floor = (tileType*) malloc(width * height * sizeof(tileType));
	
	if (floor == NULL)
	{
		return NULL;
	}

	for (uint tile = 0; tile < width * height; tile++)
	{
		floor[tile] = SUCIO;
	}

	return floor;
}


bool isFloorClean(tileType* floor, uint width, uint height)
{
	int state = YES;

	for (uint tile = 0; tile < width * height; tile++)
	{
		if (floor[tile] == SUCIO)
		{
			state = NO;
			break;
		}

	}

	return state;
}


void cleanTile(tileType* floor, uint x, uint y, uint width)
{
	floor[x * width + y] = LIMPIO;
}


void destroyFloor(tileType* floor)
{
	free(floor);
}
