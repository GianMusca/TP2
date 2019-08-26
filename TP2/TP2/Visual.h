#ifndef VISUAL_H
#define VISUAL_H

#include "Simulation.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>		//No olvides instalar allegro 


int drawFloor(tileType* floor, robotType* robots, uint robotCount, uint width, uint height, ALLEGRO_DISPLAY* display);
ALLEGRO_DISPLAY* createDisplay(tileType* floor, robotType* robots, uint robotCount, uint width, uint height);

#endif
